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
        *root = d;
    }
    else
    {
        if ((*root)->value < val)
        {
            insert(&(*root)->right, val);
        }
        else if ((*root)->value >= val)
        {
            insert(&(*root)->left, val);
        }
    }
}

int containSameValues(node* tree1, node* tree2)
{
    if (*tree1 == NULL && *tree2 == NULL) return 1;
 
    if (*tree1 != NULL && *tree2 != NULL) 
    {
        return ((*tree1)->value == (*tree2)->value 
                && containSameValues(&(*tree1)->left, &(*tree2)->left) 
                && containSameValues(&(*tree1)->right, &(*tree2)->right));
    }
 
    return 0;
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