#include "bat_swarm.hpp"
#include <iostream>

// Bat Swarm implementation

void bat_swarm::percept()
{
    std::cout << "You hear screeching." << '\n';
}

bool bat_swarm::encounter(player& p)
{
    std::cout << "You encounter a bat swarm. You are now confused." << '\n';
    p.confuse();
    return false;
}

void bat_swarm::print()
{
    std::cout << "B";
}

bat_swarm* bat_swarm::clone()
{
    return new bat_swarm(*this);
}

bool bat_swarm::gets_shot(player& p)
{
    // Just for override purposes.
    return false;
}