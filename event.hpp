#ifndef EVENT_HPP
#define EVENT_HPP

#include "player.hpp"

// Event interface
class event 
{
private:

protected:

// All functions are pure virtual and overriden in each of the derived classes.
public:

	virtual void percept() = 0;

	virtual bool encounter(player& p) = 0;

	virtual void print() = 0;

	virtual bool gets_shot(player& p) = 0;

	virtual ~event() = default;

	virtual event* clone() = 0;
};

#endif
