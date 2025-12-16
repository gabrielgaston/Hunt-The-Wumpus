#include "gold.hpp"
#include <iostream>
// Gold implementation
void gold::percept()
{
    std::cout << "You stub your toe on something heavy." << '\n';
}

bool gold::encounter(player& p)
{
    std::cout << "You found gold and pick it up. Now it is time to escape with your treasure." << '\n';
    p.obtain_gold();

    return true;
}

void gold::print()
{
    std::cout << "G";
}

gold* gold::clone()
{
    return new gold(*this);
}

bool gold::gets_shot(player& p)
{
    // Just for override purposes.
    return false;
}