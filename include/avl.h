#ifndef AVL_HEADER_H
#define AVL_HEADER_H
#include <stdlib.h>

typedef int (*cmp_data_f)(const void *lhs_data, const void *rhs_data);
typedef void (*print_data_f)(const void *data);
typedef void (*free_data_f)(void *data);

struct _node
{
    void *data;
    struct _node *left;
    struct _node *right;
    int height;
};

struct _tree
{
    struct _node *root;
    cmp_data_f cmp_data;
    print_data_f print_data;
    free_data_f free_data;
};

typedef struct _node node_t;
typedef struct _tree tree_t;
typedef int status_t;

node_t *init_node(const void *data);
tree_t *init_tree(cmp_data_f cmp_data, print_data_f print_data, free_data_f free_data);
status_t add_data_to_tree(tree_t *tree, const void *data);
node_t *insert(tree_t *tree, node_t *node, const void *data);
status_t rm_data_from_tree(tree_t *tree, void *data);
node_t *rotate_right(node_t *node);
node_t *rotate_left(node_t *node);
void display_tree(tree_t *tree);
void r_display_tree(tree_t *tree, node_t *node);
void destroy_tree(tree_t *tree);
#endif