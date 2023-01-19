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
    if ((*head)->next != 0) (*head)->next->prev = *head;
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
        int x = (*head)->data;
        if ((*head)->next) 
        {
            *head = (*head)->next;
            (*head)->prev = 0;
        }
        else
        {
            *head = NULL;
        }  
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
        if (current->prev)
        {
            node tmp = current->prev;
            push(&current, val);
            tmp->next = current;
            current->prev = tmp;
        }
        else
        {
            push(&(*head), val);
        }
    }
}

void pushAfter(node* head, node current, int val)
{
    if (current != 0)
    {
        if (current->next)
        {
            push(&current->next, val);
            current->next->prev = current;
        }
        else
        {
            pushEnd(&(*head), val);
        }
    }
}

void removeNode(node* head, node current)
{
    if (current != 0)
    {
        if (current->prev)
        {
            if (current->next)
            {
                current->next->prev = current->prev;
                current->prev->next = current->next;
            }
            else
            {
                current->prev->next = 0;
            }
        }
        else
        {
            if (current->next)
            {
                *head = (*head)->next;
                (*head)->prev = 0;
            }
            else
            {
                *head = NULL;
            }
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
    while (head && head->data != 9999)
    {
        printf ("%d->", head->data);
        head = head->next;
    }
    printf ("\n");
}

void printListReverse(node head)
{
    while (head && head->next && head->next->data != 9999)
    {
        head = head->next;
    }
    while (head)
    {
        if(head->data != 9999)
        {
            printf ("%d->", head->data);
        }
        head = head->prev;
    }
    printf ("\n");
}

void addElementInOrder(node* head, int value, int sentinel)
{
    if (sentinel == 1)
    {
        node p = (node)malloc(sizeof(doublyLinkedListNode));
        p->data = value;
        while((*head)->data != 9999)
        {
            if (value <= (*head)->data)
            {
                p->next = *head;
                p->prev = (*head)->prev;
                *head = p;
                (*head)->next->prev = p;
                return;
            }
            else
            {
                head = &(*head)->next;
            }
        }
        p->next = *head;
        p->prev = (*head)->prev;
        *head = p;
    }
    else
    {
        node p = (node)malloc(sizeof(doublyLinkedListNode));
        p->data = value;
        node tmp;
        while(*head)
        {
            if (value <= (*head)->data)
            {
                p->next = *head;
                p->prev = (*head)->prev;
                *head = p;
                (*head)->next->prev = p;
                return;
            }
            else
            {
                tmp = *head;
                head = &(*head)->next;
            }
        }
        p->next = 0;
        p->prev = tmp;
        *head = p;
    }
}

node findInOrder(node head, int value, int sentinel)
{
    if (sentinel == 1)
    {
        while ((head->data != 9999) && (head->data != value))
        {
            head = head->next;
        }
    }
    else
    {
        while ((head != NULL) && (head->data != value))
        {
            head = head->next;
        }
    }
    return head;
}

void removeElementInOrder(node* head, node element)
{
    if (element != 0)
    {
        if (element->prev)
        {
            if (element->next)
            {
                element->next->prev = element->prev;
                element->prev->next = element->next;
            }
            else
            {
                element->prev->next = 0;
            }
        }
        else
        {
            if (element->next)
            {
                *head = (*head)->next;
                (*head)->prev = 0;
            }
            else
            {
                pop(head);
            }
        }
    }
}

node readFromFileInOrder(char *fname, int sentinel)
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
        if (sentinel == 1)
        {
            pushEnd(&head, 9999);
            int val;
            if (fscanf(file, "%d ",&val) > 0) push(&head, val);
            while(fscanf(file, "%d ",&val) > 0)
            {
                node *p = &head;
                while ((*p)->next->data != 9999)
                {
                    if (val <= (*p)->next->data)
                    {
                        push(&(*p)->next, val);
                        (*p)->next->prev = *p;
                        break;
                    }
                    else
                    {
                        p = &(*p)->next;
                    }
                }
                if ((*p)->next->data == 9999 && (*p)->prev)
                {
                    push(&(*p)->next, val);
                    (*p)->next->prev = *p;
                }
                else if ((*p)->next->data == 9999 && !(*p)->prev)
                {
                    if (val <= (*p)->data) push(p, val);
                    else
                    {
                        push(&(*p)->next, val);
                        (*p)->next->prev = *p;
                    }
                }
            }
        }
        else
        {
            int val;
            if (fscanf(file, "%d ",&val) > 0) push(&head, val);
            while(fscanf(file, "%d ",&val) > 0)
            {
                node *p = &head;
                while ((*p)->next)
                {
                    if (val <= (*p)->next->data)
                    {
                        push(&(*p)->next, val);
                        (*p)->next->prev = *p;
                        break;
                    }
                    else
                    {
                        p = &(*p)->next;
                    }
                }
                if (!(*p)->next && (*p)->prev)
                {
                    push(&(*p)->next, val);
                    (*p)->next->prev = *p;
                }
                else if (!(*p)->next && !(*p)->prev)
                {
                    if (val <= (*p)->data) push(p, val);
                    else
                    {
                        push(&(*p)->next, val);
                        (*p)->next->prev = *p;
                    }
                }
            }
        }
    }
    fclose(file);
    return head;
}