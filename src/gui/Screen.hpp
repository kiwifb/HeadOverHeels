// The free and open source remake of Head over Heels
//
// Copyright © 2017 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef Screen_hpp_
#define Screen_hpp_

#include <list>
#include <vector>
#include <allegro.h>
#include "Widget.hpp"


namespace gui
{

class Action ;
class AnimatedPicture ;

/**
 * Container for elements of user interface
 */

class Screen : public Widget
{

public:

        /**
         * Constructor
         * @param picture Where to draw this screen
         * @param action Action for which this screen is created
         */
        Screen( BITMAP * picture, Action * action ) ;

        virtual ~Screen( ) ;

        /**
         * Dibuja todo el contenido de la pantalla
         * @param where Imagen donde será dibujada
         */
        void draw ( BITMAP* where ) ;

        /**
         * Responde a la pulsación de una tecla
         */
        void handleKey ( int key ) ;

        void addWidget ( Widget* widget ) ;

        bool removeWidget ( Widget* widget ) ;

        size_t countWidgets () {  return widgets.size () ;  }

        void freeWidgets () ;

        void addPictureOfHeadAt ( int x, int y ) ;

        void addPictureOfHeelsAt ( int x, int y ) ;

        void placeHeadAndHeels ( bool imagesToo, bool copyrightsToo ) ;

        static BITMAP * loadPicture ( const char * nameOfPicture ) ;

        static std::vector < BITMAP * > loadAnimation ( const char * nameOfGif ) ;

        static const double delayBetweenFrames = 0.1 ;

private:

        /**
         * Color de fondo
         */
        int backgroundColor ;

        /**
         * Imagen donde se volcarán la pantalla
         */
        BITMAP * where ;

        /**
         * Elementos de la interfaz de usuario contenidos en la pantalla
         */
        std::list < Widget * > widgets ;

        Action * actionOfScreen ;

        Action * escapeAction ;

        Widget * keyHandler ;

        AnimatedPicture * pictureOfHead ;

        AnimatedPicture * pictureOfHeels ;

protected:

        /**
         * Imagen de fondo de la pantalla
         */
        static BITMAP * backgroundPicture ;

public:

        static void refreshBackground () ;

        void refreshPicturesOfHeadAndHeels () ;

        Action * getActionOfScreen () const {  return actionOfScreen ;  }

        void setEscapeAction ( Action * action ) ;

        Action * getEscapeAction () const {  return escapeAction ;  }

        /**
         * Assign successor of this component in chain to handle typing of key
         */
        void setKeyHandler ( Widget* widget ) {  keyHandler = widget ;  }

        Widget * getKeyHandler () const {  return keyHandler ;  }

};

}

#endif
