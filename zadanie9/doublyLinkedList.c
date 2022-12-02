#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

void push(node* head, int val)
{
    node p = (node)malloc(sizeof(doublyLinkedListNode));
    p->data = val;
    p->prev = 0;
    p->next = *head;
    *head = p;
    if (&(*head)->next) (*head)->next->prev = *head;
}

void pushEnd(node* head, int val)
{
    if (*head)
    {
        while ((*head)->next)
        {
            head = &(*head)->next;
        }
        node p = (node)malloc(sizeof(doublyLinkedListNode));
        p->data = val;
        p->next = 0;
        p->prev = *head;
        (*head)->next = p;
    }
    else
    {
        node p = (node)malloc(sizeof(doublyLinkedListNode));
        p->data = val;
        p->next = 0;
        p->prev = 0;
        *head = p;
    }
}

int pop(node* head)
{
    if(*head)
    {
        node p = *head;
        int x = p->data;
        *head = p->next;
        free(p);
        (*head)->prev = 0;
        return x;
    }
    else return 9999;
}

int popEnd(node* head)
{
    if (*head)
    {
        while((*head)->next)
        {
            head = &(*head)->next;
        }
        int x = (*head)->data;
        free(*head);
        *head = NULL;
        return x;
    }
    else return 9999;
}

node find(node head, int val)
{
    while ((head != NULL) && (head->data != val))
    {
        head = head->next;
    }
    return head;
}

void pushBefore(node* head, node current, int val)
{
    if (current != 0)
    {
        if (*head == current)
        {
            push(head, val);
        }
        else
        {
            while((*head)->next != current) 
            {
                head = &(*head)->next;
            }
            push(&(*head)->next, val);
            (*head)->next->prev = *head;
        }
    }
}

void pushAfter(node* head, node current, int val)
{
    if (current != 0)
    {
        if (*head == current)
        {
            if ((*head)->next)
            {
                push(&(*head)->next, val);
                (*head)->next->prev = *head;
            }
            else pushEnd(head, val);
        }
        else
        {
            while((*head) != current) 
            {
                head = &(*head)->next;
            }
            if ((*head)->next)
            {
                push(&(*head)->next, val);
                (*head)->next->prev = *head;
            }
            else pushEnd(head, val);
        }
    }
}

void removeNode(node* head, node current)
{
    if (current != 0)
    {
        node p = *head;
        if (*head == current)
        {
            *head = p->next;
            free(p);
            (*head)->prev = 0;
        }
        else
        {
            while(p->next != current) 
            {
                p = p->next;
            }
            free(p->next);
            p->next = NULL;
            p->next = current->next;
            p->next->prev = p;
        }
    }
}

//Plik musi się znajdować w katalogu nadrzędnym
node readFromFile(char *fname)
{
    FILE *file = fopen(fname, "r");
    node head = NULL;
    if (file == NULL)
    {
        printf("Odczyt pliku nie powiódł się.\n");
        fclose(file);
        exit(0);
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

void printList(node head)
{
    while (head)
    {
        printf ("%d->", head->data);
        head = head->next;
    }
    printf ("\n");
}

void printList_reverse(node head)
{
    while (head->next)
    {
        head = head->next;
    }
    while (head)
    {
        printf ("%d->", head->data);
        head = head->prev;
    }
    printf ("\n");
}