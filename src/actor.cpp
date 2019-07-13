#include "main.hpp"

/*
 * ACTOR FILE
 *
 * Actors are anything in the game that has the ability to do stuff. Statues, doors, items, enemies, etc. are all actors
 *
 */

Actor::Actor( int x, int y, char glyph, std::string name, std::string fcolor ) : x(x), y(y), glyph(glyph), name(name), fcolor(fcolor), bcolor("transparent")
{

}

Actor::~Actor()
{

}

// This manages the AI. If it returns true, that means the AI exists for this actor. Else, not.

bool Actor::update( std::shared_ptr<Actor> actor )
{
  if( ai )
  {
      ai -> update( actor );
      return true;
  }

  return false;
}

bool Actor::render()
{
  // This displays the hero

  terminal_color( color_from_name(fcolor.c_str()) );
  terminal_bkcolor( color_from_name(bcolor.c_str()) );
  terminal_put( x, y, glyph );

  return true;
}

ActorManager::ActorManager()
{

}

ActorManager::~ActorManager()
{

}
