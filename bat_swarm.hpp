#ifndef BAT_SWARM_HPP
#define BAT_SWARM_HPP

#include "event.hpp"
// Bat Swarm interface

class bat_swarm : public event
{
    private:

    public:

        /*
         * Function: percept
         * Description: Outputs a message indicating the sound of screeching, signaling the presence of a bat swarm.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the message "You hear screeching." to the console.
         */
        virtual void percept();

        /*
         * Function: encounter
         * Description: Handles the encounter with a bat swarm, which causes the player to become confused.
         * Parameters: player& p - The player encountering the bat swarm.
         * Returns: bool - false.
         * Side effects: Outputs a message to the console and calls confuse on the player to set their confused status to true.
         */
        virtual bool encounter(player& p);

        /*
         * Function: print
         * Description: Prints a representation of the bat swarm on the console.
         * Parameters: None
         * Returns: void
         * Side effects: Outputs the character "B" to the console to represent the bat swarm.
         */
        virtual void print();

        /*
         * Function: gets_shot
         * Description: Overrides the gets_shot function from the event class. No specific functionality is implemented here.
         * Parameters: player& p - The player who shot.
         * Returns: bool - false.
         * Side effects: None.
         */
        virtual bool gets_shot(player& p);

        /*
         * Function: clone
         * Description: Creates a new instance of the bat_swarm object as a copy of the current one.
         * Parameters: None
         * Returns: bat_swarm* - A pointer to the newly created bat_swarm object.
         * Side effects: Allocates memory for a new bat_swarm object.
         */
        virtual bat_swarm* clone();
};

#endif
