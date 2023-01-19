#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void addElement(node* head, int value, int sentinel)
{
    if (sentinel == 1)
    {
        node p = (node)malloc(sizeof(linkedListNode));
        p->data = value;
        while((*head)->data != 9999)
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
        if((*head)->data != 9999)
        {
            int x = (*head)->data;
            *head = p->next;
            free(p);
            return x;
        }
        else
        {
            int x = (*head)->data;
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
            while((*head)->next->data != 9999)
            {
                head = &(*head)->next;
            }
            int x = (*head)->data;
            *head = (*head)->next;
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
        while ((head->data != 9999) && (head->data != value))
        {
            head = head->next;
        }
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

void removeElement(node* head, node element)
{
    if (element)
    {
        if (element->next)
        {
            *element = *element->next;
        }
        else
        {
            popBack(head, 0);
        }
    }
}

void printList(node head)
{
    while (head && head->data != 9999)
    {
        printf ("%d->", head->data);
        head = head->next;
    }
    printf ("\n");
}

node readFromFile(char *fname, int sentinel)
{
    FILE *file = fopen(fname, "r");
    node head = NULL;
    if (sentinel == 1)
    {
        head = (node)malloc(sizeof(linkedListNode));
        head->data = 9999;
        (*head).next = 0;
    }
    if (file == NULL)
    {
        printf("Odczyt pliku nie powiódł się.\n");
        fclose(file);
    }
    else
    {
        int val;
        if (sentinel == 1)
        {
            while(fscanf(file, "%d ",&val) > 0)
            {
                node *tmp = &head;
                while ((*tmp)->data != 9999)
                {
                    tmp = &(*tmp)->next;
                }
                node p = (node)malloc(sizeof(linkedListNode));
                p->data = val;
                p->next = *tmp;
                *tmp = p;
            }
        }
        else
        {
            while(fscanf(file, "%d ",&val) > 0)
            {
                node *tmp = &head;
                while (*tmp)
                {
                    tmp = &(*tmp)->next;
                }
                node p = (node)malloc(sizeof(linkedListNode));
                p->data = val;
                p->next = 0;
                *tmp = p;
            }
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
        fclose(file);
        return 0;
    }
    else
    {
        for (node curr = head; curr != NULL; curr = curr->next)
        {
            if (curr->data == 9999) break;
            fprintf(file, "%d ", curr->data);
        }
        fclose(file);
        return 1;
    }
}