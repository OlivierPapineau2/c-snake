cmake_minimum_required(VERSION 3.10)
project(c-snake C)

set(CMAKE_C_STANDARD 11)

# Add include directory
include_directories(include)

# Add source files
add_executable(c-snake
    src/main.c
    src/snake.c
    src/borders.c
    src/food.c
    src/math-utils.c
    src/keyboard-utils.c
    include/snake.h
    include/borders.h
    include/food.h
    include/math-utils.h
    include/keyboard-utils.h
)

