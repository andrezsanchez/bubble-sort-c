typedef int (*compare_cb) (int a, int b);

int sorted_order(int a, int b);
int reverse_sorted_order(int a, int b);

void bubble_sort(int *target, int count, compare_cb cmp);

typedef void (*sort_t) (int *target, int count, compare_cb cmp);
