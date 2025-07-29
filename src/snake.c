#include "snake.h"
#include "borders.h"
#include "food.h"

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

int extend_snake_buffer(Position **snake, int *current_length) {
  (*current_length)++;

  Position **tmp = realloc(snake, *current_length * sizeof(Position *));
  if (tmp == NULL) {
    perror("realloc failed");
    for (int i = 0; i < *current_length; i++)
      free(snake[i]);
    return 1;
  }
  snake = tmp;

  return 0;
}

int grow_snake(Position **snake, int snake_length, char pressed_key) {
  Position *last_snake_node = snake[snake_length - 1];
  int new_y;
  int new_x;

  // TODO: Rethink this, the new node should always be added in the same
  // direction as the last.

  // switch (pressed_key) {
  // case 'w':
  //   new_y = ++last_snake_node->y;
  //   new_x = last_snake_node->x;
  //   break;
  // }

  return 0;
}

int move_snake(Position **snake, char *pressed_key, Position *food_position,
               Borders GAME_BORDERS, int *snake_length) {
  Position *head_position;
  head_position = snake[0];

  Position *old_snake_head_position;
  old_snake_head_position = deep_copy_snake_position(head_position);

  switch (*pressed_key) {
  case 'w':
    head_position->y = --head_position->y;
    break;
  case 'a':
    head_position->x = --head_position->x;
    break;
  case 's':
    head_position->y = ++head_position->y;
    break;
  case 'd':
    head_position->x = ++head_position->x;
    break;
  }

  if (head_position->y == food_position->y &&
      head_position->x == food_position->x) {
    change_food_position(GAME_BORDERS, food_position);

    int extension_status = extend_snake_buffer(snake, snake_length);
    if (extension_status == 1) {
      perror("extend_snake_buffer failed.");
      return 1;
    }
  }

  draw_snake(old_snake_head_position, head_position);
  free_snake_pointer(old_snake_head_position);

  return 0;
}
