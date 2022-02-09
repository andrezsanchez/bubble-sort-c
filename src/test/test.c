#include <stdbool.h>
#include <stdio.h>
#include "bubble_sort.h"

static int current_test;

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


#define TEST(description) \
  void TEST_##description()


TEST(bubble_sort) {
  PLAN(2);

  int numbers[] = {
    4, 5, 2, 8, 4, 1, 23, 24, 74, 14, 15, 99, 15
  };

  bubble_sort(numbers, sizeof(numbers) / sizeof(int), sorted_order);

  int sorted_numbers[] = {
    1, 2, 4, 4, 5, 8, 14, 15, 15, 23, 24, 74, 98
  };

  size_t size = sizeof(numbers) / sizeof(int);
  EXPECT(size != (sizeof(sorted_numbers) / sizeof(int)), "Array size must be equal");

  bool equal = true;
  for (int i = 0; i < size; i++) {
    if (numbers[i] != sorted_numbers[i]) {
      equal = false;
      break;
    }
  }

  EXPECT(equal, "Array contents must be equal");
}

int main(int argc, char *argv[]) {
  printf("TAP version 13\n");

  current_test = 0;
  TEST_bubble_sort();

  return 0;
}
