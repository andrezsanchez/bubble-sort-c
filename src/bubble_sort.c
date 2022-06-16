#include "bubble_sort.h"
#include "swap.h"

void bubble_sort(int *target, int count, compare_cb cmp) {
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - 1 - i; j++) {
      if (cmp(target[j], target[j + 1]) > 0) {
        swap(target, j, j + 1);
      }
    }
  }
}
