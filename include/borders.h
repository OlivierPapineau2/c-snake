#ifndef BORDERS_H
#define BORDERS_H

typedef struct {
  int width;
  int height;
} Borders;

int set_borders(Borders *out);
int draw_borders(int x, int y);

#endif // BORDERS_H
