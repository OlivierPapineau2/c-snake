#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "borders.h"
#include "food.h"
#include "keyboard-utils.h"
#include "math-utils.h"
#include "snake.h"

int main() {
  // ---- Seeding time for RNG
  srand((unsigned int)time(NULL));
  // -------------------------

  // -------------------- INIT PHASE -------------------------
  char input_buffer[100];

  printf("Let's play Snake!\n");
  printf("Press <ENTER> to play\n");

  int has_pressed_enter = 1;

  while (has_pressed_enter == 1) {
    has_pressed_enter = get_enter(input_buffer);
  }
  // ---------------------------------------------------------

  // -------------------- GAME STATE -------------------------
  Borders GAME_BORDERS;
  set_borders(&GAME_BORDERS);

  char pressed_key_buffer[1];

  Position *snake_head_position = (Position *)malloc(sizeof(Position));
  snake_head_position->y = 2;
  snake_head_position->x = 2;

  int snake_length = 0;
  Position **snake = malloc(1 * sizeof(Position *));
  if (snake == NULL) {
    printf("malloc failed, could not allocate snake memory");
    return 1;
  }
  // Insert head into snake
  snake[0] = snake_head_position;
  snake_length++;

  Position food_position;
  food_position.y = random_between(2, GAME_BORDERS.height);
  food_position.x = random_between(2, GAME_BORDERS.width);
  // ---------------------------------------------------------

  enable_raw_mode();
  printf("\033[2J");

  // -------------------- GAME LOOP -------------------------
  while (1) {
    draw_borders(GAME_BORDERS.width, GAME_BORDERS.height);
    update_pressed_key(pressed_key_buffer);
    draw_food(&food_position, GAME_BORDERS);
    move_snake(snake, pressed_key_buffer, &food_position, GAME_BORDERS,
               &snake_length);

    usleep(50000);
  }
  // --------------------------------------------------------
  if (snake != NULL) {
    free(snake);
  }
  free_snake_pointer(snake_head_position);
  disable_raw_mode();

  printf("\033[?25h");
  return 0;
}
// TODO: Make snake grow (lol)
