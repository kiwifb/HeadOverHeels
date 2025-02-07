
#include "SaveGame.hpp"

#include "ospaths.hpp"

#include "GameManager.hpp"
#include "ContinueGame.hpp"

using gui::SaveGame;
using gui::ContinueGame;


SaveGame::SaveGame( unsigned int slot )
        : Action( )
        , slot( slot )
{
}

void SaveGame::doAction ()
{
        allegro::emptyKeyboardBuffer();

        if ( slot > 0 )
        {
                GameManager & gameManager = GameManager::getInstance() ;
                bool saved = gameManager.saveGame( ospaths::homePath () + "savegame" + ospaths::pathSeparator () + "saved." + util::number2string( slot ) );
                if ( ! saved )
                        std::cout << "can't save the game as \"" << "saved." << slot << "\"" << std::endl ;
        }

        ContinueGame * game = new ContinueGame( true );
        game->doIt ();
}
