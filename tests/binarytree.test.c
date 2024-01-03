#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../binarytree.c"

int main()
{
    // Trivial (sorted) binary tree.
    BSTree Tree;
    Tree.root = createNode(1, "jump");
    Tree.root->right = createNode(0, "print");
    Tree.root->left = createNode(0, "dup");
    Tree.root->right->right = createNode(1, "push");
    Tree.root->right->left = createNode(0, "pop");
    Tree.root->left->right = createNode(1, "ifeq");
    Tree.root->left->left = createNode(0, "add");

    // Can combine the steps but noo need since the tree is not long.
    bindNode(Tree.root, jump);
    bindNode(Tree.root->right, print);
    bindNode(Tree.root->left, dup);
    bindNode(Tree.root->right->right, push);
    bindNode(Tree.root->right->left, pop);
    bindNode(Tree.root->left->right, ifeq);
    bindNode(Tree.root->left->left, add);

    printf("%s", Tree.root->token);

    return 0;
}