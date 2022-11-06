#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

void push(node **head, int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = val;
    p->next = *head;
    *head = p;
}