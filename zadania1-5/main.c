#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char** argv)
{
    node* head = NULL;
    int select = 1;

    while (select)
    {
        printf("Menu naszego programu do list. Wybierz odpowiednią opcję.\n");
        printf("1 - dodaj element na poczatku listy\n");
        printf("2 - dodaj element na koncu listy\n");
        printf("Wybierz opcję: ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
                push(&head, argc);
                break;
            case 2:
                //pushEnd();
                break;
            default:
                break;
        }
    }
}