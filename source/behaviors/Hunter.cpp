
#include "Hunter.hpp"

#include "Isomot.hpp"
#include "Item.hpp"
#include "DescriptionOfItem.hpp"
#include "ItemDescriptions.hpp"
#include "FreeItem.hpp"
#include "AvatarItem.hpp"
#include "Moving.hpp"
#include "Displacing.hpp"
#include "Falling.hpp"
#include "Mediator.hpp"
#include "Room.hpp"
#include "SoundManager.hpp"
#include "GameManager.hpp"


namespace behaviors
{

Hunter::Hunter( const ItemPtr & item, const std::string & behavior )
        : Behavior( item, behavior )
        , speedTimer( new Timer() )
{
        speedTimer->go ();
}

Hunter::~Hunter()
{
}

bool Hunter::update ()
{
        Mediator* mediator = this->item->getMediator();
        AvatarItemPtr characterToHunt = mediator->getActiveCharacter();

        bool alive = true;

        switch ( activity )
        {
                case activities::Activity::Wait:
                        // if the hunter is not a waiting one, activate it just now
                        if ( getNameOfBehavior() == "behavior of hunter in four directions" ||
                                        getNameOfBehavior() == "behavior of hunter in eight directions" )
                        {
                                SoundManager::getInstance().play( this->item->getLabel(), activity );
                                activity = updateDirection( activity );
                        }
                        // otherwise check if the character is within the defined rectangle near the hunter
                        else
                        {
                                const unsigned int sizeOfRectangleInTiles = 3 ;
                                const int coverage = mediator->getRoom()->getSizeOfOneTile() * sizeOfRectangleInTiles ;

                                if ( characterToHunt != nilPointer  &&
                                        characterToHunt->getX() > this->item->getX() - coverage  &&
                                        characterToHunt->getX() < this->item->getX() + static_cast< int >( this->item->getWidthX() ) + coverage  &&
                                        characterToHunt->getY() > this->item->getY() - coverage  &&
                                        characterToHunt->getY() < this->item->getY() + static_cast< int >( this->item->getWidthY() ) + coverage )
                                {
                                        activity = updateDirection( activity );
                                }

                                // eight-directional waiting hunter emits sound when it waits
                                if ( getNameOfBehavior() == "behavior of waiting hunter in eight directions" )
                                {
                                        SoundManager::getInstance().play( this->item->getLabel(), activity );
                                }

                                // animate item, and when it waits too
                                this->item->animate();
                        }
                break;

                case activities::Activity::MoveNorth:
                case activities::Activity::MoveSouth:
                case activities::Activity::MoveEast:
                case activities::Activity::MoveWest:
                        // bin original item when full-bodied guard is created
                        if ( getNameOfBehavior() == "behavior of waiting hunter in four directions" && createFullBody () )
                        {
                                alive = false;
                        }
                        else if ( ! dynamic_cast< FreeItem& >( * this->item ).isFrozen() )
                        {
                                if ( speedTimer->getValue() > this->item->getSpeed() )
                                {
                                        // move item
                                        activities::Moving::getInstance().move( this, &activity, false );

                                        // reset timer to next cycle
                                        speedTimer->reset();

                                        // see if direction changes
                                        activity = updateDirection( activity );

                                        // fall if you have to
                                        if ( this->item->getWeight() > 0 )
                                        {
                                                activities::Falling::getInstance().fall( this );
                                        }
                                }

                                this->item->animate();

                                // play sound of movement
                                SoundManager::getInstance().play( this->item->getLabel(), activity );
                        }
                        break;

                case activities::Activity::MoveNortheast:
                case activities::Activity::MoveNorthwest:
                case activities::Activity::MoveSoutheast:
                case activities::Activity::MoveSouthwest:
                        if ( ! dynamic_cast< FreeItem& >( * this->item ).isFrozen() )
                        {
                                if ( speedTimer->getValue() > this->item->getSpeed() )
                                {
                                        // move item
                                        if ( ! activities::Moving::getInstance().move( this, &activity, false ) )
                                        {
                                                if ( activity == activities::Activity::MoveNortheast || activity == activities::Activity::MoveNorthwest )
                                                {
                                                        ActivityOfItem tempActivity = activities::Activity::MoveNorth;
                                                        if ( ! activities::Moving::getInstance().move( this, &tempActivity, false ) )
                                                        {
                                                                activity = ( activity == activities::Activity::MoveNortheast ? activities::Activity::MoveEast : activities::Activity::MoveWest );
                                                                if ( this->item->getWeight() > 0 )
                                                                {
                                                                        activities::Falling::getInstance().fall( this );
                                                                }
                                                        }
                                                }
                                                else
                                                {
                                                        ActivityOfItem tempActivity = activities::Activity::MoveSouth;
                                                        if ( ! activities::Moving::getInstance().move( this, &tempActivity, false ) )
                                                        {
                                                                activity = ( activity == activities::Activity::MoveSoutheast ? activities::Activity::MoveEast : activities::Activity::MoveWest );
                                                                if ( this->item->getWeight() > 0 )
                                                                {
                                                                        activities::Falling::getInstance().fall( this );
                                                                }
                                                        }
                                                }
                                        }
                                        else
                                        {
                                                // see if direction changes
                                                activity = updateDirection( activity );
                                        }

                                        // reset timer to next cycle
                                        speedTimer->reset();
                                }

                                this->item->animate();

                                // play sound of movement
                                SoundManager::getInstance().play( this->item->getLabel(), activity );
                        }
                        break;

                case activities::Activity::DisplaceNorth:
                case activities::Activity::DisplaceSouth:
                case activities::Activity::DisplaceEast:
                case activities::Activity::DisplaceWest:
                case activities::Activity::DisplaceNortheast:
                case activities::Activity::DisplaceNorthwest:
                case activities::Activity::DisplaceSoutheast:
                case activities::Activity::DisplaceSouthwest:
                        // when item is active and it’s time to move
                        if ( speedTimer->getValue() > this->item->getSpeed() )
                        {
                                activities::Displacing::getInstance().displace( this, &activity, false );
                                activity = activities::Activity::Wait;
                                speedTimer->reset();
                        }

                        // preserve inactivity for frozen item
                        if ( dynamic_cast< FreeItem& >( * this->item ).isFrozen() )
                        {
                                activity = activities::Activity::Freeze;
                        }
                        break;

                case activities::Activity::Freeze:
                        dynamic_cast< FreeItem& >( * this->item ).setFrozen( true );
                        break;

                case activities::Activity::WakeUp:
                        dynamic_cast< FreeItem& >( * this->item ).setFrozen( false );
                        activity = activities::Activity::Wait;
                        break;

                default:
                        ;
        }

        return ! alive;
}

ActivityOfItem Hunter::updateDirection( const ActivityOfItem & activity )
{
        if ( getNameOfBehavior() == "behavior of hunter in four directions" ||
                        getNameOfBehavior() == "behavior of waiting hunter in four directions" )
        {
                return updateDirection4( activity );
        }
        else if ( getNameOfBehavior() == "behavior of hunter in eight directions" ||
                        getNameOfBehavior() == "behavior of waiting hunter in eight directions" )
        {
                return updateDirection8( activity );
        }

        return activities::Activity::Wait;
}

ActivityOfItem Hunter::updateDirection4( const ActivityOfItem & activity )
{
        AvatarItemPtr characterToHunt = this->item->getMediator()->getActiveCharacter();

        if ( characterToHunt != nilPointer ) // if there’s the active character in the room
        {
                int dx = this->item->getX() - characterToHunt->getX();
                int dy = this->item->getY() - characterToHunt->getY();

                if ( abs( dy ) > abs( dx ) )
                {
                        if ( dx > 0 )
                        {
                                changeActivityOfItem( activities::Activity::MoveNorth );
                        }
                        else if ( dx < 0 )
                        {
                                changeActivityOfItem( activities::Activity::MoveSouth );
                        }
                        else
                        {
                                if ( dy > 0 )
                                        changeActivityOfItem( activities::Activity::MoveEast );
                                else if ( dy < 0 )
                                        changeActivityOfItem( activities::Activity::MoveWest );
                        }
                }
                else if ( abs( dy ) < abs( dx ) )
                {
                        if ( dy > 0 )
                        {
                                changeActivityOfItem( activities::Activity::MoveEast );
                        }
                        else if ( dy < 0 )
                        {
                                changeActivityOfItem( activities::Activity::MoveWest );
                        }
                        else
                        {
                                if ( dx > 0 )
                                        changeActivityOfItem( activities::Activity::MoveNorth );
                                else if ( dx < 0 )
                                        changeActivityOfItem( activities::Activity::MoveSouth );
                        }
                }
        }

        return activity;
}

ActivityOfItem Hunter::updateDirection8( const ActivityOfItem& activity )
{
        AvatarItemPtr characterToHunt = this->item->getMediator()->getActiveCharacter();

        if ( characterToHunt != nilPointer ) // if there’s the active character in the room
        {
                int dx = this->item->getX() - characterToHunt->getX();
                int dy = this->item->getY() - characterToHunt->getY();

                // change the direction to reach the character as quick as possible
                // look for the distances on X and Y between the hunter and the character

                if ( abs( dy ) > abs( dx ) )
                {
                        if ( dx > 1 )
                        {
                                if ( dy > 1 )
                                        changeActivityOfItem( activities::Activity::MoveNortheast );
                                else if ( dy < -1 )
                                        changeActivityOfItem( activities::Activity::MoveNorthwest );
                                else
                                        changeActivityOfItem( activities::Activity::MoveNorth );
                        }
                        else if ( dx < -1 )
                        {
                                if ( dy > 1 )
                                        changeActivityOfItem( activities::Activity::MoveSoutheast );
                                else if ( dy < -1 )
                                        changeActivityOfItem( activities::Activity::MoveSouthwest );
                                else
                                        changeActivityOfItem( activities::Activity::MoveSouth );
                        }
                        else
                        {
                                if ( dy > 0 )
                                        changeActivityOfItem( activities::Activity::MoveEast );
                                else if ( dy < 0 )
                                        changeActivityOfItem( activities::Activity::MoveWest );
                        }
                }
                else if ( abs( dy ) < abs( dx ) )
                {
                        if ( dy > 1 )
                        {
                                if ( dx > 1 )
                                        changeActivityOfItem( activities::Activity::MoveNortheast );
                                else if ( dx < -1 )
                                        changeActivityOfItem( activities::Activity::MoveSoutheast );
                                else
                                        changeActivityOfItem( activities::Activity::MoveEast );
                        }
                        else if ( dy < -1 )
                        {
                                if ( dx > 1 )
                                        changeActivityOfItem( activities::Activity::MoveNorthwest );
                                else if ( dx < -1 )
                                        changeActivityOfItem( activities::Activity::MoveSouthwest );
                                else
                                        changeActivityOfItem( activities::Activity::MoveWest );
                        }
                        else
                        {
                                if ( dx > 0 )
                                        changeActivityOfItem( activities::Activity::MoveNorth );
                                else if ( dx < 0 )
                                        changeActivityOfItem( activities::Activity::MoveSouth );
                        }
                }

                // the guardian of throne flees from the player with four crowns
                if ( item->getLabel() == "throne-guard" && GameManager::getInstance().countFreePlanets() >= 4 )
                {
                        changeActivityOfItem( activities::Activity::MoveSouthwest );
                }
        }

        return activity;
}

bool Hunter::createFullBody()
{
        FreeItem& thisItem = dynamic_cast< FreeItem& >( * this->item );
        bool created = false;

        if ( thisItem.getLabel() == "imperial-guard-head" && thisItem.canAdvanceTo( 0, 0, - Isomot::LayerHeight ) )
        {
                created = true;

                // create the new item at the same location
                FreeItemPtr newItem( new FreeItem (
                        ItemDescriptions::descriptions().getDescriptionByLabel( "imperial-guard" ),
                        thisItem.getX(), thisItem.getY(), thisItem.getZ() - Isomot::LayerHeight,
                        thisItem.getOrientation() ) );

                newItem->setBehaviorOf( "behavior of hunter in four directions" );

                // switch off collisions for this item
                // otherwise it would be impossible to create a full-bodied guard
                thisItem.setIgnoreCollisions( true );

                thisItem.getMediator()->getRoom()->addFreeItem( newItem );
        }

        return created;
}

}
