#include "main.hpp"

/*
 * AI FILE
 *
 * AI run the intelligent actors in the game.
 *
 */

PlayerAI::PlayerAI() {

}

PlayerAI::~PlayerAI() {

}

bool PlayerAI::update( std::shared_ptr<Actor> actor ) {

  int dx = 0;
  int dy = 0;

  // This switch statment checks the last key pressed, and goes through different cases to produce a different effect
  switch( lastKeypress ) {

    { // Movement

      case TK_LEFT: (dx--);
        break;
      case TK_RIGHT: (dx++);
        break;
      case TK_UP: (dy--);
        break;
      case TK_DOWN: (dy++);
        break;
    }

    { // Test
      case TK_M:
        // If you put the print statements before the movement check, then the message follows the character with delay
        terminal_print( actor -> x + 2, actor -> y, (actor -> name).data() );
        terminal_print( actor -> x + 2 + (actor -> name).length(), actor -> y, ( std::string("\'s eyes are [color=") + actor -> color + std::string("]glowing[/color].") ).c_str() );
        break;
    }

    default:
        break;
  }

  if( ( dx != 0 || dy != 0 ) && engine.map -> walkableAt( actor -> x + dx, actor -> y + dy ) )
  {
    actor -> x += dx;
    actor -> y += dy;
  }

  return true;
}
