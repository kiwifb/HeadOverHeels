// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef Conveyor_hpp_
#define Conveyor_hpp_

#include "Behavior.hpp"
#include "Timer.hpp"


namespace behaviors
{

class Conveyor : public Behavior
{

public:

        Conveyor( const ItemPtr & item, const std::string & behavior ) ;

        virtual ~Conveyor( ) ;

        virtual bool update () ;

private:

       /**
        * Timer for speed of dragging items above
        */
        autouniqueptr < Timer > speedTimer ;

        autouniqueptr < Timer > animationTimer ;

};

}

#endif
