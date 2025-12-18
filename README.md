# Hunt the Wumpus (C++)

A terminal-based adventure game inspired by the classic *Hunt the Wumpus*. The player explores a grid of rooms, avoids deadly hazards, collects arrows and gold, and attempts to either slay the Wumpus or escape alive with the treasure.

---

## Gameplay Overview

You control an adventurer navigating a hidden dungeon represented as a 2D grid. Each room may contain a dangerous event or a helpful item. The goal is to **win before you die**.

### Win Conditions

* Kill the Wumpus using an arrow, **or**
* Collect the gold and return to the escape rope

### Lose Conditions

* Fall into a bottomless pit
* Encounter the Wumpus directly

---

## Controls

| Key | Action        |
| --- | ------------- |
| `w` | Move up       |
| `a` | Move left     |
| `s` | Move down     |
| `d` | Move right    |
| `f` | Fire an arrow |

When firing an arrow, you will be prompted for a direction (`w`, `a`, `s`, `d`). Arrows travel up to **two rooms** in the chosen direction.

---

## Events

Each event inherits from a common `event` interface and provides its own percept, encounter behavior, and interaction with arrows.

| Symbol | Event          | Description                                                                |
| ------ | -------------- | -------------------------------------------------------------------------- |
| `W`    | Wumpus         | Instantly kills the player on encounter; can be killed by an arrow         |
| `P`    | Bottomless Pit | Chance to kill the player when entered                                     |
| `B`    | Bat Swarm      | Confuses the player, randomizing movement and arrow direction for one turn |
| `G`    | Gold           | Collectable treasure required for escape victory                           |
| `A`    | Arrow          | Increases the player's arrow count                                         |
| `R`    | Escape Rope    | Exit point; escape succeeds only if gold is collected                      |

---

## Percepts

Players do not see events directly unless debug mode is enabled. Instead, **percepts** are printed when the player is adjacent to an event:

* **Wumpus**: "The hairs stand up on the back of your neck."
* **Pit**: "You feel a breeze."
* **Bats**: "You hear screeching."
* **Gold**: "You stub your toe on something heavy."

---

## Debug Mode

At startup, you may enable debug mode. When enabled:

* All event symbols are visible on the map
* Useful for testing and debugging

---

## Program Structure

* `main.cpp` - Program entry point and user input setup
* `game.*` - Core game loop, board management, movement, and actions
* `player.*` - Player state and inventory management
* `room.*` - Room container handling events and memory management
* `event.*` - Abstract base class for all events
* `wumpus`, `gold`, `arrow`, `bat_swarm`, `bottomless_pit`, `escape_rope` - Individual event implementations

Polymorphism and deep copying (`clone()`) are used to manage events safely within the grid.

---

## Building & Running

Compile with any standard C++ compiler supporting C++11 or later.

Example using `g++`:

```bash
g++ -std=c++11 *.cpp -o wumpus
./wumpus
```

---

## Notes

* Grid size is configurable (4–30 rows/columns)
* Randomized board generation each run
* Confusion effects reset each turn
* Arrow supply is limited, make sure to use them wisely

---

## Author

Gabriel Gaston

