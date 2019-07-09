#include "main.hpp"

Engine::Engine() {
    // Opens the terminal
	terminal_open();
	// Default foreground color is white
	terminal_color( color_from_name("white") );
    // Creates an actor that will act as the player of the game. 0x0040 is Unicode for '@'
	hero = std::make_shared<Actor>( 0, 0, 0x0040, "Balgor", "red" );
    // This creates the AI for the hero. All actors have no AI by default.
    hero -> ai = std::make_unique<PlayerAI>();
}

Engine::~Engine() {

}

bool Engine::update() {

        lastKeypress = terminal_read();

        hero -> update( hero );

        return true;
}

bool Engine::render() {

    // This is the divide between the GUI and the map
    for( int x = 0; x < 120; ++x )
    {
        // 0x0335 is Unicode for '-'
        terminal_put( x, 39, 0x0335 );
    }

    // If you put the print statements before the movement check, then the message follows the character with delay
	terminal_print( hero -> x + 2, hero -> y, (hero -> name).data() );
	terminal_print( hero -> x + 2 + (hero -> name).length(), hero -> y, ( std::string("\'s eyes are [color=") + hero -> color + std::string("]glowing[/color].") ).c_str() );

    hero -> render();

    return true;
}