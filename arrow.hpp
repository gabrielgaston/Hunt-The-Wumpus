#ifndef ARROW_HPP
#define ARROW_HPP

#include "event.hpp"
// Arrow interface
class arrow : public event
{
    private:

    public:

        /*
         * Function: percept
         * Description: Overrides the percept function from the event class. No specific functionality implemented here.
         * Parameters: None
         * Returns: void
         * Side effects: None.
         */
        virtual void percept();

        /*
         * Function: encounter
         * Description: Handles the encounter when the player picks up an arrow. The player receives the arrow and a message is displayed.
         * Parameters: player& p - The player encountering the arrow.
         * Returns: bool - true
         * Side effects: Calls obtain_arrow on the player and outputs a message to the console.
         */
        virtual bool encounter(player& p);

        /*
         * Function: print
         * Description: Prints a representation of the arrow on the console.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the character "A" to the console to represent the arrow.
         */
        virtual void print();

        /*
         * Function: clone
         * Description: Creates a new instance of the arrow object as a copy of the current one.
         * Parameters: None
         * Returns: arrow* - A pointer to the newly created arrow object.
         * Side effects: Allocates memory for a new arrow object.
         */
        virtual arrow* clone();

        /*
         * Function: gets_shot
         * Description: Overrides the gets_shot function from the event class. No specific functionality is implemented here.
         * Parameters: player& p - The player.
         * Returns: bool.
         * Side effects: None.
         */
        virtual bool gets_shot(player& p);
};

#endif
