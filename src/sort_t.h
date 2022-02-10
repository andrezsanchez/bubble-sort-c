#pragma once

typedef int (*compare_cb) (int a, int b);
typedef void (*sort_t) (int *target, int count, compare_cb cmp);

