#include "stack.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//not complete

typedef struct tnode //tree node
{
    int data; // expected args for c_asm function
    char *token;
    struct tnode *left;
    struct tnode *right;
    //int (*f)(const struct tnode *);
    int (*f)(int);

} Node;

typedef struct bstree
{
    Node *root;
} BSTree;

void print_x(const struct tnode *p)
{
    printf("inside");
}


Node *createNode(int data, char *name);
Node *findNode(Node* head, char *name);

// function type
// typedef int (*foo)(int);
// foo functions[] = {&push, &pop};

void bindNode(Node* leaf, int (*f)(int))
{
    // Tree.root->f = push;
    // Tree.root->f(&Tree.root);

    // printf("%d f id\n", f);
    leaf->f = f;
    //leaf->f(99); //pushed 99
    //f(1);
}
void callNode(Node *leaf, int (*f)(int), int data)
{
    leaf->f(data); 
}

void callNodeByName(char* name, int data)
{
    //leaf->f(data);
}
int TreeInit()
{
    //Trivial (sorted) binary tree.
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

Node *findNode(Node *leaf, char *name) {
    if (leaf == NULL)
    {
        return leaf;
    }

    if (leaf->token == name)
    {
        // Found the node.
        return leaf; // Base case (can combine with above if-statement).
    }
    if (name < leaf->token) //make a strcmp !!!!!!!!!!!!!!!!!!!!
    {
        // Check the left subtree.
        return findNode(leaf->left, leaf->token);
    }
    else
    {
        // Check the right subtree.
        return findNode(leaf->right, leaf->token);
    }
}
Node *createNode(int data, char *name)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    //char *token = (char *)malloc(sizeof(name));
    if (newNode != NULL)
    {
        newNode->token = malloc(strlen(name) + 1);
        strcpy(newNode->token, name);
        
        //printf("%s", newNode->token);
        
        newNode->data = data;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}