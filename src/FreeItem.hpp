// The free and open source remake of Head over Heels
//
// Copyright © 2018 Douglas Mencken dougmencken@gmail.com
// Copyright © 2008 Jorge Rodríguez Santos
// Original game copyright © 1987 Ocean Software Ltd.
//
// This program is free software
// You may redistribute it and~or modify it under the terms of the GNU General Public License
// either version 3 of the License or at your option any later version

#ifndef FreeItem_hpp_
#define FreeItem_hpp_

#include <utility>
#include <cmath>

#include <WrappersAllegro.hpp>

#include "Ism.hpp"

#include "Item.hpp"
#include "Drawable.hpp"


namespace isomot
{

// ~TO~DO~ bin it completely
enum WhichMask
{
        NoMask,         /* masked image is nil, wantMask is true or false */
        WantRemask,     /* masked image is not nil and wantMask is true */
        AlreadyMasked   /* masked image is not nil and wantMask is false */
} ;

class ItemData ;

/**
 * Free items are those that may be anywhere and move around the room such as
 * players, enemies, or something which widths differ from widths of grid’s cells
 */

class FreeItem : public Item, public Drawable
{

public:

       /**
        * Constructor
        * @param itemData Data about this item
        * @param x Position on X
        * @param y Position on Y
        * @param z Position on Z, or how far is floor
        * @param way Initial orientation of item
        */
        FreeItem( ItemData* itemData, int x, int y, int z, const Way& way ) ;

       /**
        * Copy constructor
        */
        FreeItem( const FreeItem& freeItem ) ;

        virtual ~FreeItem( ) ;

        virtual std::string whichKindOfItem () const {  return "free item" ;  }

        virtual bool addToPosition ( int x, int y, int z ) ;

        void draw ( allegro::Pict* where ) ;

        void binBothProcessedImages () ;

        /**
         * Change graphics of item
         */
        virtual void changeImage ( allegro::Pict* newImage ) ;

        /**
         * Change graphics of item’s shadow
         */
        virtual void changeShadow ( allegro::Pict* newShadow ) ;

        /**
         * Request to shade item
         */
        void requestShadow () ;

        /**
         * Request to mask this item
         */
        void requestMask () ;

        /**
         * Enmascara la imagen del elemento con la imagen de otro elemento
         * @param x Coordenada X de pantalla donde está situada la imagen del elemento que servirá de máscara
         * @param y Coordenada Y de pantalla donde está situada la imagen del elemento que servirá de máscara
         */
        void maskImage ( int x, int y, allegro::Pict* image ) ;

protected:

        WhichMask myMask ;

        /**
         * Degree of item’s transparency in percentage 0 to 100
         */
        unsigned char transparency ;

        /**
         * Whether this item detects collisions
         */
        bool collisionDetector ;

        /**
         * Whether item is inactive
         */
        bool frozen ;

        /**
         * Current frame of this item shaded but not masked yet
         */
        allegro::Pict * shadedNonmaskedImage ;

        bool partOfDoor ;

public:

        void setWhichMask ( const WhichMask& mask ) {  myMask = mask ;  }

        WhichMask whichMask () const {  return myMask ;  }

        /**
         * Grado de transparencia del elemento
         * @return Un número entre 0 y 100, inclusive
         */
        unsigned char getTransparency () const {  return transparency ;  }

        /**
         * Set item’s ability to detect collisions
         */
        void setCollisionDetector ( bool collisionDetector ) {  this->collisionDetector = collisionDetector ;  }

        bool isCollisionDetector () const {  return collisionDetector ;  }

        /**
         * Set item’s inactivity
         */
        void setFrozen ( bool frozen ) {  this->frozen = frozen ;  }

        bool isFrozen () const {  return frozen ;  }

        allegro::Pict * getShadedNonmaskedImage () const {  return shadedNonmaskedImage ;  }

        void setShadedNonmaskedImage ( allegro::Pict * newImage ) ;

        bool isPartOfDoor () const {  return partOfDoor ;  }

        void setPartOfDoor ( bool isPart ) {  partOfDoor = isPart ;  }

};

}

#endif
