#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
    node head = NULL;
    
    printf("Menu programu do list. Wybierz odpowiednią opcję.\n");
    printf("0 - Wyjscie z programu\n");
    printf("1 - dodaj element w kolejności\n");
    printf("2 - usuwanie pierwszego elementu listy i zwracanie jego wartości\n");
    printf("3 - usuwanie ostatniego elementu listy i zwracanie jego wartości\n");
    printf("4 - znajdowanie elementu o wskazanej wartości\n");
    printf("5 - usuwanie elementu wcześniej znalezionego\n");
    printf("6 - wyświetlanie listy\n");
    printf("7 - wczytaj zawartość listy z pliku\n");
    printf("8 - zapisz zawartość listy do pliku\n");
    printf("Wybierz opcję: ");

    int select;
    scanf("%d", &select);

    int sentinel = 2;
    if (select > 0 && select < 6)
    {
        while (sentinel != 0 && sentinel != 1)
        {
            printf("Czy lista jest z wartownikiem?\n");
            printf("0 - Nie\n");
            printf("1 - Tak\n");
            printf("Wybierz opcję: ");
            scanf("%d", &sentinel);
        }
        /*if (sentinel == 1) //Odkomentować jeśli lista nie jest wczytywana z pliku
        {
            head = (node)malloc(sizeof(linkedListNode));
            head->data = 9999;
            (*head).next = 0;
        }*/
    }

    int value = 9999;
    switch (select)
    {
        case 0:
            exit(0);
            break;
        case 1:
            head = readFromFile("plik.txt", sentinel);
            printf("Lista przed:\n");
            printList(head);
            addElement(&head, 7, sentinel);
            printf("Lista po:\n");
            printList(head);
            break;
        case 2:
            head = readFromFile("plik.txt", sentinel);
            printf("Lista przed:\n");
            printList(head);
            value = pop(&head, sentinel);
            printf("Lista po:\n");
            printList(head);
            if (value == 9999) printf("Nie usunięto żadnego elementu ponieważ lista była pusta.\n");
            else printf("Wartość usuniętego elementu: %d\n", value);
            break;
        case 3:
            head = readFromFile("plik.txt", sentinel);
            printf("Lista przed:\n");
            printList(head);
            value = popBack(&head, sentinel);
            printf("Lista po:\n");
            printList(head);
            if (value == 9999) printf("Nie usunięto żadnego elementu ponieważ lista była pusta.\n");
            else printf("Wartość usuniętego elementu: %d\n", value);
            break;
        case 4:
            head = readFromFile("plik.txt", sentinel);
            printf("Przeszukiwana lista:\n");
            printList(head);
            node current = find(head, 4, sentinel);
            if (!current || current->data == 9999) printf("Nie znaleziono elementu w liście.\n");
            else 
            {
                printf("Lista znalezionego elementu:\n");
                printList(current);
            }
            break;
        case 5:
            head = readFromFile("plik.txt", sentinel);
            printf("Lista:\n");
            printList(head);
            node element = find(head, 4, sentinel);
            if (!element || element->data == 9999) printf("Nie znaleziono elementu w liście.\n");
            else 
            {
                printf("Lista znalezionego elementu:\n");
                printList(element);
                removeElement(&head, element);
                printf("Lista po usunięciu znalezionego elementu:\n");
                printList(head);
            }
            break;
        case 6:
            head = readFromFile("plik.txt", sentinel);
            printf("Wyswietlanie listy:\n");
            printList(head);
            break;
        case 7:
            head = readFromFile("plik.txt", sentinel);
            printf("Lista po wczytaniu z pliku:\n");
            printList(head);
            break;
        case 8:
            head = readFromFile("plik.txt", sentinel);
            printf("Lista do zapisania:\n");
            printList(head);
            int test = saveToFile(head, "plik.txt");
            if (test == 1) printf("Zapis do pliku powiodl sie.\n");
            else if (test == 0) printf("Zapis do pliku nie powiodl sie.\n");
            break;
        default:
            printf("Niepoprawna cyfra.\n");
            break;
    }
    if (sentinel == 1)
    {
        while((*head).next)
        {
            head = (*head).next;
        }
        free(head);
        head = NULL;
    }
}