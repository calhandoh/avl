#include <avl.h>

node_t *init_node(const void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = (void *) data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

tree_t *init_tree(cmp_data_f cmp_data, print_data_f print_data, free_data_f free_data)
{
    tree_t *tree =  malloc(sizeof(tree_t));
    tree->root = NULL;
    tree->cmp_data = cmp_data;
    tree->print_data = print_data;
    tree->free_data = free_data;
    return tree;
}

int get_max_height(int a, int b)
{
    return(a > b) ? a : b;
}

node_t *rotate_right(node_t *node)
{
    node_t *temp_one = node->left;
    node_t *temp_two = temp_one->right;

    temp_one->right = node;
    node->left = temp_two;

    temp_one->height = get_max_height(temp_one->left->height, temp_one->right->height) + 1;
    node->height = get_max_height(node->left->height, node->right->height) + 1;

    return temp_one;
}

node_t *rotate_left(node_t *node)
{
    node_t *temp_one = node->right;
    node_t *temp_two = temp_one->left;

    temp_one->right = node;
    node->right = temp_two;

    temp_one->height = get_max_height(temp_one->left->height, temp_one->right->height) + 1;
    node->height = get_max_height(node->left->height, node->right->height) + 1;

    return temp_one;
}

status_t add_data_to_tree(tree_t *tree, const void *data)
{
    node_t *new_root;
    
    if(NULL == tree->root)
    {
        tree->root = init_node(data);
        return 0;
    }
    else
    {
        new_root = insert(tree, tree->root, data);

        if(NULL != new_root)
        {
            tree->root = new_root;
            return 0;
        }

    }

    return -1;
}

node_t *insert(tree_t *tree, node_t *node, const void *data)
{
    if(NULL == node)
    {
        return init_node(data);
    }

    int retval = tree->cmp_data(data, node->data);

    if(retval < 0)
    {

        node->left = insert(tree, node->left, data);
    }
    else if(retval > 0)
    {
        node->right = insert(tree, node->right, data);
    }
    else
    {
        return node;
    }

    int balance;    

    if(NULL == node->left || NULL == node->right)
    {
        node->height = 1;
        balance = 0;
    }
    else
    {
        node->height = get_max_height(node->left->height, node->right->height) + 1;
        balance = node->left->height - node->right->height;
    }

    if(balance > 1 && tree->cmp_data(data, node->left->data) < 0)
    {
        return rotate_right(node);
    }

    if(balance < -1 && tree->cmp_data(data, node->right->data) > 0)
    {
        return rotate_left(node);
    }

    if(balance > 1 && tree->cmp_data(data, node->left->data) > 0)
    {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    if(balance < - 1 && tree->cmp_data(data, node->right->data) < 0)
    {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;
}

void display_tree(tree_t *tree)
{
    if(NULL == tree)
    {
        return;
    }

    r_display_tree(tree, tree->root);
}

void r_display_tree(tree_t *tree, node_t *node)
{
    if(NULL == node)
    {
        return;
    }

    r_display_tree(tree, node->left);
    tree->print_data(node->data);
    r_display_tree(tree, node->right);
}