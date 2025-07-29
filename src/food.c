#include <stdio.h>

#include "borders.h"
#include "math-utils.h"
#include "snake.h"

void change_food_position(Borders GAME_BORDERS, Position *food_position) {
  food_position->y = random_between(2, GAME_BORDERS.height);
  food_position->x = random_between(2, GAME_BORDERS.width);
}

void draw_food(Position *food_position, Borders GAME_BORDERS) {
  // if (food_position->y == snake_head_position->y &&
  //     food_position->x == snake_head_position->x) {
  //   change_food_position(GAME_BORDERS, food_position);
  // }

  printf("\033[%d;%dH*", food_position->y, food_position->x);
}
