// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef Moving_hpp_
#define Moving_hpp_

#include "KindOfActivity.hpp"
#include "FreeItem.hpp"


namespace activities
{

class Moving : public KindOfActivity
{

protected:

        Moving( ) : KindOfActivity( ) {}

public:

        virtual ~Moving( ) {}

        static Moving & getInstance () ;

       /**
        * Item moves
        * @param behavior behavior of item
        * @param activity to get way of movement
        * @param canFall whether item may fall, false if it flies
        * @return true for move or change of activity, false for collision
        */
        virtual bool move ( behaviors::Behavior * behavior, ActivityOfItem * activity, bool canFall ) ;

protected:

        /**
         * Recursively lift items stacked on this item
         * @param freeItem Currently first item
         * @param z Units to ascend
         */
        void ascent ( FreeItem & freeItem, int z ) ;

        /**
         * Recursively lower items stacked on this item
         * @param freeItem Currently first item
         * @param z Units to descend
         */
        void descend ( FreeItem & freeItem, int z ) ;

private:

        static Moving * instance ;

};

}

#endif
