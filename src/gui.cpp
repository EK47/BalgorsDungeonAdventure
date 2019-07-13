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
      terminal_color( color_from_name("brown") );
      terminal_bkcolor( color_from_name("transparent") );
      terminal_put( x, 40, 0x003D );
  }

  BresenhamLineDrawer lineTest;
  lineTest.recalculate( Point( 100, 47 ), Point( 50, 43 ) );
  //Point nextPoint( 0, 0 );

  for( int i = 0; i < lineTest.setSize; ++i )
  {
    //lineTest.step( nextPoint );
    terminal_color( color_from_name("white") );
    terminal_bkcolor( color_from_name("white") );
    //terminal_put( nextPoint.x, nextPoint.y, 0x004F );
  }
}
