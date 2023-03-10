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
    if (*head != NULL)
    {
        node *l = *head;
        if(l->next != 0)
        {
            *head = l->next;
            free(l);
        }
        else
        {
            free(l);
            *head = NULL;
        }
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

//Plik musi się znajdować w katalogu nadrzędnym
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
    node* current = find(*head, val);
    while (current != NULL)
    {
        removeNode(head, current);
        current = find(current, val);
    } 
}

void removeAll_recursively(node **head, int val)
{
    // if (head != NULL)
    // {
    //     node* current = find(*head, val);
    //     if (current != NULL)
    //     {
    //         removeNode(head, current);
    //         removeAll_recursively(head, val);
    //     }
    // }
    if (head != NULL)
    {
        if ((*head)->data == val)
        {
            pop(head);
            if ((*head)) removeAll_recursively(head, val);
        }
        else if ((*head)->next)
        {
            removeAll_recursively(&(*head)->next, val);
        }
    }
}

int findMostCommon(node *head)
{
    int max_count = 0;
    int max_value = 0;

    while (head != NULL)
    {
        int count = 0;
        node *current = head->next;

        while (current != NULL) 
        {
            if (current->data == head->data) 
            {
                count++;
            }
            current = current->next;
        }

        if (count > max_count) 
        {
            max_count = count;
            max_value = head->data;
        }

        head = head->next;
    }

    return max_value;
}

void usunniepodz(node **l, int k)
{
    node *current = *l;
    node *prev = NULL;
    while (current != NULL)
    {
        if (current->data % k != 0)
        {
            if (prev == NULL) 
            {
                *l = current->next;
                free(current);
                current = *l;
            } 
            else 
            {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void revert_iteratively(node **head)
{
    node *tmp;
    node *new = NULL;
    while( *head != NULL )
    {   
        tmp = (*head)->next;
        (*head)->next = new;
        new = *head;
        *head = tmp;
    }
    *head = new;
}

void revert_recursively(node **head)
{
    node *p = *head;
    if ( ( *head != NULL ) && ( (*head)->next != NULL ) )
    {
        *head = (*head)->next;
        revert_recursively(head);
        p->next->next = p;
        p->next = NULL;
    }
}