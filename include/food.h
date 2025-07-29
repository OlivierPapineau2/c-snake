#ifndef FOOD_H
#define FOOD_H

#include "borders.h"
#include "snake.h"

void change_food_position(Borders GAME_BORDERS, Position *food_position);
void draw_food(Position *food_position, Borders GAME_BORDERS);

#endif // FOOD_H
