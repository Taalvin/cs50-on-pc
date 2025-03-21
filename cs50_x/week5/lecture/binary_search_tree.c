// Only works for a balanced tree.'
typrdef struct node
{
    int number;
    struct node *left;
    struct node *right;
} node;

// Returns true if number is found in a tree. Else, returns false.
bool tree_search(int number, node *tree)
{
    if (tree == NULL)
    return false;
    else if (number < tree -> number)
    return tree_search(number, tree -> left);
    else if(number > tree -> number)
    return tree_search(number, tree -> right);
    else
    return true;
}
