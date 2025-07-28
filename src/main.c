#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
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

  Position *snake_position = (Position *)malloc(sizeof(Position));
  snake_position->y = 2;
  snake_position->x = 2;

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
    draw_food(&food_position, snake_position, GAME_BORDERS);
    move_snake(snake_position, pressed_key_buffer);

    usleep(50000);
  }
  // --------------------------------------------------------

  free_snake_pointer(snake_position);
  disable_raw_mode();

  printf("\033[?25h");
  return 0;
}
// TODO: Make snake grow (lol)
