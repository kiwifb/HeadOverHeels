// The free and open source remake of Head over Heels
//
// Copyright © 2023 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game by Jon Ritman and Bernie Drummond
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef SelectLanguage_hpp_
#define SelectLanguage_hpp_

#include "Action.hpp"


namespace gui
{

class SelectLanguage: public Action
{

public:

        explicit SelectLanguage( const std::string& language ) ;

        virtual std::string getNameOfAction () const {  return "SelectLanguage" ;  }

protected:

        /**
         * Set the language of the game
         */
        virtual void doAction () ;

private:

        std::string language ;

};

}

#endif
