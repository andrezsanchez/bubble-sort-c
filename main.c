#include <stdio.h>

typedef int (*compare_cb) (int a, int b);

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

void print_numbers(int numbers[], int count) {
  printf("[");
  for (int i = 0; i < count; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("%d]\n", numbers[count - 1]);
}

int main(int argc, char *argv[]) {
  int numbers[] = {
    4, 5, 2, 8, 4, 1, 23, 24, 74, 14, 15, 99, 15
  };

  bubble_sort(numbers, sizeof(numbers) / sizeof(int), reverse_sorted_order);

  print_numbers(numbers, sizeof(numbers) / sizeof(int));

  return 0;
}
