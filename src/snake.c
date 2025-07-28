#include "snake.h"

#include <stdio.h>
#include <stdlib.h>

Position *deep_copy_snake_position(const Position *source) {
  if (source == NULL) {
    return NULL;
  }

  Position *dest = (Position *)malloc(sizeof(Position));
  if (dest == NULL) {
    printf("Failed to allocate memory");
    return NULL;
  }

  dest->x = source->x;
  dest->y = source->y;

  return dest;
}

void free_snake_pointer(Position *pos) {
  if (pos != NULL) {
    free(pos);
  }
}

void draw_snake(Position *old_snake_position, Position *new_snake_position) {
  printf("\033[%d;%dH ", old_snake_position->y, old_snake_position->x);
  printf("\033[%d;%dH@", new_snake_position->y, new_snake_position->x);
}

void move_snake(Position *snake_position, char *pressed_key) {
  Position *old_snake_position;
  old_snake_position = deep_copy_snake_position(snake_position);

  switch (*pressed_key) {
  case 'w':
    snake_position->y = --snake_position->y;
    break;
  case 'a':
    snake_position->x = --snake_position->x;
    break;
  case 's':
    snake_position->y = ++snake_position->y;
    break;
  case 'd':
    snake_position->x = ++snake_position->x;
    break;
  }

  draw_snake(old_snake_position, snake_position);
  free_snake_pointer(old_snake_position);
}
