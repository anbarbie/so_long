# so_long

This project is a game implemented using the MiniLibX library in C. The game revolves around a main character who must collect every collectible present on the map and then escape by choosing the shortest possible route.

## Game Features

- The player controls the main character using the W, A, S, and D keys (or ZQSD or arrow keys).
- The main character can move up, down, left, or right.
- The player cannot move into walls.
- The current number of movements is displayed in the shell after every move.
- The game uses a 2D view (top-down or profile).
- The game is not real-time.

## Graphic Management

- The game is displayed in a window using the MiniLibX library.
- Window management remains smooth, allowing for switching to another window or minimizing.
- Pressing ESC or clicking on the window's cross closes the window and quits the program in a clean way.
- The images provided by the MiniLibX library are used for graphics.

## Map

- The map is constructed with three components: walls, collectibles, and free space.
- The map is represented using the following characters:
  - 0 for an empty space
  - 1 for a wall
  - C for a collectible
  - E for the map exit
  - P for the player's starting position
- The map must contain at least one exit, one collectible, and one starting position to be considered valid.
- The map must be rectangular.
- The map must be closed/surrounded by walls; otherwise, the program returns an error.
- The program checks if there is a valid path in the map.
- The program can parse any valid map format as long as it follows the specified rules.
- If any misconfiguration or error is encountered in the map file, the program exits with an error message.

## Bonus Features

- The player loses if they touch an enemy patrol.
- Sprite animation can be added.
- The movement count can be displayed directly on the screen instead of in the shell.
