#include "main.hpp"

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
        
        default:
            break;
    }

    return true;
}