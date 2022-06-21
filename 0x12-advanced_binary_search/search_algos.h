#ifndef _SEARCH_ALGO_
#define _SEARCH_ALGO_
#include <stddef.h>
#include <stdio.h>
int advanced_binary(int *array, size_t size, int value);
int recursive_binary(int *array, size_t start, size_t finish, int value);
void print_array(int *array, size_t start, size_t finish);
#endif
