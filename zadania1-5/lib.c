#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void WyswietlListe (node *head)
{
    node *l = head;
    while (l)
    {
        printf ("%d->", l->data);
        l = l->next;
    }
    printf ("\n");
}

void push(node **head, int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = val;
    p->next = *head;
    *head = p;
}

void pushEnd(node **head, int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = val;
    p->next = 0;
    while ((*head))
    {
        head = &(*head)->next;
    }
    *head = p;
}

void pop(node **head)
{
    node *l = *head;
    if(l)
    {
        *head = l->next;
        free(l);
    }
}

void popEnd(node **head)
{
    node *l = *head;
    if(l)
    {
        if ( l->next != NULL)
        {
            while(l->next->next)
            {
                l = l->next;
            }
            free(l->next);
            l->next = NULL;
        }
        else
        {
            free(l);
            *head = NULL;
        }
    }
}

node* find(node *head, int val)
{
    while ((head != NULL) && (head->data != val))
    {
        head = head->next;
    }
    return head;
}

void pushBefore(node **head, node *current, int val)
{
    node *p = *head;
    if( p == current )
    {
        push(head, val);
    }
    else
    {
        while( p->next != current )
        {
            p = p->next;
        }
        p->next = (node*)malloc(sizeof(node));
        p->next->next = current;
        p->next->data = val;
    }
}

void pushAfter(node **head, node *current, int val)
{
    node *p = *head;
    while( p != current )
    {
        p = p->next;
    }
    node *end = (node*)malloc(sizeof(node));
    end->data = val;
    end->next = current->next;
    p->next = end;
}

void removeNode(node **head, node *current)
{
    node *p = *head;
    if( p == current )
    {
        pop(head);
    }
    else
    {
        while( p->next != current ) 
        {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
        p->next = current->next;
    }
}

node* readFromFile(char *fname)
{
    FILE *file = fopen(fname, "r");
    node* head = NULL;
    if (file == NULL)
    {
        printf("Error.\n");
    }
    else
    {
        int val;
        while(fscanf(file, "%d ",&val) > 0)
        {
            pushEnd(&head, val);
        }
    }
    fclose(file);
    return head;
}

int saveToFile(node *head, char *fname)
{
    FILE *file = fopen(fname, "w");
    if (file == NULL)
    {
        printf("Error.\n");
        fclose(file);
        return 0;
    }
    else
    {
        for (node* curr = head; curr != NULL; curr = curr->next)
        {
            fprintf(file, "%d ", curr->data);
        }
        fclose(file);
        return 1;
    }
}

void removeAll_iteratively(node **head, int val)
{
    node* current;
    do
    {
        current = find(*head, val);
        removeNode(head, current);
    }
    while(current != NULL);
}

node* revert_iteratively(node *head)
{
    node *new = NULL;
    node *tmp;
    while (head != NULL)
    {
        tmp = head->next;
        head->next = new;
        new = head;
        head = tmp;
    }
    head = new;
    return head;
}

void revert_recursively(node *head)
{
    node *p = head;
    if ((head != NULL) && (head->next != NULL))
    {
        head = head->next;
        revert_recursively(head);
        p->next->next = p;
        p->next = NULL;
    }
}