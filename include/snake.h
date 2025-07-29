#ifndef SNAKE_H
#define SNAKE_H

#include "borders.h"

typedef struct {
  int x;
  int y;
} Position;

Position *deep_copy_snake_position(const Position *source);
void free_snake_pointer(Position *pos);
void draw_snake(Position *old_snake_position, Position *new_snake_position);
int move_snake(Position **snake, char *pressed_key, Position *food_position,
               Borders GAME_BORDERS, int *snake_length);

#endif // SNAKE_H
