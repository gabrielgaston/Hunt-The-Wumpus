#ifndef PLAYER_HPP
#define PLAYER_HPP

class player
{
    private:
        int row;
        int col;
        int arrows;
        bool alive;
        bool gold;
        bool confused;
        bool killed_wumpus;
        bool at_escape_rope;
        

    public:
        /*
         * Function: get_row
         * Description: Retrieves the player's current row position.
         * Parameters: None.
         * Returns: int - The row index of the player.
         * Side effects: None.
         */
        int get_row();

        /*
         * Function: get_col
         * Description: Retrieves the player's current column position.
         * Parameters: None.
         * Returns: int - The column index of the player.
         * Side effects: None.
         */
        int get_col();

        /*
         * Function: set_row
         * Description: Sets the player's row position.
         * Parameters: int row - The new row index to assign to the player.
         * Returns: void
         * Side effects: Modifies the player's row position.
         */
        void set_row(int row);

        /*
         * Function: set_col
         * Description: Sets the player's column position.
         * Parameters: int col - The new column index to assign to the player.
         * Returns: void
         * Side effects: Modifies the player's column position.
         */
        void set_col(int col);

        /*
         * Function: kill_player
         * Description: Sets the player's status to dead by marking them as not alive.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's alive status to false.
         */
        void kill_player();

        /*
         * Function: is_alive
         * Description: Returns the player's current alive status.
         * Parameters: None
         * Returns: bool - true if the player is alive, false if the player is dead.
         * Side effects: None.
         */
        bool is_alive() const;

        /*
         * Function: player
         * Description: Constructor for the player class, initializing the player's attributes.
         * Parameters: None
         * Returns: void
         * Side effects: Initializes player attributes such as position, alive status, and game-related variables.
         */
        player();

        /*
         * Function: move_up
         * Description: Moves the player up by decrementing their row position.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's row position by decreasing it by one.
         */
        void move_up();
        
        /*
         * Function: move_left
         * Description: Moves the player left by decrementing their column position.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's column position by decreasing it by one.
         */
        void move_left();

        /*
         * Function: move_right
         * Description: Moves the player right by incrementing their column position.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's column position by increasing it by one.
         */
        void move_right();

        /*
         * Function: move_down
         * Description: Moves the player down by incrementing their row position.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's row position by increasing it by one.
         */
        void move_down();

        /*
         * Function: obtain_gold
         * Description: Sets the player's gold status to true, indicating they have obtained gold.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's gold status to true.
         */
        void obtain_gold();

        /*
         * Function: has_gold
         * Description: Returns the player's current gold status.
         * Parameters: None
         * Returns: bool - true if the player has gold, false otherwise.
         * Side effects: None
         */
        bool has_gold() const;

        /*
         * Function: confuse
         * Description: Sets the player's confusion status to true, indicating they are confused.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's confused status to true.
         */
        void confuse();

        /*
         * Function: unconfuse
         * Description: Resets the player's confusion status to false, indicating they are no longer confused.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's confused status to false.
         */
        void unconfuse();

        /*
         * Function: is_confused
         * Description: Returns the player's current confusion status.
         * Parameters: None
         * Returns: bool - true if the player is confused, false otherwise.
         * Side effects: None
         */
        bool is_confused() const;

        /*
         * Function: has_killed_wumpus
         * Description: Returns the status on if the player has killed the wumpus.
         * Parameters: None
         * Returns: bool - true if player has killed wumpus, false otherwise.
         * Side effects: None
         */
        bool has_killed_wumpus() const;

        /*
         * Function: has_arrows
         * Description: Checks if the player has any arrows remaining.
         * Parameters: None
         * Returns: bool - true if the player has more than 0 arrows, false otherwise.
         * Side effects: None.
         */
        bool has_arrows() const;

        /*
         * Function: num_arrows
         * Description: Returns the number of arrows the player currently has.
         * Parameters: None
         * Returns: int - The number of arrows the player has.
         * Side effects: None.
         */
        int num_arrows() const;

        /*
         * Function: use_arrow
         * Description: Decreases the number of arrows the player has by one, if they have any arrows remaining.
         * Parameters: None
         * Returns: void
         * Side effects: Decrements the player's arrow count if the player has arrows.
         */
        void use_arrow();

        /*
         * Function: obtain_arrow
         * Description: Increases the number of arrows the player has by one.
         * Parameters: None
         * Returns: void
         * Side effects: Increments the player's arrow count by one.
         */
        void obtain_arrow();

        /*
         * Function: is_at_escape_rope
         * Description: Checks if the player is currently at the escape rope.
         * Parameters: None
         * Returns: bool - true if the player is at the escape rope, false otherwise.
         * Side effects: None.
         */
        bool is_at_escape_rope() const;

        /*
         * Function: move_from_escape_rope
         * Description: Sets the player's escape rope status to false, indicating they are no longer at the escape rope.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's escape rope status to false.
         */
        void move_from_escape_rope();

        /*
         * Function: move_to_escape_rope
         * Description: Sets the player's escape rope status to true, indicating they are at the escape rope.
         * Parameters: None
         * Returns: void
         * Side effects: Modifies the player's escape rope status to true.
         */
        void move_to_escape_rope();

        /*
         * Function: shoots_wumpus
         * Description: Player shoots the wumpus so it updates the boolean killed_wumpus.
         * Parameters: None
         * Returns: None
         * Side effects: Updates killed_wumpus to true.
         */
        void shoots_wumpus();
};

#endif
