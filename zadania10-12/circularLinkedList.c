#include <stdio.h>
#include <stdlib.h>
#include "circularLinkedList.h"

void push(node* head, int value)
{
    node p = malloc(sizeof(linkedListNode));
    if (*head)
    {
        p->data = (*head)->data;
        p->next = (*head)->next;
        (*head)->data = value;
        (*head)->next = p;
    }
    else 
    {
        p->data = value;
        p->next = p;
        *head = p;
    }
}

void pushEnd(node* head, int value)
{
    if (*head)
    {
        node p = *head;
        while (p && p->next != *head)
        {
            p = p->next;
        }
        node elem = malloc(sizeof(linkedListNode));
        elem->data = value;
        elem->next = *head;
        p->next = elem;
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
            node p = *head;
            while (p->next->next != *head)
            {
                p = p->next;
            }
            p->next = p->next->next;
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
        pushEnd(&current->next, val);
    }
}

void removeNode(node* head, node current)
{
    if (current != 0)
    {
        if (current->next && current->next != *head)
        {
            *current = *current->next;
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

void removeEveryK(node* head, int k)
{
    node current = *head;
    node temp;

    if (*head == NULL || current->next == *head || k < 1)
    {
        return;
    }

    if (k == 1)
    {
        while (current->next != *head)
        {
            pop(&current);
        }
        return;
    }
    int i;
    while (current->next != *head || current->next->next != *head)
    {
        for (i = 0; i < k - 2; i++)
        {
            current = current->next;
        }
        temp = current->next;
        current->next = temp->next;
        if (temp == *head)
        {
            *head = current->next;
        }
        free(temp);
        current = current->next;
    }
}

void diffList(node* a, node b)
{
    if (b)
    {
        node p = b;
        node tmp;
        while (p)
        {
            tmp = find(*a, p->data);
            while(tmp)
            {
                if (tmp->next == *a && tmp != *a)
                {
                    popEnd(&tmp->next);
                }
                else if (tmp->next == *a && tmp == *a)
                {
                    *a = NULL;
                }
                else if (tmp->next != *a)
                {
                    pop(&tmp);
                }
                tmp = find(*a, p->data);
            }
            if (p->next == b) break;
            p = p->next;
        }
    }
    else printf("Lista b jest pusta\n");
}