#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void pushEnd(node *head, int val) //funkcja dla wartownika
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

void popEnd(node *head) //funkcja dla wartownika
{
    if(*head)
    {
        while((*head)->next)
        {
            head = &(*head)->next;
        }
        free(*head);
        *head = NULL;
    }
}

void addElement(node* head, int value, int sentinel)
{
    if (sentinel == 1)
    {
        pushEnd(head, 9999);
        node p = (node)malloc(sizeof(linkedListNode));
        p->data = value;
        while((*head)->data != 9999)
        {
            if (value <= (*head)->data)
            {
                p->next = *head;
                *head = p;
                popEnd(head);
                return;
            }
            else
            {
                head = &(*head)->next;
            }
        }
        p->next = *head;
        *head = p;
        popEnd(head);
    }
    else
    {
        node p = (node)malloc(sizeof(linkedListNode));
        p->data = value;
        while(*head)
        {
            if (value <= (*head)->data)
            {
                p->next = *head;
                *head = p;
                return;
            }
            else
            {
                head = &(*head)->next;
            }
        }
        p->next = *head;
        *head = p;
    }
}

int pop(node* head, int sentinel)
{
    node p = *head;
    if (sentinel == 1)
    {
        pushEnd(head, 9999);
        if((*head)->data != 9999)
        {
            int x = (*head)->data;
            *head = p->next;
            free(p);
            popEnd(head);
            return x;
        }
        else
        {
            int x = (*head)->data;
            free(*head);
            *head = NULL;
            return x;
        }
    }
    else
    {
        if(*head)
        {
            int x = (*head)->data;
            *head = p->next;
            free(p);
            return x;
        }
        else return 9999;
    }
}

int popBack(node* head, int sentinel)
{
    if (sentinel == 1)
    {
        if (*head)
        {
            pushEnd(head, 9999);
            while((*head)->next->data != 9999)
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
    else
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
}

node find(node head, int value, int sentinel)
{
    if (sentinel == 1)
    {
        pushEnd(&head, 9999);
        while ((head->data != 9999) && (head->data != value))
        {
            head = head->next;
        }
        popEnd(&head);
        return head;
    }
    else
    {
        while ((head != NULL) && (head->data != value))
        {
            head = head->next;
        }
        return head;
    }
}

void removeElement(node* head, node element, int sentinel)
{
    if (sentinel == 1)
    {
        if (*head == element)
        {
            pop(head, sentinel);
        }
        else
        {
            pushEnd(head, 9999);
            node p = *head;
            while(p->next != element) 
            {
                p = p->next;
            }
            free(p->next);
            p->next = NULL;
            p->next = element->next;
            popEnd(head);
        }
    }
    else
    {
        node p = *head;
        if (*head == element)
        {
            *head = p->next;
            free(p);
        }
        else
        {
            while(p->next != element) 
            {
                p = p->next;
            }
            free(p->next);
            p->next = NULL;
            p->next = element->next;
        }
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