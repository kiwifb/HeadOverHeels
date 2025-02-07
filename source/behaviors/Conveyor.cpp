
#include "Conveyor.hpp"

#include "Item.hpp"
#include "FreeItem.hpp"
#include "AvatarItem.hpp"
#include "Displacing.hpp"
#include "Falling.hpp"
#include "Mediator.hpp"
#include "SoundManager.hpp"


namespace behaviors
{

Conveyor::Conveyor( const ItemPtr & item, const std::string & behavior )
        : Behavior( item, behavior )
        , speedTimer( new Timer() )
        , animationTimer( new Timer() )
{
        speedTimer->go();
        animationTimer->go();
}

Conveyor::~Conveyor( )
{
}

bool Conveyor::update ()
{
        Mediator* mediator = item->getMediator();

        switch ( activity )
        {
                case activities::Activity::Wait:
                        if ( speedTimer->getValue() > item->getSpeed() )
                        {
                                if ( ! item->canAdvanceTo( 0, 0, 1 ) )
                                {
                                        std::stack< std::string > topItems;
                                        while ( ! mediator->isStackOfCollisionsEmpty() )
                                        {
                                                topItems.push( mediator->popCollision() );
                                        }

                                        // check conditions as long as there are items on top
                                        while ( ! topItems.empty () )
                                        {
                                                ItemPtr collision = mediator->findItemByUniqueName( topItems.top() );
                                                topItems.pop();

                                                // is it free item
                                                if ( collision != nilPointer &&
                                                        ( collision->whichKindOfItem() == "free item" || collision->whichKindOfItem() == "avatar item" ) )
                                                {
                                                        FreeItem& itemAbove = dynamic_cast< FreeItem & >( *collision );

                                                        // is it item with behavior
                                                        if ( itemAbove.getBehavior() != nilPointer )
                                                        {
                                                                if ( ! itemAbove.getAnchor().empty() || this->item->getUniqueName() == itemAbove.getAnchor() )
                                                                {
                                                                        ActivityOfItem activityOfItemAbove = itemAbove.getBehavior()->getActivityOfItem() ;
                                                                        bool outOfGravity = ( activityOfItemAbove == activities::Activity::RegularJump
                                                                                               || activityOfItemAbove == activities::Activity::HighJump
                                                                                                  || activityOfItemAbove == activities::Activity::Vanish ) ;

                                                                        if ( ! outOfGravity ) {
                                                                                if ( item->getOrientation() == "south" )
                                                                                        itemAbove.getBehavior()->changeActivityOfItem( activities::Activity::ForceDisplaceSouth );
                                                                                else if ( item->getOrientation() == "west" )
                                                                                        itemAbove.getBehavior()->changeActivityOfItem( activities::Activity::ForceDisplaceWest );
                                                                                else if ( item->getOrientation() == "north" )
                                                                                        itemAbove.getBehavior()->changeActivityOfItem( activities::Activity::ForceDisplaceNorth );
                                                                                else if ( item->getOrientation() == "east" )
                                                                                        itemAbove.getBehavior()->changeActivityOfItem( activities::Activity::ForceDisplaceEast );
                                                                        }

                                                                        // play the sound of conveyor
                                                                        SoundManager::getInstance().play( item->getLabel(), activities::Activity::IsActive );
                                                                }
                                                        }
                                                }
                                        }
                                }

                                speedTimer->reset();
                        }

                        if ( animationTimer->getValue() > 2 * item->getSpeed() )
                        {
                                item->animate ();
                                animationTimer->reset();
                        }

                        break;

                default:
                        activity = activities::Activity::Wait;
        }

        return false;
}

}
