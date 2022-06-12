#include <stdbool.h>
#include <stdio.h>
#include "permutation_sort.h"
#include "swap.h"

bool is_sorted(int *target, int start, int end, compare_cb cmp) {
  for (int i = start + 1; i < end; i++) {
    if (cmp(target[i - 1], target[i]) > 0) {
      return false;
    }
  }

  return true;
}

bool permutation_sort_internal(int *target, int start, int end, compare_cb cmp) {
  if (is_sorted(target, 0, end, cmp)) {
    return true;
  }

  for (int i = start; i < end; i++) {
    swap(target, start, i);
    if (permutation_sort_internal(target, start + 1, end, cmp)) {
      return true;
    }
    swap(target, start, i);
  }

  return false;
}

void permutation_sort(int *target, int count, compare_cb cmp) {
  permutation_sort_internal(target, 0, count, cmp);
}

