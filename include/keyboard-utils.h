#ifndef KEYBOARD_UTILS_H
#define KEYBOARD_UTILS_H

int get_enter(char *buffer);
void enable_raw_mode();
void disable_raw_mode();
void update_pressed_key(char *buffer);

#endif // KEYBOARD_UTILS_H
