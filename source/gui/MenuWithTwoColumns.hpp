// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef MenuWithTwoColumns_hpp_
#define MenuWithTwoColumns_hpp_

#include "Menu.hpp"


namespace gui
{

/*
 * Two-column menu
 */

class MenuWithTwoColumns : public Menu
{

public:

        /**
         * @param space Space between columns
         */
        MenuWithTwoColumns( unsigned int space );

        virtual ~MenuWithTwoColumns( );

        virtual void draw () ;

        virtual unsigned int getWidthOfMenu () const ;

        virtual unsigned int getHeightOfMenu () const ;

private:

        unsigned int spaceBetweenColumns;

};

}

#endif
