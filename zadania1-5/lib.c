#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void WyswietlListe (node *head)
{
    node *l = head;
    while (l)
    {
        printf ("%d-", l->data);
        l = l->next;
    }
    printf ("|\n");
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