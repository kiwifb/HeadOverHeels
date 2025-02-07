
#include "AvatarItem.hpp"

#include "Behavior.hpp"
#include "Door.hpp"
#include "Mediator.hpp"
#include "Room.hpp"
#include "GameManager.hpp"
#include "GameInfo.hpp"
#include "PlayerControlled.hpp"
#include "ItemDescriptions.hpp"

#include <algorithm> // std::find


AvatarItem::AvatarItem( const DescriptionOfItem* description, int x, int y, int z, const std::string& way )
        : FreeItem( description, x, y, z, way )
        , wayOfExit( "did not quit" )
        , wayOfEntry( "just wait" )
        , shieldTimer( new Timer () )
        , descriptionOfTakenItem( nilPointer )
{
}

AvatarItem::AvatarItem( const AvatarItem & toCopy )
        : FreeItem( toCopy )
        , wayOfExit( toCopy.wayOfExit )
        , wayOfEntry( toCopy.wayOfEntry )
        , shieldTimer( new Timer () )
        , descriptionOfTakenItem( nilPointer )
{
}

void AvatarItem::setWayOfExit ( const std::string& way )
{
        this->wayOfExit = way;

        switch ( Way( way ).getIntegerOfWay () )
        {
                case Way::North:
                case Way::South:
                case Way::East:
                case Way::West:
                        setOrientation( way );
                        break;

                case Way::Northeast:
                case Way::Northwest:
                        setOrientation( "north" );
                        break;

                case Way::Southeast:
                case Way::Southwest:
                        setOrientation( "south" );
                        break;

                case Way::Eastnorth:
                case Way::Eastsouth:
                        setOrientation( "east" );
                        break;

                case Way::Westnorth:
                case Way::Westsouth:
                        setOrientation( "west" );
                        break;

                default:
                        ;
        }
}

void AvatarItem::autoMoveOnEntry ( const std::string& wayOfEntry )
{
        setWayOfEntry( wayOfEntry );

        if ( getBehavior() == nilPointer )
        {
                std::cerr << "nil behavior at AvatarItem::autoMoveOnEntry" << std::endl ;
                return;
        }

        switch ( Way( wayOfEntry ).getIntegerOfWay () )
        {
                case Way::North:
                case Way::Northeast:
                case Way::Northwest:
                        getBehavior()->changeActivityOfItem( activities::Activity::AutoMoveSouth );
                        break;

                case Way::South:
                case Way::Southeast:
                case Way::Southwest:
                        getBehavior()->changeActivityOfItem( activities::Activity::AutoMoveNorth );
                        break;

                case Way::East:
                case Way::Eastnorth:
                case Way::Eastsouth:
                        getBehavior()->changeActivityOfItem( activities::Activity::AutoMoveWest );
                        break;

                case Way::West:
                case Way::Westnorth:
                case Way::Westsouth:
                        getBehavior()->changeActivityOfItem( activities::Activity::AutoMoveEast );
                        break;

                case Way::ByTeleport:
                case Way::ByTeleportToo:
                        getBehavior()->changeActivityOfItem( activities::Activity::BeginWayInTeletransport );
                        break;

                case Way::Above:
                        getBehavior()->changeActivityOfItem( activities::Activity::Fall );
                        break;

                default:
                        ;
        }
}

bool AvatarItem::addToPosition( int x, int y, int z )
{
        bool itAutomoves = getBehavior()->getActivityOfItem() == activities::Activity::AutoMoveNorth ||
                                getBehavior()->getActivityOfItem() == activities::Activity::AutoMoveSouth ||
                                getBehavior()->getActivityOfItem() == activities::Activity::AutoMoveEast ||
                                getBehavior()->getActivityOfItem() == activities::Activity::AutoMoveWest ;

        bool itFallsUnderDoor = ( x == 0 && y == 0 && z < 0 && this->isUnderSomeDoor () );

        if ( ! this->isActiveCharacter() && ! itAutomoves && ! itFallsUnderDoor )
        {
                return FreeItem::addToPosition( x, y, z );
        }

        mediator->clearStackOfCollisions( );

        int xBefore = xYet ;
        int yBefore = yYet ;
        int zBefore = zYet ;

        std::pair< int, int > offsetBefore = getOffset() ;

        xYet += x ;
        yYet += y ;
        zYet += z ;

        // look for collision with door

        bool doorCollision = false;

        bool collisionFound = mediator->lookForCollisionsOf( this->getUniqueName() );

        if ( collisionFound )
        {
                while ( ! mediator->isStackOfCollisionsEmpty () )
                {
                        std::string what = mediator->popCollision();

                        // case of move to north wall
                        if ( x < 0 )
                        {
                                // check for hit of north door’s jamb
                                doorCollision = isCollidingWithDoor( "north", what, xBefore, yBefore );
                                if ( ! doorCollision )
                                {
                                        // check for hit of northeast door’s jamb
                                        doorCollision = isCollidingWithDoor( "northeast", what, xBefore, yBefore );
                                        if ( ! doorCollision )
                                        {
                                                // then it’s hit of northwest door’s jamb
                                                doorCollision = isCollidingWithDoor( "northwest", what, xBefore, yBefore );
                                        }
                                }
                        }
                        // case of move to south wall
                        else if ( x > 0 )
                        {
                                // check for hit of south door’s jamb
                                doorCollision = isCollidingWithDoor( "south", what, xBefore, yBefore );
                                if ( ! doorCollision )
                                {
                                        // check for hit of southeast door’s jamb
                                        doorCollision = isCollidingWithDoor( "southeast", what, xBefore, yBefore );
                                        if ( ! doorCollision )
                                        {
                                                // then it’s hit of southwest door’s jamb
                                                doorCollision = isCollidingWithDoor( "southwest", what, xBefore, yBefore );
                                        }
                                }
                        }
                        // case of move to east wall
                        else if ( y < 0 )
                        {
                                doorCollision = isCollidingWithDoor( "east", what, xBefore, yBefore );
                                // check for hit of east door’s jamb
                                if ( ! doorCollision )
                                {
                                        // check for hit of east-north door’s jamb
                                        doorCollision = isCollidingWithDoor( "eastnorth", what, xBefore, yBefore );
                                        if ( ! doorCollision )
                                        {
                                                // so it’s hit of east-south door’s jamb
                                                doorCollision = isCollidingWithDoor( "eastsouth", what, xBefore, yBefore );
                                        }
                                }
                        }
                        // case of move to west wall
                        else if ( y > 0 )
                        {
                                doorCollision = isCollidingWithDoor( "west", what, xBefore, yBefore );
                                // check for hit of west door’s jamb
                                if ( ! doorCollision )
                                {
                                        // check for hit of west-north door’s jamb
                                        doorCollision = isCollidingWithDoor( "westnorth", what, xBefore, yBefore );
                                        if ( ! doorCollision )
                                        {
                                                // so it’s hit of west-south door’s jamb
                                                doorCollision = isCollidingWithDoor( "westsouth", what, xBefore, yBefore );
                                        }
                                }
                        }
                }
        }

        // look for collision with real wall, one which limits the room
        if ( this->getX() < mediator->getRoom()->getLimitAt( "north" )
                        && isNotUnderDoorAt( "north" ) && isNotUnderDoorAt( "northeast" ) && isNotUnderDoorAt( "northwest" ) )
        {
                mediator->pushCollision( "some segment of wall at north" );
        }
        else if ( this->getX() + static_cast< int >( getDescriptionOfItem()->getWidthX() ) > mediator->getRoom()->getLimitAt( "south" )
                        && isNotUnderDoorAt( "south" ) && isNotUnderDoorAt( "southeast" ) && isNotUnderDoorAt( "southwest" ) )
        {
                mediator->pushCollision( "some segment of wall at south" );
        }

        if ( this->getY() - static_cast< int >( getDescriptionOfItem()->getWidthY() ) + 1 < mediator->getRoom()->getLimitAt( "east" )
                        && isNotUnderDoorAt( "east" ) && isNotUnderDoorAt( "eastnorth" ) && isNotUnderDoorAt( "eastsouth" ) )
        {
                mediator->pushCollision( "some segment of wall at east" );
        }
        else if ( this->getY() >= mediator->getRoom()->getLimitAt( "west" )
                        && isNotUnderDoorAt( "west" ) && isNotUnderDoorAt( "westnorth" ) && isNotUnderDoorAt( "westsouth" ) )
        {
                mediator->pushCollision( "some segment of wall at west" );
        }

        collisionFound = ! mediator->isStackOfCollisionsEmpty ();
        if ( ! collisionFound )
        {
                // now it is known that the character can go thru a door
                // look for collisions with the limits of room

                const std::string doors[ 12 ] =
                        {  "northeast", "northwest", "north", "southeast", "southwest", "south",
                                "eastnorth", "eastsouth", "east", "westnorth", "westsouth", "west"  };

                // check each limit of room
                for ( unsigned int i = 0; i < 12; i++ )
                {
                        if ( isCollidingWithLimitsOfRoom( doors[ i ] ) )
                        {
                                mediator->pushCollision( doors[ i ] + " limit" );
                                break;
                        }
                }

                // collision with floor
                if ( this->getZ() < 0 )
                {
                        mediator->pushCollision( "some tile of floor" );
                }

                // collision with ceiling
                if ( z >= 0 && this->getZ() > ( Isomot::MaxLayers - 1 ) * Isomot::LayerHeight + ( Isomot::LayerHeight >> 1 ) )
                {
                        mediator->pushCollision( "ceiling" );
                }

                collisionFound = ! mediator->isStackOfCollisionsEmpty ();
                if ( ! collisionFound )
                {
                        // look for collision with the rest of items in room
                        collisionFound = mediator->lookForCollisionsOf( this->getUniqueName() );
                        if ( ! collisionFound )
                        {
                                // reshade and remask
                                freshBothProcessedImages();
                                setWantShadow( true );
                                setWantMaskTrue();

                                // update offset to point of room’s origin
                                calculateOffset ();

                                // mark to mask free items whose images overlap with character’s image
                                mediator->wantToMaskWithFreeItemAt( *this, offsetBefore );
                                mediator->wantToMaskWithFreeItem( *this );

                                // reshade items
                                mediator->wantShadowFromFreeItemAt( *this, xBefore, yBefore, zBefore );
                                mediator->wantShadowFromFreeItem( *this );

                                // mark to sort container of free items
                                mediator->markToSortFreeItems ();
                        }
                }
        }

        if ( collisionFound && ! doorCollision )
        {
                // restore previous values
                xYet = xBefore ;
                yYet = yBefore ;
                zYet = zBefore ;

                setOffset( offsetBefore );
        }

        return ! collisionFound ;
}

bool AvatarItem::isCollidingWithLimitsOfRoom( const std::string & onWhichWay )
{
        bool result = false;

        Door* door = mediator->getRoom()->getDoorAt( onWhichWay );

        switch ( Way( onWhichWay ).getIntegerOfWay () )
        {
                case Way::North:
                        result = ( this->getX() < 0 );
                        break;

                case Way::Northeast:
                case Way::Northwest:
                        result = ( door != nilPointer &&
                                        this->getX() < mediator->getRoom()->getLimitAt( onWhichWay ) &&
                                        door->isUnderDoor( this->getX(), this->getY(), this->getZ() ) );
                        break;

                case Way::South:
                        result = ( this->getX() + static_cast< int >( getDescriptionOfItem()->getWidthX() )
                                        > static_cast< int >( mediator->getRoom()->getTilesX() * mediator->getRoom()->getSizeOfOneTile() ) );
                        break;

                case Way::Southeast:
                case Way::Southwest:
                        result = ( door != nilPointer &&
                                        this->getX() + static_cast< int >( getDescriptionOfItem()->getWidthX() ) > mediator->getRoom()->getLimitAt( onWhichWay ) &&
                                        door->isUnderDoor( this->getX(), this->getY(), this->getZ() ) );
                        break;

                case Way::East:
                        result = ( this->getY() - static_cast< int >( getDescriptionOfItem()->getWidthY() ) + 1 < 0 );
                        break;

                case Way::Eastnorth:
                case Way::Eastsouth:
                        result = ( door != nilPointer &&
                                        this->getY() - static_cast< int >( getDescriptionOfItem()->getWidthY() ) + 1 < mediator->getRoom()->getLimitAt( onWhichWay ) &&
                                        door->isUnderDoor( this->getX(), this->getY(), this->getZ() ) );
                        break;

                case Way::West:
                        result = ( this->getY()
                                        >= static_cast< int >( mediator->getRoom()->getTilesY() * mediator->getRoom()->getSizeOfOneTile() ) );
                        break;

                case Way::Westnorth:
                case Way::Westsouth:
                        result = ( door != nilPointer &&
                                        this->getY() + static_cast< int >( getDescriptionOfItem()->getWidthY() ) > mediator->getRoom()->getLimitAt( onWhichWay ) &&
                                        door->isUnderDoor( this->getX(), this->getY(), this->getZ() ) );
                        break;

                default:
                        ;
        }

        return result;
}

void AvatarItem::behave ()
{
        if ( getBehavior() != nilPointer )
                dynamic_cast< behaviors::PlayerControlled * >( getBehavior ().get() )->behave ();
}

bool AvatarItem::update ()
{
        if ( getBehavior() != nilPointer )
                getBehavior()->update ();

        return false;
}

void AvatarItem::wait ()
{
        ActivityOfItem activity = getBehavior()->getActivityOfItem();

        // don’t wait while teleporting or loosing life
        if ( activity != activities::Activity::BeginWayOutTeletransport && activity != activities::Activity::WayOutTeletransport &&
                activity != activities::Activity::BeginWayInTeletransport && activity != activities::Activity::WayInTeletransport &&
                activity != activities::Activity::MeetMortalItem && activity != activities::Activity::Vanish )
        {
                // set waiting frame by orientation of item
                changeFrame( firstFrame () );

                getBehavior()->changeActivityOfItem( activities::Activity::Wait );
        }
}

bool AvatarItem::isActiveCharacter () const
{
        return mediator->getActiveCharacter()->getUniqueName() == this->getUniqueName() ;
}

unsigned char AvatarItem::getLives() const
{
        const std::string & character = this->getOriginalLabel() ;
        GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;
        return gameInfo.getLivesByName( character ) ;
}

void AvatarItem::addLives( unsigned char lives )
{
        const std::string & character = this->getOriginalLabel() ;
        GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;
        gameInfo.addLivesByName( character, lives );
}

void AvatarItem::loseLife ()
{
        setWayOfExit( "rebuild room" );

        const std::string & character = this->getOriginalLabel() ;
        GameManager & gameManager = GameManager::getInstance () ;
        GameInfo & gameInfo = gameManager.getGameInfo () ;
        unsigned char lives = gameInfo.getLivesByName( character ) ;

        if ( ! gameManager.areLivesInexhaustible () && lives > 0 )
                gameInfo.loseLifeByName( getOriginalLabel () /* current label is "bubbles" */ );

        gameManager.emptyHandbag () ;
}

void AvatarItem::takeMagicTool( const std::string & label )
{
        GameManager::getInstance().getGameInfo().setMagicToolByLabel( label );
}

unsigned short AvatarItem::getDonuts () const
{
        return GameManager::getInstance().getGameInfo ().getDoughnuts () ;
}

void AvatarItem::addDonuts( unsigned short howMany )
{
        GameManager::getInstance().getGameInfo ().addDoughnuts( howMany );
}

void AvatarItem::useDoughnutHorn ()
{
        GameManager::getInstance().getGameInfo ().consumeOneDoughnut () ;
}

unsigned short AvatarItem::getQuickSteps () const
{
        return GameManager::getInstance().getGameInfo ().getBonusQuickSteps () ;
}

void AvatarItem::activateBonusQuickSteps ()
{
        if ( this->getOriginalLabel() == "head" )
        {
                GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;

                unsigned short bonusHighSpeedSteps = 99 ;
                gameInfo.addQuickStepsByName( this->getOriginalLabel(), bonusHighSpeedSteps );
        }
}

void AvatarItem::decrementBonusQuickSteps ()
{
        GameManager::getInstance().getGameInfo().decrementQuickStepsByName( this->getOriginalLabel() );
}

unsigned short AvatarItem::getHighJumps () const
{
        return GameManager::getInstance().getGameInfo ().getBonusHighJumps () ;
}

void AvatarItem::addBonusHighJumps( unsigned char howMany )
{
        if ( getOriginalLabel() == "heels" )
        {
                GameManager::getInstance().getGameInfo().addHighJumpsByName( this->getOriginalLabel(), howMany );
        }
}

void AvatarItem::decrementBonusHighJumps ()
{
        GameManager::getInstance().getGameInfo().decrementHighJumpsByName( this->getOriginalLabel() );
}

void AvatarItem::activateShield ()
{
        shieldTimer->reset () ;
        shieldTimer->go () ;

        GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;
        const std::string & character = this->getOriginalLabel() ;
        gameInfo.setShieldPointsByName( character, 99 );
}

void AvatarItem::activateShieldForSeconds ( double seconds )
{
        shieldTimer->reset () ;

        if ( seconds > 0 && ! hasShield() )
        {
                shieldTimer->go () ;
        }

        GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;
        const std::string & character = this->getOriginalLabel() ;
        gameInfo.setShieldSecondsByName( character, seconds );
}

void AvatarItem::decrementShieldOverTime ()
{
        GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;
        double shieldSecondsRemaining = GameInfo::fullShieldTimeInSeconds - shieldTimer->getValue() ;

        if ( shieldSecondsRemaining < 0 )
        {
                shieldSecondsRemaining = 0 ;
                shieldTimer->stop () ;
        }

        const std::string & character = this->getOriginalLabel() ;
        gameInfo.setShieldSecondsByName( character, shieldSecondsRemaining );
}

void AvatarItem::liberatePlanet ()
{
        std::string scenery = this->mediator->getRoom()->getScenery();

        if ( scenery == "jail" || scenery == "blacktooth" || scenery == "market" )
        {
                GameManager::getInstance().liberatePlanet( "blacktooth" );
        }
        else if ( scenery == "egyptus" )
        {
                GameManager::getInstance().liberatePlanet( "egyptus" );
        }
        else if ( scenery == "penitentiary" )
        {
                GameManager::getInstance().liberatePlanet( "penitentiary" );
        }
        else if ( scenery == "safari" )
        {
                GameManager::getInstance().liberatePlanet( "safari" );
        }
        else if ( scenery == "byblos" )
        {
                GameManager::getInstance().liberatePlanet( "byblos" );
        }
}

void AvatarItem::placeItemInBag ( const std::string & labelOfItem, const std::string & behavior )
{
        this->descriptionOfTakenItem = ItemDescriptions::descriptions ().getDescriptionByLabel( labelOfItem ) ;
        this->behaviorOfTakenItem = behavior ;
}

void AvatarItem::emptyBag ()
{
        this->descriptionOfTakenItem = nilPointer ;
        this->behaviorOfTakenItem = "still" ;
}

void AvatarItem::save ()
{
        GameManager::getInstance().eatFish( *this, this->mediator->getRoom() );
}

void AvatarItem::saveAt ( int x, int y, int z )
{
        GameManager::getInstance().eatFish( *this, this->mediator->getRoom(), x, y, z );
}

bool AvatarItem::hasTool( const std::string & tool ) const
{
        GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;
        const std::string & character = this->getOriginalLabel() ;

        if ( tool == "horn" && gameInfo.hasHorn() )
                if (  character == "head" || character == "headoverheels" )
                        return true ;

        if ( tool == "handbag" && gameInfo.hasHandbag() )
                if ( character == "heels" || character == "headoverheels" )
                        return true ;

        return false ;
}

bool AvatarItem::hasShield () const
{
        GameInfo & gameInfo = GameManager::getInstance().getGameInfo () ;
        return gameInfo.getShieldPointsByName( this->getOriginalLabel() ) > 0 ;
}
