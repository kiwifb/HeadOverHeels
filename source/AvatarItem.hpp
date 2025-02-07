// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef AvatarItem_hpp_
#define AvatarItem_hpp_

#include <vector>

#include "FreeItem.hpp"
#include "DescriptionOfItem.hpp"
#include "Timer.hpp"
#include "Picture.hpp"


/**
 * An avatar is a game character controlled by the player
 */

class AvatarItem : public FreeItem
{

public:

        AvatarItem( const DescriptionOfItem* description, int x, int y, int z, const std::string& orientation ) ;

        AvatarItem( const AvatarItem & toCopy ) ;

        virtual ~AvatarItem( ) { }

        virtual std::string whichKindOfItem () const {  return "avatar item" ;  }

        bool isHead () const {  return getOriginalLabel() == "head" ;  }

        bool isHeels () const {  return getOriginalLabel() == "heels" ;  }

        bool isHeadOverHeels () const {  return getOriginalLabel() == "headoverheels" ;  }

        void autoMoveOnEntry ( const std::string & wayOfEntry ) ;

        virtual void behave () ;

        /**
         * Update the behavior
         */
        virtual bool update () ;

        void wait () ;

        bool isActiveCharacter () const ;

        unsigned char getLives() const ;

        void addLives( unsigned char lives ) ;

        void loseLife () ;

        /**
         * the character takes a magic tool, one of "horn" or "handbag"
         */
        void takeMagicTool( const std::string & label ) ;

        unsigned short getDonuts () const ;

        void addDonuts( unsigned short howMany ) ;

        /**
         * the character releases a doughnut
         */
        void useDoughnutHorn () ;

        unsigned short getQuickSteps () const ;

        void activateBonusQuickSteps () ;

        void decrementBonusQuickSteps () ;

        unsigned short getHighJumps () const ;

        void addBonusHighJumps ( unsigned char howMany ) ;

        void decrementBonusHighJumps () ;

        void activateShield () ;

        void activateShieldForSeconds ( double seconds ) ;

        void decrementShieldOverTime () ;

        /**
         * Character just liberated a planet
         */
        void liberatePlanet() ;

        /**
         * Save game when a character meets reincarnation fish
         */
        void save () ;

        void saveAt ( int x, int y, int z ) ;

        virtual bool addToPosition ( int x, int y, int z ) ;

        void placeItemInBag ( const std::string & labelOfItem, const std::string & behavior ) ;

        void emptyBag () ;

        const DescriptionOfItem * getDescriptionOfTakenItem () const {  return descriptionOfTakenItem ;  }

        const std::string & getBehaviorOfTakenItem () const {  return this->behaviorOfTakenItem ;  }

        /**
         * This character has the temporary invulnerability or doesn't have
         */
        bool hasShield () const ;

        /**
         * This character has the magic tool, the horn or the bag, or doesn't have
         */
        bool hasTool ( const std::string & tool ) const ;

        void setWayOfExit ( const std::string& way ) ;

        const std::string & getWayOfExit () const {  return wayOfExit ;  }

        const std::string & getWayOfEntry () const {  return wayOfEntry ;  }

        void setWayOfEntry ( const std::string& way ) {  wayOfEntry = way ;  }

protected:

        /**
         * See if the character crosses the limits of room, if yes then change the room
         */
        bool isCollidingWithLimitsOfRoom( const std::string & onWhichWay ) ;

private:

        /**
         * The way by which the character leaves the room
         */
        std::string wayOfExit ;

        /**
         * How the character enters the room:
         * through a door, or via teleport, or going below the floor or above the ceiling
         */
        std::string wayOfEntry ;

        autouniqueptr < Timer > shieldTimer ;

        const DescriptionOfItem * descriptionOfTakenItem ;

        std::string behaviorOfTakenItem ;

} ;

typedef multiptr < AvatarItem > AvatarItemPtr ;

#endif
