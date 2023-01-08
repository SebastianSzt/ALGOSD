#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binaryTree.h"
#define COUNT 10

void insert(node* root, char* value)
{
    if (*root == NULL)
    {
        node d = NULL;
        d = (node)malloc(sizeof(treeNode));
        d->word = value;
        d->left = NULL;
        d->right = NULL;
        *root = d;
    }
    else
    {
        int tmp = strcmp((*root)->word, value);
        if (tmp < 0)
        {
            insert(&(*root)->right, value);
        }
        else if (tmp >= 0)
        {
            insert(&(*root)->left, value);
        }
    }
}

void removeNode(node* root, char* value)
{
    // if (*root == NULL)
    // {
    //     return;
    // } 
    // if (strcmp((*root)->word, value) >= 0)
    // {
    //     removeNode(&(*root)->left, value);
    // }   
    // else if (strcmp((*root)->word, value) < 0)
    // {
    //     removeNode(&(*root)->right, value);
    // }
    // else 
    // {
    //     if (&(*root)->left == NULL) 
    //     {
    //         node temp = (*root)->right;
    //         free(root);
    //         *root = temp;
    //     }
    //     else if (&(*root)->right == NULL) 
    //     {
    //         node temp = (*root)->left;
    //         free(root);
    //         *root = temp;
    //     }
    //     else
    //     {
    //         node temp = *root;
 
    //         while (temp && temp->left != NULL)  temp = temp->left;
 
    //         (*root)->word = temp->word;
    
    //         removeNode(&(*root)->right, temp->word);
    //     }
    // }
}

char* treeMax(node root)
{
    if (root == 0) return 0;
    while (root->right)
    {
        root = root->right;
    }
    return root->word;
}

char* treeMin(node root)
{
    if (root == 0) return 0;
    while (root->left)
    {
        root = root->left;
    }
    return root->word;
}

char* ancestor(node root)
{
    if (root)
    {
        if (root->left)
        {
            return treeMax(root->left);
        }
        node a;  
        do
        {
            a = root;
            root = root->right;
        } while (root != NULL && root->left == a);
    }
    return root->word;
}

char* descendant(node root)
{
    if (root)
    {
        if (root->right)
        {
            return treeMin(root->right);
        }
        node a;  
        do
        {
            a = root;
            root = root->right;
        } while (root != NULL && root->right == a);
    }
    return root->word;
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
    printf("%s\n", root->word);

    printTree0(root->left, space);
}

void printTree(node root)
{
    printTree0(root, 0);
}