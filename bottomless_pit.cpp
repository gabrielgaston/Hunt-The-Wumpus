#include "bottomless_pit.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

// Bottomless Pit implementation

void bottomless_pit::percept()
{
    std::cout << "You feel a breeze" << '\n';
}

bool bottomless_pit::encounter(player& p)
{
    std::cout << "You reach a bottomless pit and try not to fall in..." << '\n';
    int rand_kill = std::rand() % 4;
    if(rand_kill == 0)
    {
        std::cout << "You fell in the bottomless pit." << '\n';
        p.kill_player();
    }
    return false;
}

void bottomless_pit::print()
{
    std::cout << "P";
}

bottomless_pit* bottomless_pit::clone()
{
    return new bottomless_pit(*this);
}

bool bottomless_pit::gets_shot(player& p)
{
    // Just for override purposes.
    return false;
}