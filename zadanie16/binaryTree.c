#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"
#define COUNT 10

void insert(node* root, int val)
{
    if (*root == NULL)
    {
        node d = NULL;
        d = (node)malloc(sizeof(treeNode));
        d->value = val;
        d->left = NULL;
        d->right = NULL;
        d->parent = NULL;
        *root = d;
    }
    else
    {
        if ((*root)->value < val)
        {
            insert(&(*root)->right, val);
            (*root)->right->parent = (*root);
        }
        else if ((*root)->value >= val)
        {
            insert(&(*root)->left, val);
            (*root)->left->parent = (*root);
        }
    }
}

node treeMin(node root)
{
    if (root == 0) return 0;
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

node ancestor(node root)
{
    node tmp;
    if (!root) return 0;
    if (root->right)
    {
        return treeMin(root->right);
    }
    do
    {
        tmp = root;
        root = root->parent;
    } 
    while (root && root->right == tmp);

    return root;

}

int containSameValues(node* tree1, node* tree2)
{
    if (!tree1 || !tree2) return 0;
    node min1 = treeMin(*tree1);
    node min2 = treeMin(*tree2);

    while (min1 || min2)
    {
        if (!min1 || !min2 || (min1->value != min2->value)) return 0;
        min1 = ancestor(min1);
        min2 = ancestor(min2);
    }
    return 1;
}

void printTree0(node root, int space)
{
    if (root == 0)
    {
        return;
    }

    space += COUNT;

    printTree0(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->value);

    printTree0(root->left, space);
}

void printTree(node root)
{
    printTree0(root, 0);
}