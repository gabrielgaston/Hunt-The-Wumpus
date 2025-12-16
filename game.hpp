#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "room.hpp"
#include "player.hpp"

// game interface
class game 
{
private:
	std::vector<std::vector<room>> rooms; // vector of the game grid
	int width;				// width of the game grid
	int height;				// height of the game grid
	bool debug;				// debug mode or not


public:
	/*
	 * Function: Constructor
	 * Description: Constructs game object with a grid matching the given
	 * 		width and height
	 * Parameters:
	 * 		width (int): Width of the grid
	 * 		height (int): Height of the grid
	 * 		debug (bool): Whether or not debug mode should be enabled
	 */
	game(int width, int height, bool debug, player& p);

	/*
	 * Function: display_game
	 * Description: Displays the game grid in the terminal
	 */
	void display_game(player& p) const;

	/*
	 * Function: check_win
	 * Description: Determines whether the player has won the game
	 * Returns (bool): True if the player has won, false otherwise
	 */
	bool check_win(player& p) const;

	/*
	 * Function: check_lose
	 * Description: Determines whether the player has lost the game
	 * Returns (bool): True if the player has lost, false otherwise
	 */
	bool check_lose(player& p) const;

	/*
	 * Function: is_direction
	 * Description: Returns true if the given character is a valid direction
	 * 		character (w/a/s/d) and false otherwise
	 * Parameters:
	 * 		c (char): The character to check
	 * Returns (bool): Boolean indicating whether the character is a valid
	 * 		direction character (w/a/s/d)
	 */
	bool is_direction(char c);

	/*
	 * Function: to_lower
	 * Description: Converts a given character to lowercase. Used to standardize
	 * 		a user's character input.
	 * Parameters:
	 * 		direction (char): Character to convert to lowercase
	 * Returns (char): Character converted to lowercase
	 */
	char to_lower(char direction);

	/*
	 * Function: can_move_in_direction
	 * Description: Determines whether the player can move in the given
	 * 		direction, based on their current location and the size of the
	 * 		grid.
	 * Parameters:
	 * 		direction (char): Direction the player wishes to move in
	 * Returns (bool): True if the player can move in the given direction
	 * 		without moving off the grid. False otherwise.
	 */
	bool can_move_in_direction(char direction, player& p);

	/*
	 * Function: is_valid_action
	 * Description: Determines whether the given action is valid.
	 * Parameters:
	 * 		action (char): Action the player wishes to perform.
	 * Returns (bool): True if the requested action is valid. False otherwise.
	 */
	bool is_valid_action(char action, player& p);

	/*
	 * Function: print_action_error
	 * Description: Prints a clear error message associated with the user's
	 * 		provided invalid action
	 * Parameters:
	 * 		action (char): Invalid action that the user requested
	 */
	void print_action_error(char action);

	/*
	 * Function: get_player_action
	 * Description: Prompts the player for their action for the turn and
	 * 		returns it as a char (w, a, s, d, or f). If the player enters
	 * 		an invalid action, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid action provided by the player.
	 */
	char get_player_action(player& p);

	/*
	 * Function: get_arrow_fire_direction
	 * Description: Prompts the player for the direction they want to fire an
	 * 		arrow (w, a, s, or d) and returns it as a char. If the player enters
	 * 		an invalid direction, this function reprompts until a valid one is
	 * 		provided.
	 * Returns (char): The valid direction provided by the player.
	 */
	char get_arrow_fire_direction(player& p);

	/*
	 * Function: move_up
	 * Description: Moves the player up one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_up(player& p);

	/*
	 * Function: move_down
	 * Description: Moves the player down one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_down(player& p);

	/*
	 * Function: move_left
	 * Description: Moves the player left one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_left(player& p);

	/*
	 * Function: move_right
	 * Description: Moves the player right one grid space
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move_right(player& p);

	/*
	 * Function: move
	 * Description: Moves the player in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to move the player (a for
	 * 			west, s for south, d for east, w for north).
	 * Pre-condition: Player is capable of moving in this direction (without
	 * 		hitting the edge of the board)
	 * Post-condition: Player is moved accordingly.
	 */
	void move(char direction, player& p);

	/*
	 * Function: fire_arrow_up
	 * Description: Fires an arrow upward
	 * Post-condition: Arrow is fired upward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_up(player& p);

	/*
	 * Function: fire_arrow_down
	 * Description: Fires an arrow downward
	 * Post-condition: Arrow is fired downward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_down(player& p);

	/*
	 * Function: fire_arrow_left
	 * Description: Fires an arrow leftward
	 * Post-condition: Arrow is fired leftward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_left(player& p);

	/*
	 * Function: fire_arrow_right
	 * Description: Fires an arrow rightward
	 * Post-condition: Arrow is fired rightward. Wumpus is killed if hit / moves
	 * 		if missed.
	 */
	void fire_arrow_right(player& p);

	/*
	 * Function: fire_arrow
	 * Description: Fires an arrow in the direction specified by the given
	 * 		character
	 * Parameters:
	 * 		direction (char): Direction in which to fire arrow (a for
	 * 			west, s for south, d for east, w for north).
	 * Post-condition: Arrow is fired. Wumpus is killed if hit and moves if
	 * 		missed.
	 */
	void fire_arrow(char direction, player& p);

	/*
	 * Function: play_game
	 * Description: Runs one full iteration of the game
	 */
	void play_game(player& p);

	/*
	 * Function: tick
	 * Description: Advances the game state by updating the player's status for the current turn.
	 * Parameters: player& p - Reference to the player object to update.
	 * Returns: void
	 * Side effects: Modifies the player's confusion status.
	 */
	void tick(player& p);

	/*
	 * Function: percepts
	 * Description: Checks for events in adjacent rooms and prints percepts if any events are present.
	 * Parameters: player& p - Reference to the player object to determine the current position.
	 * Returns: void
	 * Side effects: Outputs percept messages to the console if events are detected in adjacent rooms.
	 */
	void percepts(player& p);

	/*
	 * Function: encounter
	 * Description: Handles the player's encounter with an event in their current room.
	 * Parameters: player& p - Reference to the player object to update their status.
	 * Returns: void
	 * Side effects: Modifies the player's escape rope status and triggers an event if present in the current room.
	 */
	void encounter(player& p);

	/*
	 * Function: randomize_direction
	 * Description: Randomly selects a movement direction for the player, ensuring the chosen direction is valid.
	 * Parameters: player& p - Reference to the player object to check for valid movement.
	 * Returns: char - The selected direction ('w', 'a', 's', or 'd').
	 * Side effects: None.
	 */
	char randomize_direction(player& p);
};
#endif
