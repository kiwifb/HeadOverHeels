// Copyright (C) 2005-2007 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file
//

#include <xsd/cxx/pre.hxx>

#include "ConfigurationXML.hpp"

namespace cxml
{
  // ConfigurationXML
  //

  const ConfigurationXML::language_type& ConfigurationXML::
  language () const
  {
    return this->language_.get ();
  }

  ConfigurationXML::language_type& ConfigurationXML::
  language ()
  {
    return this->language_.get ();
  }

  void ConfigurationXML::
  language (const language_type& language)
  {
    this->language_.set (language);
  }

  void ConfigurationXML::
  language (::std::auto_ptr< language_type > language)
  {
    this->language_.set (language);
  }

  const ConfigurationXML::keyboard_type& ConfigurationXML::
  keyboard () const
  {
    return this->keyboard_.get ();
  }

  ConfigurationXML::keyboard_type& ConfigurationXML::
  keyboard ()
  {
    return this->keyboard_.get ();
  }

  void ConfigurationXML::
  keyboard (const keyboard_type& keyboard)
  {
    this->keyboard_.set (keyboard);
  }

  void ConfigurationXML::
  keyboard (::std::auto_ptr< keyboard_type > keyboard)
  {
    this->keyboard_.set (keyboard);
  }

  const ConfigurationXML::audio_type& ConfigurationXML::
  audio () const
  {
    return this->audio_.get ();
  }

  ConfigurationXML::audio_type& ConfigurationXML::
  audio ()
  {
    return this->audio_.get ();
  }

  void ConfigurationXML::
  audio (const audio_type& audio)
  {
    this->audio_.set (audio);
  }

  void ConfigurationXML::
  audio (::std::auto_ptr< audio_type > audio)
  {
    this->audio_.set (audio);
  }

  const ConfigurationXML::video_type& ConfigurationXML::
  video () const
  {
    return this->video_.get ();
  }

  ConfigurationXML::video_type& ConfigurationXML::
  video ()
  {
    return this->video_.get ();
  }

  void ConfigurationXML::
  video (const video_type& video)
  {
    this->video_.set (video);
  }

  void ConfigurationXML::
  video (::std::auto_ptr< video_type > video)
  {
    this->video_.set (video);
  }

  // keyboard
  //

  const keyboard::movenorth_type& keyboard::
  movenorth () const
  {
    return this->movenorth_.get ();
  }

  keyboard::movenorth_type& keyboard::
  movenorth ()
  {
    return this->movenorth_.get ();
  }

  void keyboard::
  movenorth ( const movenorth_type& movenorth )
  {
    this->movenorth_.set ( movenorth );
  }

  const keyboard::movesouth_type& keyboard::
  movesouth () const
  {
    return this->movesouth_.get ();
  }

  keyboard::movesouth_type& keyboard::
  movesouth ()
  {
    return this->movesouth_.get ();
  }

  void keyboard::
  movesouth ( const movesouth_type& movesouth )
  {
    this->movesouth_.set ( movesouth );
  }

  const keyboard::moveeast_type& keyboard::
  moveeast () const
  {
    return this->moveeast_.get ();
  }

  keyboard::moveeast_type& keyboard::
  moveeast ()
  {
    return this->moveeast_.get ();
  }

  void keyboard::
  moveeast ( const moveeast_type& moveeast )
  {
    this->moveeast_.set ( moveeast );
  }

  const keyboard::movewest_type& keyboard::
  movewest () const
  {
    return this->movewest_.get ();
  }

  keyboard::movewest_type& keyboard::
  movewest ()
  {
    return this->movewest_.get ();
  }

  void keyboard::
  movewest ( const movewest_type& movewest )
  {
    this->movewest_.set ( movewest );
  }

  const keyboard::take_type& keyboard::
  take () const
  {
    return this->take_.get ();
  }

  keyboard::take_type& keyboard::
  take ()
  {
    return this->take_.get ();
  }

  void keyboard::
  take (const take_type& take)
  {
    this->take_.set (take);
  }

  const keyboard::jump_type& keyboard::
  jump () const
  {
    return this->jump_.get ();
  }

  keyboard::jump_type& keyboard::
  jump ()
  {
    return this->jump_.get ();
  }

  void keyboard::
  jump (const jump_type& jump)
  {
    this->jump_.set (jump);
  }

  const keyboard::doughnut_type& keyboard::
  doughnut () const
  {
    return this->doughnut_.get ();
  }

  keyboard::doughnut_type& keyboard::
  doughnut ()
  {
    return this->doughnut_.get ();
  }

  void keyboard::
  doughnut (const doughnut_type& doughnut)
  {
    this->doughnut_.set (doughnut);
  }

  const keyboard::takeandjump_type& keyboard::
  takeandjump () const
  {
    return this->takeandjump_.get ();
  }

  keyboard::takeandjump_type& keyboard::
  takeandjump ()
  {
    return this->takeandjump_.get ();
  }

  void keyboard::
  takeandjump (const takeandjump_type& takeandjump)
  {
    this->takeandjump_.set (takeandjump);
  }

  const keyboard::swap_type& keyboard::
  swap () const
  {
    return this->swap_.get ();
  }

  keyboard::swap_type& keyboard::
  swap ()
  {
    return this->swap_.get ();
  }

  void keyboard::
  swap (const swap_type& swap)
  {
    this->swap_.set (swap);
  }

  const keyboard::pause_type& keyboard::
  pause () const
  {
    return this->pause_.get ();
  }

  keyboard::pause_type& keyboard::
  pause ()
  {
    return this->pause_.get ();
  }

  void keyboard::
  pause (const pause_type& pause)
  {
    this->pause_.set (pause);
  }


  // audio
  //

  const audio::fx_type& audio::
  fx () const
  {
    return this->fx_.get ();
  }

  audio::fx_type& audio::
  fx ()
  {
    return this->fx_.get ();
  }

  void audio::
  fx (const fx_type& fx)
  {
    this->fx_.set (fx);
  }

  const audio::music_type& audio::
  music () const
  {
    return this->music_.get ();
  }

  audio::music_type& audio::
  music ()
  {
    return this->music_.get ();
  }

  void audio::
  music (const music_type& music)
  {
    this->music_.set (music);
  }

  const audio::roomtunes_type& audio::
  roomtunes () const
  {
    return this->roomtunes_.get ();
  }

  audio::roomtunes_type& audio::
  roomtunes ()
  {
    return this->roomtunes_.get ();
  }

  void audio::
  roomtunes (const roomtunes_type& roomtunes)
  {
    this->roomtunes_.set (roomtunes);
  }

  // video
  //

  const video::fullscreen_type& video::
  fullscreen () const
  {
    return this->fullscreen_.get ();
  }

  video::fullscreen_type& video::
  fullscreen ()
  {
    return this->fullscreen_.get ();
  }

  void video::
  fullscreen (const fullscreen_type& fullscreen)
  {
    this->fullscreen_.set (fullscreen);
  }

  const video::shadows_type& video::
  shadows () const
  {
    return this->shadows_.get ();
  }

  video::shadows_type& video::
  shadows ()
  {
    return this->shadows_.get ();
  }

  void video::
  shadows (const shadows_type& shadows)
  {
    this->shadows_.set (shadows);
  }

  const video::background_type& video::
  background () const
  {
    return this->background_.get ();
  }

  video::background_type& video::
  background ()
  {
    return this->background_.get ();
  }

  void video::
  background (const background_type& background)
  {
    this->background_.set (background);
  }

  const video::graphics_type& video::
  graphics () const
  {
    return this->graphics_.get ();
  }

  video::graphics_type& video::
  graphics ()
  {
    return this->graphics_.get ();
  }

  void video::
  graphics (const graphics_type& graphics)
  {
    this->graphics_.set (graphics);
  }

  void video::
  graphics (::std::auto_ptr< graphics_type > graphics)
  {
    this->graphics_.set (graphics);
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace cxml
{
  // ConfigurationXML
  //

  ConfigurationXML::
  ConfigurationXML (const language_type& language,
                    const keyboard_type& keyboard,
                    const audio_type& audio,
                    const video_type& video)
  : ::xml_schema::type (),
    language_ (language, ::xml_schema::flags (), this),
    keyboard_ (keyboard, ::xml_schema::flags (), this),
    audio_ (audio, ::xml_schema::flags (), this),
    video_ (video, ::xml_schema::flags (), this)
  {
  }

  ConfigurationXML::
  ConfigurationXML (const ConfigurationXML& x,
                    ::xml_schema::flags f,
                    ::xml_schema::type* c)
  : ::xml_schema::type (x, f, c),
    language_ (x.language_, f, this),
    keyboard_ (x.keyboard_, f, this),
    audio_ (x.audio_, f, this),
    video_ (x.video_, f, this)
  {
  }

  ConfigurationXML::
  ConfigurationXML (const ::xercesc::DOMElement& e,
                    ::xml_schema::flags f,
                    ::xml_schema::type* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    language_ (f, this),
    keyboard_ (f, this),
    audio_ (f, this),
    video_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void ConfigurationXML::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // language

      if (n.name () == "language" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< language_type > r (
          language_traits::create (i, f, this));

        if (!language_.present ())
        {
          this->language (r);
          continue;
        }
      }

      // keyboard

      if (n.name () == "keyboard" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< keyboard_type > r (
          keyboard_traits::create (i, f, this));

        if (!keyboard_.present ())
        {
          this->keyboard (r);
          continue;
        }
      }

      // audio

      if (n.name () == "audio" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< audio_type > r (
          audio_traits::create (i, f, this));

        if (!audio_.present ())
        {
          this->audio (r);
          continue;
        }
      }

      // video

      if (n.name () == "video" && n.namespace_ ().empty ())
      {
        ::std::auto_ptr< video_type > r (
          video_traits::create (i, f, this));

        if (!video_.present ())
        {
          this->video (r);
          continue;
        }
      }

      break;
    }
  }

  ConfigurationXML* ConfigurationXML::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new ConfigurationXML (*this, f, c);
  }

  // keyboard
  //

  keyboard::
  keyboard (const movenorth_type& movenorth,
            const movesouth_type& movesouth,
            const moveeast_type& moveeast,
            const movewest_type& movewest,
            const take_type& take,
            const jump_type& jump,
            const doughnut_type& doughnut,
            const takeandjump_type& takeandjump,
            const swap_type& swap,
            const pause_type& pause)
  : ::xml_schema::type (),
    movenorth_ (movenorth, ::xml_schema::flags (), this),
    movesouth_ (movesouth, ::xml_schema::flags (), this),
    moveeast_ (moveeast, ::xml_schema::flags (), this),
    movewest_ (movewest, ::xml_schema::flags (), this),
    take_ (take, ::xml_schema::flags (), this),
    jump_ (jump, ::xml_schema::flags (), this),
    doughnut_ (doughnut, ::xml_schema::flags (), this),
    takeandjump_ (takeandjump, ::xml_schema::flags (), this),
    swap_ (swap, ::xml_schema::flags (), this),
    pause_ (pause, ::xml_schema::flags (), this)
  {
  }

  keyboard::
  keyboard (const keyboard& x,
            ::xml_schema::flags f,
            ::xml_schema::type* c)
  : ::xml_schema::type (x, f, c),
    movenorth_ (x.movenorth_, f, this),
    movesouth_ (x.movesouth_, f, this),
    moveeast_ (x.moveeast_, f, this),
    movewest_ (x.movewest_, f, this),
    take_ (x.take_, f, this),
    jump_ (x.jump_, f, this),
    doughnut_ (x.doughnut_, f, this),
    takeandjump_ (x.takeandjump_, f, this),
    swap_ (x.swap_, f, this),
    pause_ (x.pause_, f, this)
  {
  }

  keyboard::
  keyboard (const ::xercesc::DOMElement& e,
            ::xml_schema::flags f,
            ::xml_schema::type* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    movenorth_ (f, this),
    movesouth_ (f, this),
    moveeast_ (f, this),
    movewest_ (f, this),
    take_ (f, this),
    jump_ (f, this),
    doughnut_ (f, this),
    takeandjump_ (f, this),
    swap_ (f, this),
    pause_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void keyboard::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // movenorth
      //
      if (n.name () == "movenorth" && n.namespace_ ().empty ())
      {
        if (!movenorth_.present ())
        {
          this->movenorth (movenorth_traits::create (i, f, this));
          continue;
        }
      }

      // movesouth
      //
      if (n.name () == "movesouth" && n.namespace_ ().empty ())
      {
        if (!movesouth_.present ())
        {
          this->movesouth (movesouth_traits::create (i, f, this));
          continue;
        }
      }

      // moveeast
      //
      if (n.name () == "moveeast" && n.namespace_ ().empty ())
      {
        if (!moveeast_.present ())
        {
          this->moveeast (moveeast_traits::create (i, f, this));
          continue;
        }
      }

      // movewest
      //
      if (n.name () == "movewest" && n.namespace_ ().empty ())
      {
        if (!movewest_.present ())
        {
          this->movewest (movewest_traits::create (i, f, this));
          continue;
        }
      }

      // take
      //
      if (n.name () == "take" && n.namespace_ ().empty ())
      {
        if (!take_.present ())
        {
          this->take (take_traits::create (i, f, this));
          continue;
        }
      }

      // jump
      //
      if (n.name () == "jump" && n.namespace_ ().empty ())
      {
        if (!jump_.present ())
        {
          this->jump (jump_traits::create (i, f, this));
          continue;
        }
      }

      // doughnut
      //
      if (n.name () == "doughnut" && n.namespace_ ().empty ())
      {
        if (!doughnut_.present ())
        {
          this->doughnut (doughnut_traits::create (i, f, this));
          continue;
        }
      }

      // takeandjump
      //
      if (n.name () == "takeandjump" && n.namespace_ ().empty ())
      {
        if (!takeandjump_.present ())
        {
          this->takeandjump (takeandjump_traits::create (i, f, this));
          continue;
        }
      }

      // swap
      //
      if (n.name () == "swap" && n.namespace_ ().empty ())
      {
        if (!swap_.present ())
        {
          this->swap (swap_traits::create (i, f, this));
          continue;
        }
      }

      // pause
      //
      if (n.name () == "pause" && n.namespace_ ().empty ())
      {
        if (!pause_.present ())
        {
          this->pause (pause_traits::create (i, f, this));
          continue;
        }
      }

      break;
    }
  }

  keyboard* keyboard::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new keyboard (*this, f, c);
  }

  // audio
  //

  audio::
  audio ( const fx_type& fx,
          const music_type& music,
          const roomtunes_type& roomtunes)
  : ::xml_schema::type (),
    fx_ (fx, ::xml_schema::flags (), this),
    music_ (music, ::xml_schema::flags (), this),
    roomtunes_ (roomtunes, ::xml_schema::flags (), this)
  {
  }

  audio::
  audio ( const audio& x,
          ::xml_schema::flags f,
          ::xml_schema::type* c)
  : ::xml_schema::type (x, f, c),
    fx_ (x.fx_, f, this),
    music_ (x.music_, f, this),
    roomtunes_ (x.roomtunes_, f, this)
  {
  }

  audio::
  audio ( const ::xercesc::DOMElement& e,
          ::xml_schema::flags f,
          ::xml_schema::type* c)
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    fx_ (f, this),
    music_ (f, this),
    roomtunes_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void audio::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // fx
      //
      if (n.name () == "fx" && n.namespace_ ().empty ())
      {
        if (!fx_.present ())
        {
          this->fx (fx_traits::create (i, f, this));
          continue;
        }
      }

      // music
      //
      if (n.name () == "music" && n.namespace_ ().empty ())
      {
        if (!music_.present ())
        {
          this->music (music_traits::create (i, f, this));
          continue;
        }
      }

      // room tunes
      //
      if (n.name () == "roomtunes" && n.namespace_ ().empty ())
      {
        if ( ! roomtunes_.present () )
        {
          this->roomtunes (roomtunes_traits::create (i, f, this));
          continue;
        }
      }

      break;
    }
  }

  audio* audio::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new audio (*this, f, c);
  }

  // video
  //

  video::
  video ( const fullscreen_type& fullscreen,
          const shadows_type& shadows,
          const background_type& background,
          const graphics_type& graphics )
  : ::xml_schema::type (),
    fullscreen_ (fullscreen, ::xml_schema::flags (), this),
    shadows_ (shadows, ::xml_schema::flags (), this),
    background_ (background, ::xml_schema::flags (), this),
    graphics_ (graphics, ::xml_schema::flags (), this)
  {
  }

  video::
  video ( const video& x,
          ::xml_schema::flags f,
          ::xml_schema::type* c )
  : ::xml_schema::type (x, f, c),
    fullscreen_ (x.fullscreen_, f, this),
    shadows_ (x.shadows_, f, this),
    background_ (x.background_, f, this),
    graphics_ (x.graphics_, f, this)
  {
  }

  video::
  video ( const ::xercesc::DOMElement& e,
          ::xml_schema::flags f,
          ::xml_schema::type* c )
  : ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
    fullscreen_ (f, this),
    shadows_ (f, this),
    background_ (f, this),
    graphics_ (f, this)
  {
    if ((f & ::xml_schema::flags::base) == 0)
    {
      ::xsd::cxx::xml::dom::parser< char > p (e);
      this->parse (p, f);
    }
  }

  void video::
  parse (::xsd::cxx::xml::dom::parser< char >& p,
         ::xml_schema::flags f)
  {
    for (; p.more_elements (); p.next_element ())
    {
      const ::xercesc::DOMElement& i (p.cur_element ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (i));

      // fullscreen

      if (n.name () == "fullscreen" && n.namespace_ ().empty ())
      {
        if (!fullscreen_.present ())
        {
          this->fullscreen (fullscreen_traits::create (i, f, this));
          continue;
        }
      }

      // shadows

      if (n.name () == "shadows" && n.namespace_ ().empty ())
      {
        if (!shadows_.present ())
        {
          this->shadows (shadows_traits::create (i, f, this));
          continue;
        }
      }

      // background

      if (n.name () == "background" && n.namespace_ ().empty ())
      {
        if (!background_.present ())
        {
          this->background (background_traits::create (i, f, this));
          continue;
        }
      }

      // graphics

      if (n.name () == "graphics" && n.namespace_ ().empty ())
      {
        if (!graphics_.present ())
        {
          this->graphics (graphics_traits::create (i, f, this));
          continue;
        }
      }

      break;
    }
  }

  video* video::
  _clone (::xml_schema::flags f,
          ::xml_schema::type* c) const
  {
    return new video (*this, f, c);
  }
}

#include <istream>
#include <xercesc/framework/Wrapper4InputSource.hpp>
#include <xsd/cxx/xml/sax/std-input-source.hxx>

namespace cxml
{
  ::std::auto_ptr< ::cxml::ConfigurationXML >
  preferences (  const ::std::string& u,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p )
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d ( ::xsd::cxx::xml::dom::parse< char > ( u, p, f ) );

    if ( ! d ) throw ::xsd::cxx::tree::parsing< char > ();

    ::std::auto_ptr< ::cxml::ConfigurationXML > r (
      ::cxml::preferences (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::cxml::ConfigurationXML >
  preferences (  ::std::istream& is,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p )
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::cxml::preferences (wrap, f, p);
  }

  ::std::auto_ptr< ::cxml::ConfigurationXML >
  preferences (  ::std::istream& is,
                 const ::std::string& sid,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p )
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0,
      (f & ::xml_schema::flags::keep_dom) == 0);

    ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
    ::xercesc::Wrapper4InputSource wrap (&isrc, false);
    return ::cxml::preferences (wrap, f, p);
  }

  ::std::auto_ptr< ::cxml::ConfigurationXML >
  preferences (  const ::xercesc::DOMLSInput& i,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p )
  {
    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d ( ::xsd::cxx::xml::dom::parse< char > ( i, p, f ) );

    if ( ! d ) throw ::xsd::cxx::tree::parsing< char > ();

    ::std::auto_ptr< ::cxml::ConfigurationXML > r (
      ::cxml::preferences (
        d.get (), f | ::xml_schema::flags::own_dom, p));

    if (f & ::xml_schema::flags::keep_dom)
      d.release ();

    return r;
  }

  ::std::auto_ptr< ::cxml::ConfigurationXML >
  preferences (  const ::xercesc::DOMDocument& d,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& p )
  {
    if (f & ::xml_schema::flags::keep_dom)
    {
      ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > c (
        static_cast< ::xercesc::DOMDocument* > (d.cloneNode (true)));

      ::std::auto_ptr< ::cxml::ConfigurationXML > r (
        ::cxml::preferences (
          c.get (), f | ::xml_schema::flags::own_dom, p));

      c.release ();
      return r;
    }

    const ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (n.name () == "preferences" &&
        n.namespace_ () == "")
    {
      ::std::auto_ptr< ::cxml::ConfigurationXML > r (
        ::xsd::cxx::tree::traits< ::cxml::ConfigurationXML, char >::create (
          e, f, 0));
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "preferences",
      "");
  }

  ::std::auto_ptr< ::cxml::ConfigurationXML >
  preferences (  ::xercesc::DOMDocument* d,
                 ::xml_schema::flags f,
                 const ::xml_schema::properties& )
  {
    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > c (
      ((f & ::xml_schema::flags::keep_dom) &&
       !(f & ::xml_schema::flags::own_dom))
      ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
      : 0);

    const ::xercesc::DOMElement& e (
      c.get ()
      ? *c->getDocumentElement ()
      : *d->getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (n.name () == "preferences" &&
        n.namespace_ () == "")
    {
      ::std::auto_ptr< ::cxml::ConfigurationXML > r (
        ::xsd::cxx::tree::traits< ::cxml::ConfigurationXML, char >::create (
          e, f, 0));
      c.release ();
      return r;
    }

    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "preferences",
      "");
  }
}

#include <ostream>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace cxml
{
  void
  preferences (  ::std::ostream& o,
                 const ::cxml::ConfigurationXML& s,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f )
  {
    ::xsd::cxx::xml::auto_initializer i (
      (f & ::xml_schema::flags::dont_initialize) == 0);

    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::cxml::preferences (s, m, f));

    ::xsd::cxx::xml::dom::ostream_format_target t (o);
    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, f))
    {
      throw ::xsd::cxx::tree::parsing< char > ();
    }
  }

  void
  preferences (  ::xercesc::XMLFormatTarget& t,
                 const ::cxml::ConfigurationXML& s,
                 const ::xml_schema::namespace_infomap& m,
                 const ::std::string& e,
                 ::xml_schema::flags f )
  {
    ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
      ::cxml::preferences (s, m, f));

    if (!::xsd::cxx::xml::dom::serialize (t, *d, e, f))
    {
      throw ::xsd::cxx::tree::parsing< char > ();
    }
  }

  void
  preferences (  ::xercesc::DOMDocument& d,
                 const ::cxml::ConfigurationXML& s,
                 ::xml_schema::flags )
  {
    ::xercesc::DOMElement& e (*d.getDocumentElement ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (e));

    if (n.name () == "preferences" &&
        n.namespace_ () == "")
    {
      e << s;
    }
    else
    {
      throw ::xsd::cxx::tree::unexpected_element < char > (
        n.name (),
        n.namespace_ (),
        "preferences",
        "");
    }
  }

  ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument >
  preferences (  const ::cxml::ConfigurationXML& s,
                 const ::xml_schema::namespace_infomap& m,
                 ::xml_schema::flags f )
  {
    try
    {
      ::xsd::cxx::xml::dom::auto_ptr< ::xercesc::DOMDocument > d (
        ::xsd::cxx::xml::dom::serialize< char > (
          "preferences",
          "",
          m, f));

      ::cxml::preferences (*d, s, f);
      return d;
    }
    catch (const ::xsd::cxx::xml::dom::mapping< char >& e)
    {
      throw ::xsd::cxx::tree::no_namespace_mapping< char > (e.name ());
    }
    catch (const ::xsd::cxx::xml::dom::xsi_already_in_use&)
    {
      throw ::xsd::cxx::tree::xsi_already_in_use< char > ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const ConfigurationXML& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // language
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "language",
          e));

      s << i.language ();
    }

    // keyboard
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "keyboard",
          e));

      s << i.keyboard ();
    }

    // audio
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "audio",
          e));

      s << i.audio ();
    }

    // video
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "video",
          e));

      s << i.video ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const keyboard& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // movenorth
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "movenorth",
          e));

      s << i.movenorth ();
    }

    // movesouth
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "movesouth",
          e));

      s << i.movesouth ();
    }

    // moveeast
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "moveeast",
          e));

      s << i.moveeast ();
    }

    // movewest
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "movewest",
          e));

      s << i.movewest ();
    }

    // take
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "take",
          e));

      s << i.take ();
    }

    // jump
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "jump",
          e));

      s << i.jump ();
    }

    // doughnut
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "doughnut",
          e));

      s << i.doughnut ();
    }

    // takeandjump
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "takeandjump",
          e));

      s << i.takeandjump ();
    }

    // swap
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "swap",
          e));

      s << i.swap ();
    }

    // pause
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "pause",
          e));

      s << i.pause ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const audio& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // fx
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "fx",
          e));

      s << i.fx ();
    }

    // music
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "music",
          e));

      s << i.music ();
    }

    // room tunes
    //
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "roomtunes",
          e));

      s << i.roomtunes ();
    }
  }

  void
  operator<< (::xercesc::DOMElement& e, const video& i)
  {
    e << static_cast< const ::xml_schema::type& > (i);

    // fullscreen
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "fullscreen",
          e));

      s << i.fullscreen ();
    }

    // shadows
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "shadows",
          e));

      s << i.shadows ();
    }

    // background
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "background",
          e));

      s << i.background ();
    }

    // graphics
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "graphics",
          e));

      s << i.graphics ();
    }
  }
}

#include <xsd/cxx/post.hxx>

