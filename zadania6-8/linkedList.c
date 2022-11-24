#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void pushEnd(node *head, int val)
{
    node p = (node)malloc(sizeof(linkedListNode));
    p->data = val;
    p->next = 0;
    while (*head)
    {
        head = &(*head)->next;
    }
    *head = p;
}

void popEnd(node *head)
{
    if(*head)
    {
        while((*head)->next)
        {
            head = &(*head)->next;
        }
        free(*head);
        *head = NULL;
        // if ( (*head)->next != NULL )
        // {
        //     while((*head)->next->next)
        //     {
        //         *head = (*head)->next;
        //     }
        //     free((*head)->next);
        //     (*head)->next = NULL;
        // }
        // else
        // {
        //     free(head);
        //     *head = NULL;
        // }
    }
}

void addElement(node* head, int value, int sentinel)
{
    node p = *head;
    if (sentinel == 1)
    {
        pushEnd(head, 9999);
        while(p->data != 9999)
        {
            if (value <= p->data)
            {
                node tmp = (node)malloc(sizeof(linkedListNode));
                tmp = p;
                printList(tmp);
                printList(p);
                p->data = value;
                printList(tmp);
                printList(p);
                p->next = tmp;
                popEnd(head);
                return;
            }
            else
            {
                p = p->next;
            }
        }
        // p->next = p;
        // p = p;
        // popEnd(head);
    }
    else
    {
        exit(0);
    }
}

void printList(node head)
{
    while (head)
    {
        printf ("%d->", head->data);
        head = head->next;
    }
    printf ("\n");
}

node readFromFile(char *fname)
{
    FILE *file = fopen(fname, "r");
    node head = NULL;
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

int saveToFile(node head, char *fname)
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
        for (node curr = head; curr != NULL; curr = curr->next)
        {
            fprintf(file, "%d ", curr->data);
        }
        fclose(file);
        return 1;
    }
}