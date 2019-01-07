#include <test_avl.h>

int main(void)
{
    tree_t *tree;
    tree = init_tree((cmp_data_f) string_cmp, (print_data_f) string_print, (free_data_f) string_free);
    return 0;
}

int string_cmp(const char *lhs_data, const char *rhs_data)
{
    return strcmp(lhs_data, rhs_data);
}

void string_print(char *data)
{
    printf("%s\n", data);
}

void string_free(void *data)
{
    ;
}