#ifndef BOTTOMLESS_PIT_HPP
#define BOTTOMLESS_PIT_HPP

#include "event.hpp"
// Bottomless Pit interface

class bottomless_pit : public event
{
    private:

    public:

        /*
         * Function: percept
         * Description: Outputs a message indicating the sensation of a breeze, signaling the presence of a bottomless pit.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the message "You feel a breeze" to the console.
         */
        virtual void percept();

        /*
         * Function: encounter
         * Description: Handles the encounter with a bottomless pit. The player has a chance to fall in and be killed.
         * Parameters: player& p - The player.
         * Returns: bool - false.
         * Side effects: Outputs messages to the console and may call kill_player on the player if they fall into the pit.
         */
        virtual bool encounter(player& p);

        /*
         * Function: print
         * Description: Prints a representation of the bottomless pit on the console.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the character "P" to the console to represent the bottomless pit.
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
         * Description: Creates a new instance of the bottomless_pit object as a copy of the current one.
         * Parameters: None
         * Returns: bottomless_pit* - A pointer to the newly created bottomless_pit object.
         * Side effects: Allocates memory for a new bottomless_pit object.
         */
        virtual bottomless_pit* clone();
};

#endif
