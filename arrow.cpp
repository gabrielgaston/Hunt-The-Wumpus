#include "arrow.hpp"

#include <iostream>

// Arrow implementation

void arrow::percept()
{
    // Just to override the percept function of the event class.
}

bool arrow::encounter(player& p)
{
    std::cout << "You pick up an arrow";
    p.obtain_arrow();
    return true;
}

void arrow::print()
{
    std::cout << "A";
}

arrow* arrow::clone()
{
    return new arrow(*this);
}

bool arrow::gets_shot(player& p)
{
    // Just for override purposes.
    return false;
}