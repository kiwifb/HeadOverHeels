// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef DisplaceKindOfActivity_hpp_
#define DisplaceKindOfActivity_hpp_

#include "KindOfActivity.hpp"


namespace activities
{

class DisplaceKindOfActivity : public KindOfActivity
{

protected:

        DisplaceKindOfActivity( ) : KindOfActivity( ) {}

public:

        virtual ~DisplaceKindOfActivity( ) {}

        static DisplaceKindOfActivity & getInstance() ;

       /**
        * Item is being displaced
        * @param behavior behavior of item
        * @param activity subactivity to get way of movement
        * @param canFall whether item may fall, false if it flies
        * @return true for displace or change of activity, false for collision
        */
        virtual bool displace ( behaviors::Behavior * behavior, ActivityOfItem * activity, bool canFall ) ;

private:

        static DisplaceKindOfActivity * instance ;

};

}

#endif
