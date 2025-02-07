// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef Special_hpp_
#define Special_hpp_

#include "Behavior.hpp"
#include "AvatarItem.hpp"
#include "Timer.hpp"


namespace behaviors
{

/**
 * Behavior of magic bonus item
 */

class Special : public Behavior
{

public:

        Special( const ItemPtr & item, const std::string& behavior ) ;

        virtual ~Special () { }

        virtual bool update () ;

protected:

        /**
         * Checks if magic item can be taken, it depends on item and on character who takes it
         */
        bool mayTake ( const std::string & character ) ;

        void takeMagicItem ( AvatarItem & whoTakes ) ;

private:

        /**
         * Timer for disappearance of bonus
         */
        autouniqueptr < Timer > disappearanceTimer ;

        /**
         * Timer for speed of item’s movement
         */
        autouniqueptr < Timer > speedTimer ;

        /**
         * Timer for speed of item’s falling
         */
        autouniqueptr < Timer > fallTimer ;

};

}

#endif
