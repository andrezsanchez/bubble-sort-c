#include "bubble_sort.h"

int sorted_order(int a, int b) {
  return a - b;
}

int reverse_sorted_order(int a, int b) {
  return b - a;
}

int * bubble_sort(int *target, int count, compare_cb cmp) {
  int temp = 0;
  int i = 0;
  int j = 0;

  for (i = 0; i < count; i++) {
    for (j = 0; j < count - 1; j++) {
      if (cmp(target[j], target[j + 1]) > 0) {
        temp = target[j];
        target[j] = target[j + 1];
        target[j + 1] = temp;
      }
    }
  }

  return target;
}
