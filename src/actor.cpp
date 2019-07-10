#include "main.hpp"

/*
 * ACTOR FILE
 *
 * Actors are anything in the game that has the ability to do stuff. Statues, doors, items, enemies, etc. are all actors
 *
 */

Actor::Actor( int x, int y, char glyph, std::string name, std::string color ) : x(x), y(y), glyph(glyph), name(name), color(color) {

}

Actor::~Actor() {

}

// This manages the AI. If it returns true, that means the AI exists for this actor. Else, not.

bool Actor::update( std::shared_ptr<Actor> actor ) {
  if( ai )
  {
      ai -> update( actor );
      return true;
  }

  return false;
}

bool Actor::render() {
  // This displays the hero
	/*
   * I'm pretty proud of this third argument. The function requires a const char*, but I can't combine a char with two const char*s for
	 * some reason. I wanted to avoid using an extraneous variable, and I managed to come up with this. It converts the const char* literals
   * into strings, then combines it with the char variable. C++ std::strings can absorb non-strings using binary operations, and c_str() converts
	 * the string into a const char*.
   */

  terminal_print( x, y, ( std::string("[color=") + color + std::string("]") + &(glyph) + std::string("[/color]") ).c_str() );

  return true;
}

ActorManager::ActorManager() {

}

ActorManager::~ActorManager() {

}
