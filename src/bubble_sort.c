#include "bubble_sort.h"

void bubble_sort(int *target, int count, compare_cb cmp) {
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - 1; j++) {
      if (cmp(target[j], target[j + 1]) > 0) {
        int temp = target[j];
        target[j] = target[j + 1];
        target[j + 1] = temp;
      }
    }
  }
}
