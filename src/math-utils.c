#include <stdlib.h>

#include "math-utils.h"

int random_between(int min, int max) {
  if (min > max) {
    int temp = min;
    min = max;
    max = temp;
  }

  return rand() % (max - min + 1) + min;
}
