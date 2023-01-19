#include <stdio.h>
#include <stdlib.h>
#include "circularDoublyLinkedList.h"

void push(node* head, int value)
{
    node p = malloc(sizeof(doublyLinkedListNode));
    if (*head)
    {
        p->data=(*head)->data;
        p->next=(*head)->next;
        p->prev=*head;
        if((*head)->next) (*head)->next->prev=p;
        (*head)->next=p;
        (*head)->data=value;
    }
    else 
    {
        p->data = value;
        p->next = p;
        p->prev = p;
        *head = p;
    }
}

void pushEnd(node* head, int value)
{
    if (*head)
    {
        node p = malloc(sizeof(doublyLinkedListNode));
        p->data = value;
        p->next = *head;
        p->prev = (*head)->prev;
        (*head)->prev->next = p;
        (*head)->prev = p;
    }
    else push(head, value);
}

void pop(node* head)
{
    if(*head)
    {
        node p = (*head)->next;
        if (p == *head) *head = NULL;
        else
        {
            (*head)->data = p->data;
            (*head)->next = p->next;
            p->next->prev = *head;
        }
        free(p);
    }
}

void popEnd(node* head)
{
    if (*head)
    {
        if ((*head)->next == *head) *head = NULL;
        else
        {
            (*head)->prev->prev->next = *head;
            (*head)->prev = (*head)->prev->prev;
        }
    }
}

node find(node head, int value)
{
    node p = head;
    while (p && (p->next != head) && (p->data != value))
    {
        p = p->next;
    }
    if (p->data == value) return p;
    else return NULL;
}

void pushBefore(node current, int val)
{
    if (current != 0)
    {
        push(&current, val);
    }
}

void pushAfter(node current, int val)
{
    if (current != 0)
    {
        node p = malloc(sizeof(doublyLinkedListNode));
        p->data = val;
        p->next = current->next;
        p->prev = current;
        current->next->prev = p;
        current->next = p;
    }
}

void removeNode(node* head, node current)
{
    if (current != 0)
    {
        if (current->next && current->next != *head && current->prev != (*head)->prev)
        {
            current->next->prev = current->prev;
            current->prev->next = current->next;
        }
        else if (current->prev == (*head)->prev && current->next != *head)
        {
            pop(&current);
        }
        else if (current->prev == (*head)->prev && current->next == *head)
        {
            *head = NULL;
        }
        else
        {
            popEnd(head);
        }
    }
}

node readFromFile(char* fname)
{
    FILE *file = fopen(fname, "r");
    node head = NULL;
    if (file == NULL)
    {
        printf("Odczyt pliku nie powiódł się.\n");
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

int saveToFile(node head, char* fname)
{
    FILE *file = fopen(fname, "w");
    if (file == NULL)
    {
        return 0;
    }
    else
    {
        for (node curr = head; curr != NULL; curr = curr->next)
        {
            fprintf(file, "%d ", curr->data);
            if (curr->next == head) break;
        }
        fclose(file);
        return 1;
    }
}

void printList(node head)
{
    if (head)
    {
        node p = head;
        while (p)
        {
            printf("%d->", p->data);
            if (p->next == head) break;
            p = p->next;
        }
        // p = p->next;
        // printf("\t");
        // while (p)
        // {
        //     printf("%d->", p->data);
        //     if (p->next == head) break;
        //     p = p->next;
        // }
    }
    printf("\n");
}

void printListReverse(node head)
{
    if (head)
    {
        node p = head->prev;
        while (p)
        {
            printf("%d->", p->data);
            if (p->prev == head->prev) break;
            p = p->prev;
        }
        // p = p->prev;
        // printf("\t");
        // while (p)
        // {
        //     printf("%d->", p->data);
        //     if (p->prev == head->prev) break;
        //     p = p->prev;
        // }
    }
    printf("\n");
}