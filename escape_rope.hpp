#ifndef ESCAPE_ROPE_HPP
#define ESCAPE_ROPE_HPP

#include "event.hpp"
// Escape rope interface

class escape_rope : public event
{
    private:

    public:

        /*
         * Function: percept
         * Description: Overrides the percept function from the event class. No specific functionality is implemented here.
         * Parameters: None
         * Returns: void
         * Side effects: None.
         */
        virtual void percept();

        /*
         * Function: encounter
         * Description: Handles the encounter with the escape rope. 
                        The player attempts to climb the rope and either escapes with the gold or realizes something is missing.
         * Parameters: player& p - The player.
         * Returns: bool - false.
         * Side effects: Outputs messages to the console and calls move_to_escape_rope on the player.
         */
        virtual bool encounter(player& p);

        /*
         * Function: print
         * Description: Prints a representation of the escape rope on the console.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the character "R" to the console to represent the escape rope.
         */
        virtual void print();

        /*
         * Function: gets_shot
         * Description: Overrides the gets_shot function from the event class. No specific functionality is implemented here.
         * Parameters: player& p - The player.
         * Returns: bool - false.
         * Side effects: None.
         */
        virtual bool gets_shot(player& p);

        /*
         * Function: clone
         * Description: Creates a new instance of the escape_rope object as a copy of the current one.
         * Parameters: None
         * Returns: escape_rope* - A pointer to the newly created escape_rope object.
         * Side effects: Allocates memory for a new escape_rope object.
         */
        virtual escape_rope* clone();
};

#endif
