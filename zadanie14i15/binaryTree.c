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
        d->parent = NULL;
        *root = d;
    }
    else
    {
        int tmp = strcmp((*root)->word, value);
        if (tmp < 0)
        {
            insert(&(*root)->right, value);
            (*root)->right->parent = (*root);
        }
        else if (tmp >= 0)
        {
            insert(&(*root)->left, value);
            (*root)->left->parent = (*root);
        }
    }
}

void removeNode(node* root, char* value)
{
    node tmp=*root;
	if (!*root)
	{
        return;
    }
	while (tmp != NULL && tmp->word != value)
	{
		if (strcmp(tmp->word, value) < 0)
		{
			tmp = tmp->right;
		}
		else
        {
            tmp = tmp->left;
        }
	}
	if (!tmp)
    {
        printf("Nie znaleziono takiego wyrazu, nic nie usunieto.\n");
        return;
    }

    node current;
    if (tmp->right)
    {
        current = tmp->right;
        while (current->left)
        {
            current = current->left;
        }
        tmp->word = current->word;
        removeNode(&current, current->word);
    }
    else if (tmp->left)
    {
        current = tmp->left;
        while (current->right)
        {
            current = current->right;
        }
        tmp->word = current->word;
        removeNode(&current, current->word);
    }
    else
    {
        if (tmp->parent->left == tmp) tmp->parent->left = NULL;
        else tmp->parent->right = NULL;
        free(tmp);
    }
}

node find(node* root,char* value)
{
	if (!*root)
	{
        printf("Drzewo jest puste.\n");
        return 0;
    }
	while (*root != NULL && (*root)->word != value)
	{
		if (strcmp((*root)->word, value) < 0)
		{
			*root = (*root)->right;
		}
		else
        {
            *root = (*root)->left;
        }
	}
	if (!*root)
    {
        printf("Nie znaleziono takiego wyrazu.\n");
        return 0;
    }
    return *root;
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