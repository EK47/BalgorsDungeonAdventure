#include "main.hpp"

// Global variables are evil and all, but this keypress is something necessary for all functions. It needs to be global.
int lastKeypress { TK_INPUT_NONE };

int main() {
	Engine engine;
	while( lastKeypress != TK_ESCAPE ) {
		// This clears the terminal before calculations for the next frame are done
		terminal_clear();
		engine.update();
		engine.render();
		terminal_refresh();
	}

	terminal_close();

	return 0;
}
