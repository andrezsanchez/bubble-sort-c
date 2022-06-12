#include "swap.h"

void swap(int *target, int i, int j) {
  int temp = target[i];
  target[i] = target[j];
  target[j] = temp;
}
