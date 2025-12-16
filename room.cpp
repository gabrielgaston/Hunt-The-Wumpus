#include "room.hpp"

room::room(event* event) : room_event(event){}

room::room() : room_event(nullptr) {}

room::room(const room& exisiting_room)
{
    if(exisiting_room.room_event)
    {
        room_event = exisiting_room.room_event->clone();
    }
    else
    {
        room_event = nullptr;
    }
}

room& room::operator=(const room& exisiting_room)
{
    if(this != &exisiting_room)
    {
        delete room_event;

        if(exisiting_room.room_event)
        {
            room_event = exisiting_room.room_event->clone();
        }
        else
        {
            room_event = nullptr;
        }
    }
    return *this;
}

room::~room()
{
    if(room_event)
    {
        delete room_event;
    }
}

bool room::has_event() const
{
    return this->room_event != nullptr;
}

void room::print() const
{
    if(room_event != nullptr)
    {
        room_event->print();
    }
}

void room::print_percept() const
{
    if(room_event != nullptr)
    {
        room_event->percept();
    }
}

void room::encounter(player& p)
{
    if(room_event != nullptr)
    {
        bool remove_event = room_event->encounter(p);
        if(remove_event)
        {
            delete room_event;
            room_event = nullptr;
        }
    }
}

void room::gets_shot(player& p)
{
    if(room_event != nullptr)
    {
        bool remove_event = room_event->gets_shot(p);
        if(remove_event)
        {
            delete room_event;
            room_event = nullptr;
        }
    }
}