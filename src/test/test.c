#include <stdbool.h>
#include <stdio.h>
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "permutation_sort.h"
#include "sort_t.h"
#include "sorted_order.h"

#define c_vec_len(V) (sizeof(V)/sizeof((V)[0]))

static int current_test = 0;

#define EXPECT(block, message, ...) \
  do { \
    if (!(block)) { \
      printf("not "); \
    } \
    printf("ok %d - " message "\n", ++current_test, ##__VA_ARGS__); \
  } while (0);

#define PLAN(count) \
  do { \
    printf("1..%d\n", count); \
  } while (0);

#define ARRAYS_EQUAL(a, b) ({ \
    size_t size = c_vec_len(numbers); \
    bool equal = size == c_vec_len(sorted_numbers); \
    for (int i = 0; equal && i < size; i++) { \
      if (numbers[i] != sorted_numbers[i]) { \
        equal = false; \
      } \
    } \
    equal; \
  })

void test_sort(sort_t sort) {
  PLAN(3);

  {
    int numbers[] = {};
    int sorted_numbers[] = {};
    sort(numbers, c_vec_len(numbers), sorted_order);
    EXPECT(ARRAYS_EQUAL(numbers, sorted_numbers), "Array contents must be equal");
  }

  {
    int numbers[] = {-999};
    int sorted_numbers[] = {-999};
    sort(numbers, c_vec_len(numbers), sorted_order);
    EXPECT(ARRAYS_EQUAL(numbers, sorted_numbers), "Array contents must be equal");
  }

  {
    int numbers[] =        { 4, 5, 2, 4, 1, -156, 74, 15, 99, 15 };
    int sorted_numbers[] = { -156, 1, 2, 4, 4, 5, 15, 15, 74, 99 };
    sort(numbers, c_vec_len(numbers), sorted_order);
    EXPECT(ARRAYS_EQUAL(numbers, sorted_numbers), "Array contents must be equal");
  }
}

int main(int argc, char *argv[]) {
  printf("TAP version 13\n");

  sort_t sorts[] = {
    bubble_sort,
    insertion_sort,
    permutation_sort,
  };

  for (int i = 0; i < c_vec_len(sorts); i++) {
    test_sort(sorts[i]);
  }

  return 0;
}
