#include <iostream>
#include <ctime>
#include <cstdlib>

#include "game.hpp"
#include "gold.hpp"
#include "bat_swarm.hpp"
#include "bottomless_pit.hpp"
#include "wumpus.hpp"
#include "escape_rope.hpp"
#include "arrow.hpp"

// game implementation

game::game(int width, int height, bool debug, player& p) :
		width(width),
		height(height),
		debug(debug),
		rooms(height, std::vector<room>(width)) 
{
	int rand_col {};
	int rand_row {};
	for(int i = 0; i < 9;)
	{
		rand_col = std::rand() % width; 
		rand_row = std::rand() % height;
		if(!(rooms.at(rand_row).at(rand_col).has_event()))
		{
			if (i < 2)
			{
				rooms.at(rand_row).at(rand_col) = room(new bat_swarm());
			}
			else if (i < 4)
			{
				rooms.at(rand_row).at(rand_col) = room(new bottomless_pit());
			}
			else if (i < 5)
			{
				rooms.at(rand_row).at(rand_col) = room(new wumpus());
			}
			else if (i < 6)
			{
				rooms.at(rand_row).at(rand_col) = room(new gold());
			}
			else if (i < 8)
			{
				rooms.at(rand_row).at(rand_col) = room(new arrow());
			}
			else
			{
				rooms.at(rand_row).at(rand_col) = room(new escape_rope());
				p.set_col(rand_col);
				p.set_row(rand_row);
			}
			i++;
		}
	}
}

void game::display_game(player& p) const
{
	std::cout << "\n\nArrows remaining: " << p.num_arrows() << '\n';

	std::string row_border = "+";
	for (int i = 0; i < this->width; ++i) 
	{
		row_border += "--+";
	}

	std::cout << row_border << '\n';
	for (int i = 0; i < this->height; ++i) 
	{ // For each row
		std::cout << "|";
		for (int j = 0; j < this->width; ++j) 
		{ // For each column
			if(p.get_row() == i && p.get_col() == j)
			{
				std::cout << "*";
			}
			else
			{
				std::cout << " ";
			}

			if(!this->debug || !(this->rooms.at(i).at(j).has_event()))
			{
				std::cout << " ";
			}
			else
			{
				this->rooms.at(i).at(j).print();
			}
			
			std::cout << "|";
		}
		std::cout << '\n';
		std::cout << row_border << '\n';
	}

	// Example output: 
	// +--+--+--+--+
	// | P| G| P|  |
	// +--+--+--+--+
	// |  | W|  | B|
	// +--+--+--+--+
	// | A|  |  |  |
	// +--+--+--+--+
	// |*R| B| A|  |
	// +--+--+--+--+
}

bool game::check_win(player& p) const
{
	if(p.has_killed_wumpus() || (p.has_gold() && p.is_at_escape_rope()))
	{
		return true;
	}
	return false;
}

bool game::check_lose(player& p) const
{
	return !(p.is_alive());
}

bool game::is_direction(char c) 
{
	return c == 'w' ||
		c == 'a' ||
		c == 's' ||
		c == 'd';
}

char game::to_lower(char direction) 
{
	if (direction >= 'A' && direction <= 'Z') 
	{
		return direction + ('a' - 'A');
	}
	return direction;
}

bool game::can_move_in_direction(char direction, player& p) 
{
	if(direction == 'w')
	{
		if(p.get_row() == 0)
		{
			return false;
		}
	}
	else if(direction == 'a')
	{
		if(p.get_col() == 0)
		{
			return false;
		}
	}
	else if(direction == 's')
	{
		if(p.get_row() == (height -1))
		{
			return false;
		}
	}
	else
	{
		if(p.get_col() == (width -1))
		{
			return false;
		}
	}
	return true;
}

bool game::is_valid_action(char action, player& p) 
{
	if (this->is_direction(action)) 
	{
		char direction = action;
		return this->can_move_in_direction(direction, p);
	} 
	else if (action == 'f') 
	{
		return p.has_arrows();
	}
	return false;
}

void game::print_action_error(char action) 
{
	if (this->is_direction(action)) 
	{
		std::cout << "You can't move in that direction!\n" << '\n';
	} 
	else if (action == 'f') 
	{
		std::cout << "You're out of arrows!\n" << '\n';
	} 
	else 
	{
		std::cout << "\nThat's an invalid input!\n" << '\n';
	}
}

char game::get_player_action(player& p) 
{
	char action;
	bool first = true;
	do 
	{
		if (!first) 
		{
			char previous_action = action;
			this->print_action_error(previous_action);
		}
		first = false;

		std::cout << "\n\nWhat would you like to do?\n" << '\n';
		std::cout << "w: move up" << '\n';
		std::cout << "a: move left" << '\n';
		std::cout << "s: move down" << '\n';
		std::cout << "d: move right" << '\n';
		std::cout << "f: fire an arrow" << '\n';

		std::cin >> action;
		action = this->to_lower(action);
	} 
	while (!this->is_valid_action(action, p));

	return action;
}

char game::get_arrow_fire_direction(player& p) 
{
	char direction;
	bool first = true;
	do 
	{
		if (!first)
		{
			std::cout << "\nThat's an invalid input!\n" << '\n';
		}
		first = false;

		std::cout << "\n\nWhat direction would you like to fire the arrow?\n" << '\n';
		std::cout << "w: up" << '\n';
		std::cout << "a: left" << '\n';
		std::cout << "s: down" << '\n';
		std::cout << "d: right" << '\n';

		std::cin >> direction;

		if(p.is_confused()) // If player is confused it will choose a random direction instead.
		{
			direction = randomize_direction(p);
		}

		direction = this->to_lower(direction);
	} 
	while (!this->is_direction(direction));

	return direction;
}

char game::randomize_direction(player& p)
{
	int rand_direction = rand() % 4;
	char direction {};
	if(rand_direction == 0)
	{
		direction = 'w';
		if(!is_valid_action('w', p))
		{
			direction = 's';
		}
	}
	else if(rand_direction == 1)
	{
		direction = 'a';
		if(!is_valid_action('a', p))
		{
			direction = 'd';
		}
	}
	else if(rand_direction == 2)
	{
		direction = 's';
		if(!is_valid_action('s', p))
		{
			direction = 'w';
		}
	}
	else
	{
		direction = 'd';
		if(!is_valid_action('d', p))
		{
			direction = 'a';
		}
	}
	return direction;
}

void game::move(char direction, player& p) 
{
	if(p.is_confused())
	{
		direction = randomize_direction(p);
	}

	if (direction == 'w') 
	{
		move_up(p);
	} 
	else if (direction == 'a') 
	{
		move_left(p);
	} 
	else if (direction == 's') 
	{
		move_down(p);
	} 
	else 
	{
		move_right(p);
	}
}

void game::move_up(player& p)
{
	p.move_up();
}

void game::move_left(player& p)
{
	p.move_left();
}

void game::move_down(player& p)
{
	p.move_down();
}

void game::move_right(player& p)
{
	p.move_right();
}

void game::fire_arrow(char direction, player& p) 
{
	if (direction == 'w') 
	{
		fire_arrow_up(p);
	} 
	else if (direction == 'a') 
	{
		fire_arrow_left(p);
	} 
	else if (direction == 's') 
	{
		fire_arrow_down(p);
	} 
	else 
	{
		fire_arrow_right(p);
	}

	p.use_arrow();
}

void game::fire_arrow_up(player& p)
{
	int check_row = p.get_row() - 1;
	for(int i = 0; i < 2; i++)
	{
		if(check_row > 0)
		{
			check_row--;
			if(rooms.at(check_row).at(p.get_col()).has_event())
			{
				rooms.at(check_row).at(p.get_col()).gets_shot(p);
			}
		}
	}
}

void game::fire_arrow_left(player& p)
{
	int check_col = p.get_col() - 1;
	for(int i = 0; i < 2; i++)
	{
		if(check_col > 0)
		{
			check_col--;
			if(rooms.at(p.get_row()).at(check_col).has_event())
			{
				rooms.at(p.get_row()).at(check_col).gets_shot(p);
			}
		}
	}
}

void game::fire_arrow_down(player& p)
{
	int check_row = p.get_row() + 1;
	for(int i = 0; i < 2; i++)
	{
		if(check_row < height - 1)
		{
			check_row++;
			if(rooms.at(check_row).at(p.get_col()).has_event())
			{
				rooms.at(check_row).at(p.get_col()).gets_shot(p);
			}
		}
	}
}

void game::fire_arrow_right(player& p)
{
	int check_col = p.get_col() + 1;
	for(int i = 0; i < 2; i++)
	{
		if(check_col < width - 1)
		{
			check_col++;
			if(rooms.at(p.get_row()).at(check_col).has_event())
			{
				rooms.at(p.get_row()).at(check_col).gets_shot(p);
			}
		}
	}
}

void game::play_game(player& p)
{
	while (!this->check_win(p) && !this->check_lose(p)) 
	{
		// Print game board.
		this->display_game(p);

		// Displays the percepts for events bordering the player.
		this->percepts(p);

		// Ask player for their action.
		char action = this->get_player_action(p);

		// Process action
		if (this->is_direction(action)) 
		{
			// W/A/S/D = move player.
			char direction = action;
			this->move(direction, p);
		} 
		else 
		{
			// F = prompt for arrow fire direction and fire arrow.
			char direction = this->get_arrow_fire_direction(p);
			this->fire_arrow(direction, p);
		}
		this->tick(p);
		encounter(p);
	}
	if(this->check_lose(p))
	{
		std::cout << "\n\n\nGAME OVER" << '\n';
	}
	else
	{
		std::cout << "\n\n\nVICTORY" << '\n';
	}
}

void game::percepts(player& p)
{
	int player_row = p.get_row();
	int player_col = p.get_col();
	// Checks above player.
	if(player_row > 0)
	{
		if(rooms.at(player_row-1).at(player_col).has_event())
		{
			rooms.at(player_row-1).at(player_col).print_percept();
		}
	}
	// Checks below player.
	if(player_row < height-1)
	{
		if(rooms.at(player_row+1).at(player_col).has_event())
		{
			rooms.at(player_row+1).at(player_col).print_percept();
		}
	}
	// Checks to left of player.
	if(player_col > 0)
	{ 
		if(rooms.at(player_row).at(player_col-1).has_event())
		{
			rooms.at(player_row).at(player_col-1).print_percept();
		}
	}
	// Checks to right of player.
	if(player_col < width-1)
	{
		if(rooms.at(player_row).at(player_col+1).has_event())
		{
			rooms.at(player_row).at(player_col+1).print_percept();
		}
	}
}

void game::tick(player& p)
{
	p.unconfuse(); // Resets confusion status each turn.
}

void game::encounter(player& p)
{
	// Sets the boolean if the player is at the escape rope to false.
	p.move_from_escape_rope(); 

	// Makes sure there is an event at the place where the player is before calling it.
	if(rooms.at(p.get_row()).at(p.get_col()).has_event())
	{
		rooms.at(p.get_row()).at(p.get_col()).encounter(p);
	}
}