# Snake

Console-based Snake game developed in C with modular source code organization, real-time keyboard input, and Windows console customization.

![C](https://img.shields.io/badge/C-Programming-blue)
![CMake](https://img.shields.io/badge/CMake-Build%20System-green)
![Windows](https://img.shields.io/badge/Platform-Windows-lightgrey)
![Console App](https://img.shields.io/badge/Application-Console%20App-informational)

## Demo

https://github.com/user-attachments/assets/aec0d503-2485-49cb-9819-d2d311a0c2dd

## What is it?

Snake is a desktop console application that implements the classic Snake game for Windows.

The software manages snake movement, food generation, collision detection, score calculation, win detection, and final result visualization directly inside a Windows console interface.

The project is organized into separate source and header files to keep the game loop, map management, snake logic, keyboard input, console configuration, and graphical output clearly separated.

## Features

- Console-based Snake gameplay
- Real-time movement using keyboard input
- Direction control with `W`, `A`, `S`, and `D`
- Exit command using `Esc`
- Random food generation
- Snake growth after collecting food
- Collision detection with walls and the snake body
- Score calculation based on collected food
- Win condition when the playable area is fully occupied
- Game over screen with final score
- Fixed and centered Windows console window
- Custom executable icon through Windows resource files
- Modular C source code organization

## Key Technical Aspects

- Modular separation between game loop, map handling, snake logic, input management, console configuration, and graphical output
- Windows-specific console customization using the Windows API
- Real-time keyboard input handled through a dedicated input thread
- Dynamic memory allocation for the game map and snake body coordinates
- Matrix-based map representation for walls, free cells, food, and snake positions
- Direction validation to prevent direct reversal into the snake body
- CMake-based build configuration
- Custom executable icon integration through a Windows resource file
- Clear separation between source files and header files

## Technology Stack

- C
- CMake
- Windows API
- Windows resource file `.rc`
- CLion or another CMake-compatible IDE

## Requirements

- Windows operating system
- CMake
- A C compiler supported by CMake
- CLion, Visual Studio, or another CMake-compatible development environment

## Quick Start

### Clone the repository

```bash
git clone https://github.com/MattiaBenati/Snake.git
cd Snake
```

### Build the project

Generate the build files:

```bash
cmake -S . -B build
```

Build the executable:

```bash
cmake --build build
```

### Run the application

Run the generated executable from the build directory or directly from the IDE.

## Usage

1. Start the application
2. The console window is configured and displayed
3. The game panel is drawn inside the console
4. Press any key to start the match
5. Control the snake using the keyboard
6. Collect food to increase the snake length and score
7. Avoid collisions with the walls and the snake body
8. The game ends when the snake collides, the player exits, or the playable area is fully occupied
9. The final result and score are displayed in the console

## Controls

| Key | Action |
| --- | --- |
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `Esc` | Exit the game |

The program prevents the snake from immediately reversing direction into itself.

## Project Structure

```text
Snake/
├── assets/
│   ├── icon.ico
│   ├── icon.png
│   └── resource.rc
├── include/
│   ├── console.h
│   ├── gioco.h
│   ├── grafica.h
│   ├── input.h
│   ├── mappa.h
│   └── serpente.h
├── src/
│   ├── console.c
│   ├── gioco.c
│   ├── grafica.c
│   ├── input.c
│   ├── main.c
│   ├── mappa.c
│   └── serpente.c
└── CMakeLists.txt
```

## Architecture Overview

The project follows a modular C structure, where each source file is responsible for a specific part of the application.

- `main.c`: starts the application, configures the console, initializes the game, starts the input thread, and manages the main execution flow
- `console.c`: configures the Windows console title, window size behavior, input mode, and screen position
- `gioco.c`: manages game initialization, the main game loop, and the final result screen
- `grafica.c`: manages cursor positioning, game borders, and result panel drawing
- `input.c`: handles real-time keyboard input through a dedicated thread
- `mappa.c`: creates and releases the matrix-based game map
- `serpente.c`: manages snake creation, movement, direction updates, collision checks, growth, and food generation
- `include/`: contains the header files used by the source modules
- `assets/`: contains the application icon and Windows resource file
- `CMakeLists.txt`: defines the CMake build configuration

## Output

The software runs entirely inside the Windows console.

During execution, it displays the game panel, the snake, food items, real-time movement updates, collision results, and the final score.

The final output indicates whether the player has won by filling the playable area or whether the match ended with a game over.
