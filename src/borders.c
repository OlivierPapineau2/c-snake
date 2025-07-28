#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "borders.h"

int set_borders(Borders *out) {
  struct winsize w;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
    perror("ioctl failed");
    return 1;
  }

  out->width = w.ws_col;
  out->height = w.ws_row;

  return 0;
}

int draw_borders(int x, int y) {
  printf("\033[?25l"); // Clearing the screen

  // Print top bar
  for (int col = 1; col <= x; col++) {
    printf("\033[1;%dH#", col);
  }

  // Print side borders
  for (int row = 1; row < y; row++) {
    printf("\033[%d;0H#", row);
    printf("\033[%d;%dH#", row, x);
  }

  // Print bottom bar
  for (int col = 0; col <= x; col++) {
    printf("\033[%d;%dH#", y, col);
  }

  fflush(stdout);
  return 0;
}
