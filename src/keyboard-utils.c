#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int get_enter(char *buffer) {
  // Reading buffer, number of characters, stream (standard input)
  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    buffer[strcspn(buffer, "\n")] = 0;

    if (strlen(buffer) == 0) {
      printf("Enter key was pressed.\n");
      return 0;
    }

    printf("You need to press <ENTER> to play\n");
  }

  return 1;
}

void enable_raw_mode() {
  struct termios old_tio, new_tio;
  tcgetattr(STDIN_FILENO, &old_tio); // Get current terminal attributes
  new_tio = old_tio;
  new_tio.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echoing
  tcsetattr(STDIN_FILENO, TCSANOW, &new_tio); // Apply new attributes
}

void disable_raw_mode() {
  struct termios old_tio;
  tcgetattr(STDIN_FILENO, &old_tio);
  old_tio.c_lflag |= (ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

void update_pressed_key(char *buffer) {
  char pressed_key;
  pressed_key = getchar();

  buffer[0] = pressed_key;
}
