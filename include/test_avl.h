#ifndef TEST_AVL_HEADER_H
#define TEST_AVL_HEADER_H

#include <stdio.h>
#include <string.h>
#include <avl.h>

int string_cmp(const char *lhs_data, const char *rhs_data);

void string_print(char *data);

void string_free(void *data);
#endif