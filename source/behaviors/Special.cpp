
#include "Special.hpp"

#include "FreeItem.hpp"
#include "Displacing.hpp"
#include "Falling.hpp"
#include "Room.hpp"
#include "Mediator.hpp"
#include "BonusManager.hpp"
#include "SoundManager.hpp"


namespace behaviors
{

Special::Special( const ItemPtr & item, const std::string & behavior )
        : Behavior( item, behavior )
        , disappearanceTimer( new Timer() )
        , speedTimer( new Timer() )
        , fallTimer( new Timer() )
{
        disappearanceTimer->go();
        speedTimer->go();
        fallTimer->go();
}

bool Special::update ()
{
        bool isGone = false ;

        Mediator* mediator = item->getMediator();

        switch ( activity )
        {
                case activities::Activity::Wait:
                        // is there an item above this one
                        if ( ! item->canAdvanceTo( 0, 0, 1 ) )
                        {
                                ItemPtr itemAbove = mediator->findCollisionPop( );

                                // is that above item the character which may take this bonus
                                if ( itemAbove != nilPointer
                                        && itemAbove->whichKindOfItem() == "avatar item"
                                                && mayTake( itemAbove->getOriginalLabel() ) )
                                {
                                        activity = activities::Activity::Vanish ;
                                        this->sender = itemAbove ; // the character is yet the sender

                                        disappearanceTimer->reset();
                                }
                        }

                        item->animate();

                        // fall if it’s not taken
                        if ( activity != activities::Activity::Vanish )
                        {
                                activity = activities::Activity::Fall;
                        }
                        break;

                case activities::Activity::DisplaceNorth:
                case activities::Activity::DisplaceSouth:
                case activities::Activity::DisplaceEast:
                case activities::Activity::DisplaceWest:
                case activities::Activity::DisplaceNortheast:
                case activities::Activity::DisplaceSoutheast:
                case activities::Activity::DisplaceSouthwest:
                case activities::Activity::DisplaceNorthwest:
                case activities::Activity::DisplaceUp:
                        // if the character touches the bonus item and may take this bonus
                        if ( sender->whichKindOfItem() == "avatar item" && mayTake( sender->getOriginalLabel() ) )
                        {
                                activity = activities::Activity::Vanish;
                        }
                        // otherwise it's some other item which moves the bonus
                        else if ( speedTimer->getValue() > item->getSpeed() )
                        {
                                activities::Displacing::getInstance().displace( this, &activity, true );

                                // after displaced, back to falling
                                activity = activities::Activity::Fall;

                                speedTimer->reset();
                        }
                        break;

                case activities::Activity::ForceDisplaceNorth:
                case activities::Activity::ForceDisplaceSouth:
                case activities::Activity::ForceDisplaceEast:
                case activities::Activity::ForceDisplaceWest:
                        // the bonus item is on a conveyor
                        if ( speedTimer->getValue() > item->getSpeed() )
                        {
                                activities::Displacing::getInstance().displace( this, &activity, true );

                                // after displaced, back to falling
                                activity = activities::Activity::Fall;

                                speedTimer->reset();
                        }
                        break;

                case activities::Activity::Fall:
                        // is it fall in room without floor
                        if ( item->getZ() == 0 && ! item->getMediator()->getRoom()->hasFloor() )
                        {
                                isGone = true;
                        }
                        // is it time to fall
                        else if ( fallTimer->getValue() > item->getWeight() )
                        {
                                if ( ! activities::Falling::getInstance().fall( this ) )
                                {
                                        activity = activities::Activity::Wait;
                                }

                                fallTimer->reset();

                                // look if the bonus falls on the character
                                if ( ! item->canAdvanceTo( 0, 0, -1 ) )
                                {
                                        ItemPtr itemBelow = mediator->findCollisionPop( );

                                        // is that below item the character which may take this bonus
                                        if ( itemBelow != nilPointer && itemBelow->whichKindOfItem() == "avatar item" && mayTake( itemBelow->getOriginalLabel() ) )
                                        {
                                                // get collisions of the avatar item with the items above it
                                                itemBelow->canAdvanceTo( 0, 0, 1 );

                                                // if that avatar item is just below the bonus then it’s okay to take it
                                                bool takeIt = ( mediator->depthOfStackOfCollisions() <= 1 );

                                                // disappear on take
                                                if ( takeIt )
                                                {
                                                        activity = activities::Activity::Vanish ;
                                                        this->sender = itemBelow; // the character is yet the sender

                                                        disappearanceTimer->reset();
                                                }
                                        }
                                }
                        }
                        break;

                case activities::Activity::Vanish:
                        if ( disappearanceTimer->getValue() > 0.100 )
                        {
                                isGone = true ;

                                // play sound of taking
                                SoundManager::getInstance().play( item->getLabel(), activity );

                                // a bonus item disappears from room once it's taken
                                BonusManager::getInstance().markAsAbsent(
                                        BonusInRoom(
                                                item->getLabel(),
                                                item->getMediator()->getRoom()->getNameOfRoomDescriptionFile()
                                        ) );

                                takeMagicItem( dynamic_cast< AvatarItem & >( *sender ) );

                                if ( item->getOriginalLabel() != "crown" ) // no bubbles for crowns
                                {
                                        item->setIgnoreCollisions( true );

                                        item->setHeight( 0 );
                                        item->metamorphInto( "bubbles", "vanishing bonus item" );
                                        item->setBehaviorOf( "behavior of disappearance in time" );

                                        isGone = false ;
                                }
                        }
                        break;

                default:
                        ;
        }

        return isGone;
}

bool Special::mayTake( const std::string& character )
{
        std::string magicItem = this->item->getOriginalLabel();

        if ( magicItem == "extra-life" || magicItem == "shield" ||
                magicItem == "reincarnation-fish" || magicItem == "crown" )
        {
                return true ;
        }

        return  ( character == "head"     &&  ( magicItem == "quick-steps" ||
                                                magicItem == "horn" ||
                                                magicItem == "donuts" ) )
                ||

                ( character == "heels"    &&  ( magicItem == "high-jumps" ||
                                                magicItem == "handbag" ) )
                ||

                ( character == "headoverheels" && ( magicItem == "handbag" ||
                                                magicItem == "horn" ||
                                                magicItem == "donuts" ) ) ;
}

void Special::takeMagicItem( AvatarItem & whoTakes )
{
        std::string magicItem = this->item->getOriginalLabel () ;

        if ( magicItem == "donuts" )
        {
                const unsigned short DonutsPerBox = 6 ;
                whoTakes.addDonuts( DonutsPerBox );
        }
        else if ( magicItem == "extra-life" )
        {
                whoTakes.addLives( 2 );
        }
        else if ( magicItem == "quick-steps" )
        {
                whoTakes.activateBonusQuickSteps () ;
        }
        else if ( magicItem == "high-jumps" )
        {
                whoTakes.addBonusHighJumps( 10 );
        }
        else if ( magicItem == "shield" )
        {
                whoTakes.activateShield () ;
        }
        else if ( magicItem == "crown" )
        {
                whoTakes.liberatePlanet () ;
        }
        else if ( magicItem == "horn" || magicItem == "handbag" )
        {
                whoTakes.takeMagicTool( magicItem );
        }
        else if ( magicItem == "reincarnation-fish" )
        {
                whoTakes.saveAt( this->item->getX (), this->item->getY (), this->item->getZ () );
        }
}

}
