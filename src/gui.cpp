#include "main.hpp"

/*
 * GUI FILE
 *
 * This is the GUI. The GUI is everything that isn't the environment and all things in it. This handles the log,
 * stats, and inventory.
 *
 */

Gui::Gui()
{

}

Gui::~Gui()
{

}

void Gui::render()
{
  // This is the divide between the GUI and the map
  for( int x = 0; x < 120; ++x )
  {
      // 0x003D is Unicode for '='
      terminal_put( x, 40, 0x003D );
  }
}
