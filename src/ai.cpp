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

  // This switch statment checks the last key pressed, and goes through different cases to produce a different effect
  switch( lastKeypress ) {

    { // Movement
      case TK_LEFT: (actor -> x)--;
        break;
      case TK_RIGHT: (actor -> x)++;
        break;
      case TK_UP: (actor -> y)--;
        break;
      case TK_DOWN: (actor -> y)++;
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

  return true;
}
