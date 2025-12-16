#include "escape_rope.hpp"
#include <iostream>
// Escape rope implementation

void escape_rope::percept()
{
    // Just so it overrides the function from the event class.
}

bool escape_rope::encounter(player& p)
{
    std::cout << "You attempt to climb the escape rope..." << '\n';
    p.move_to_escape_rope();
    if(p.has_gold())
    {
        std::cout << "You escape with the gold!" << '\n';
    }
    else
    {
        std::cout << "You seem to be missing something..." << '\n';
    }
    return false;
}

void escape_rope::print()
{
    std::cout << "R";
}

escape_rope* escape_rope::clone()
{
    return new escape_rope(*this);
}

bool escape_rope::gets_shot(player& p)
{
    // Just for override purposes.
    return false;
}