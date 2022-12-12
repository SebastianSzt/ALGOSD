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

void printListReverse(node head)
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

void addElementInOrder(node* head, int value, int sentinel)
{
    if (sentinel == 1)
    {
        pushEnd(head, 9999);
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
                popEnd(head);
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
        popEnd(head);
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
        pushEnd(&head, 9999);
        while ((head->data != 9999) && (head->data != value))
        {
            head = head->next;
        }
        popEnd(&head);
    }
    else
    {
        while ((head != NULL) && (head->data != value))
        {
            head = head->next;
        }
    }
    if (head) head->prev = 0;
    return head;
}

void removeElementInOrder(node* head, node element, int sentinel)
{
    if (sentinel == 1)
    {
        if (*head == element)
        {
            pop(head);
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
            p->next->prev = p;
            popEnd(head);
        }
    }
    else
    {
        if (*head == element)
        {
            pop(head);
        }
        else
        {
            node p = *head;
            while(p->next != element) 
            {
                p = p->next;
            }
            free(p->next);
            p->next = NULL;
            p->next = element->next;
            if (p->next) p->next->prev = p;
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
            node *p = &head;
            while((*p)->next)
            {
                p = &(*p)->next;
            }
            free(*p);
            (*p)->prev->next = 0;
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