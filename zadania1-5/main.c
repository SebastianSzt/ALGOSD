#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char** argv)
{
    node* head = NULL;
    int select = 1;

    while (select)
    {
        printf("Menu programu do list. Wybierz odpowiednią opcję.\n");
        printf("0 - Wyjscie z programu\n");
        printf("1 - dodaj element na poczatku listy\n");
        printf("2 - dodaj element na koncu listy\n");
        printf("3 - usun pierwszy element listy\n");
        printf("Wybierz opcję: ");
        scanf("%d", &select);
        switch (select)
        {
            case 0:
                exit(0);
                break;
            case 1:
                push(&head, 3);
                push(&head, 2);
                push(&head, 1);
                push(&head->next, 0);
                push(&head, 10);
                WyswietlListe(head);
                break;
            case 2:
                pushEnd(&head, 1);
                pushEnd(&head, 2);
                pushEnd(&head, 3);
                WyswietlListe(head);
                break;
            default:
                break;
        }
    }
}