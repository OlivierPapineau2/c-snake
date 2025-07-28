#ifndef SNAKE_H
#define SNAKE_H

typedef struct {
  int x;
  int y;
} Position;

Position *deep_copy_snake_position(const Position *source);
void free_snake_pointer(Position *pos);
void draw_snake(Position *old_snake_position, Position *new_snake_position);
void move_snake(Position *snake_position, char *pressed_key);

#endif // SNAKE_H
