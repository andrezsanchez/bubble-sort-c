#include "insertion_sort.h"
#include "swap.h"

void insertion_sort(int *target, int count, compare_cb cmp) {
  for (int i = 1; i < count; i++) {
    for (int j = i; (j > 0) && (cmp(target[j - 1], target[j]) > 0); j--) {
      swap(target, j, j - 1);
    }
  }
}
