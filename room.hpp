#ifndef ROOM_HPP
#define ROOM_HPP

#include "event.hpp"

// Room interface
class room 
{
	private: 
		event* room_event;
	public:
		/*
		 * Function: room
		 * Description: Constructor for the room class, initializing the room's event.
		 * Parameters: event* event - Pointer to the event associated with the room.
		 * Returns: void
		 * Side effects: Initializes the room_event with the provided event pointer.
		 */
		room(event* event);

		/*
		 * Function: room
		 * Description: Default constructor for the room class, initializing the room's event to nullptr.
		 * Parameters: None
		 * Returns: void
		 * Side effects: Initializes the room_event to nullptr.
		 */
		room();

		room(const room& existing_room);

		room& operator=(const room& existing_room);

		/*
		 * Function: ~room
		 * Description: Destructor for the room class, deleting the associated event if it exists.
		 * Parameters: None
		 * Returns: void
		 * Side effects: Deletes the room_event object if it is not nullptr.
		 */
		~room();

		/*
		 * Function: has_event
		 * Description: Checks if the room has an associated event.
		 * Parameters: None
		 * Returns: bool - true if the room has an event, false otherwise.
		 * Side effects: None.
		 */
		bool has_event() const;

		/*
		 * Function: print
		 * Description: Prints the details of the room's event if it exists.
		 * Parameters: None
		 * Returns: void
		 * Side effects: Calls the print function of the room_event if it is not nullptr.
		 */
		void print() const;

		/*
		 * Function: print_percept
		 * Description: Prints the percept of the room's event if it exists.
		 * Parameters: None
		 * Returns: void
		 * Side effects: Calls the percept function of the room_event if it is not nullptr.
		 */
		void print_percept() const;

		/*
		 * Function: encounter
		 * Description: Handles an encounter between the player and the room's event. If the event is resolved, it deletes the event.
		 * Parameters: player& p - The player.
		 * Returns: void
		 * Side effects: If the event is resolved, deletes the room_event and sets it to nullptr.
		 */
		void encounter(player& p);

		/*
		 * Function: gets_shot
		 * Description: Handles the scenario where the player shoots in the room. If the event is resolved, it deletes the event.
	  	 * Parameters: player& p - The player.
		 * Returns: void
		 * Side effects: If the event is resolved, deletes the room_event and sets it to nullptr.
		 */
		void gets_shot(player& p);
};

#endif
