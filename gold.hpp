#ifndef GOLD_HPP
#define GOLD_HPP

#include "event.hpp"
// Gold interface
class gold : public event 
{
    private:

    public:

        /*
         * Function: percept
         * Description: Outputs a message indicating the player stubbing their toe on something heavy, signaling the presence of gold.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the message "You stub your toe on something heavy." to the console.
         */
        virtual void percept();

        /*
         * Function: encounter
         * Description: Handles the encounter with gold. The player picks up the gold and prepares to escape with it.
         * Parameters: player& p - The player.
         * Returns: bool - true.
         * Side effects: Outputs a message to the console and calls obtain_gold on the player to update their status.
         */
        virtual bool encounter(player& p);

        /*
         * Function: print
         * Description: Prints a representation of the gold on the console.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the character "G" to the console to represent the gold.
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
         * Description: Creates a new instance of the gold object as a copy of the current one.
         * Parameters: None
         * Returns: gold* - A pointer to the newly created gold object.
         * Side effects: Allocates memory for a new gold object.
         */
        virtual gold* clone();
};

#endif
