#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char** argv)
{
    node* head = NULL;
    int select = 1;

    while (select)
    {
        printf("Menu naszego programu do list. Wybierz odpowiedniuą opcję.\n");
        printf("1 - dodaj na początek listy\n");
        printf("2 - dodaj na koniec listy\n");
        printf("Wybierz opcję: ");
        scanf("%d", &select);
        switch (select)
        {
            case 1:
                //push();
                break;
            case 2:
                //pushEnd();
                break;
            default:
                break;
        }
    }
}