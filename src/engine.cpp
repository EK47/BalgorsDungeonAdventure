#include "main.hpp"

/*
 * ENGINE FILE
 *
 * The engine is the core of the game. There is generally only one running, but it is still a class because I wanted it to be.
 *
 */

Engine::Engine()
{
	// Opens the terminal
	terminal_open();
	// Alters some default terminal settings
	terminal_set( "window : title=\"Balgor's Dungeon Adventure\", size=120x50;" );
	// Default foreground color is white
	terminal_color( color_from_name("white") );
	// This is the map.
	map = std::make_shared<Map>( 120, 40 );
	// This is the GUI that displays player info and event logs.
	gui = std::make_shared<Gui>();
	// Creates an actor that will act as the player of the game. 0x0040 is Unicode for '@'
	hero = std::make_shared<Actor>( 1, 1, 0x0040, "Balgor", "red" );
	// This creates the AI for the hero. All actors have no AI by default.
	hero -> ai = std::make_unique<PlayerAI>();
}

Engine::~Engine()
{

}

bool Engine::update()
{

	lastKeypress = terminal_read();

	hero -> update( hero );

	return true;
}

bool Engine::render()
{

	map -> render();

	gui -> render();

	hero -> render();

	return true;
}
