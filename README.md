# [WIP] C-Snake Game

Welcome to C-Snake, a simple terminal-based snake game written in C. The goal is to navigate the snake to eat food while avoiding running into the walls or itself.

## Features
- Classic snake game mechanics
- Playable in the terminal
- Responsive controls using `W`, `A`, `S`, `D` keys

## Building

This project uses CMake for building.

### Requirements
- CMake 3.10 or higher
- GCC or Clang

### Build Steps

1. **Clone the repository** (if you haven't already):
    ```bash
    git clone <repository-url>
    cd c-snake
    ```

2. **Build the project**:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

    This will generate an executable named `c-snake`.

## Running

Once built, you can run the game with:

```bash
./c-snake
```

### Controls

- **Start the game**: Press `<ENTER>`
- **Move Up**: Press `W`
- **Move Down**: Press `S`
- **Move Left**: Press `A`
- **Move Right**: Press `D`

## Project Structure

```
c-snake/
├── CMakeLists.txt      # Build configuration
├── include/            # Header files
│   ├── borders.h
│   ├── food.h
│   ├── keyboard-utils.h
│   ├── math-utils.h
│   └── snake.h
└── src/                # Source files
    ├── borders.c
    ├── food.c
    ├── keyboard-utils.c
    ├── main.c
    ├── math-utils.c
    └── snake.c
```

## Game Components

- **Snake**: Represented by `@` character, moves based on keyboard input
- **Food**: Randomly placed on the game board
- **Borders**: Terminal-based game boundaries
- **Controls**: Raw mode keyboard input for responsive gameplay

## License

This project is licensed under the MIT License. See the LICENSE file for details.
