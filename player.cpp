
#include "player.hpp"

int player::get_row()
{
    return this->row;
}

int player::get_col()
{
    return this->col;
}

void player::set_row(int row)
{
    this->row = row;
}

void player::set_col(int col)
{
    this->col = col;
}

void player::kill_player()
{
    alive = false;
}

bool player::is_alive() const
{
    return this->alive;
}

player::player() : row(0), col(0), alive(true), killed_wumpus(false), arrows(0), at_escape_rope(true), gold(false), confused(false){}

void player::move_up()
{
    this->row--;
}

void player::move_down()
{
    this->row++;
}

void player::move_left()
{
    this->col--;
}

void player::move_right()
{
    this->col++;
}

bool player::has_gold() const
{
    return this->gold;
}

void player::obtain_gold()
{
    this->gold = true;
}

void player::confuse()
{
    this->confused = true;
}

void player::unconfuse()
{
    this->confused = false;
}

bool player::is_confused() const
{
    return this->confused;
}

bool player::has_killed_wumpus() const
{
    return this->killed_wumpus;
}

void player::shoots_wumpus()
{
    this->killed_wumpus = true;
}

bool player::has_arrows() const
{
    return (this->arrows > 0);
}

int player::num_arrows() const
{
    return this->arrows;
}

void player::use_arrow()
{
    if(this->has_arrows())
    {
        this->arrows--;
    }
}

void player::obtain_arrow()
{
    this->arrows++;
}

bool player::is_at_escape_rope() const
{
    return this->at_escape_rope;
}

void player::move_from_escape_rope()
{
    this->at_escape_rope = false;
}

void player::move_to_escape_rope()
{
    this->at_escape_rope = true;
}