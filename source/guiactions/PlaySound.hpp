// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef PlaySound_hpp_
#define PlaySound_hpp_

#include "SoundManager.hpp"


namespace gui
{

class PlaySound : public Action
{

public:

        explicit PlaySound( const ActivityOfItem& what ) : Action( ), whichSound( what ) { }

        virtual ~PlaySound( ) { }

        virtual std::string getNameOfAction () const {  return "PlaySound" ;  }

protected:

        virtual void doAction ()
        {
                SoundManager::getInstance().stopEverySound (); //stop ( "gui", whichSound );
                SoundManager::getInstance().play ( "gui", whichSound, /* loop */ false );
        }

private:

        ActivityOfItem whichSound ;

};

}

#endif
