#include <stdio.h>
#include <stdlib.h>
#include "doublyLinkedList.h"

int main()
{
    node head = NULL;
    
    printf("Dostępne listy.\n");
    printf("0 - Wyjscie z programu\n");
    printf("1 - Lista dwukierunkowa nieposortowana\n");
    printf("2 - Lista dwukierunkowa posortowana\n");
    printf("Wybierz opcję: ");
    int select;
    scanf("%d", &select);

    if (select == 0)
    {
        return 0;
    }
    else if (select == 1)
    {
        printf("Menu programu do list. Wybierz odpowiednią opcję.\n");
        printf("0 - Wyjscie z programu\n");
        printf("1 - dodawanie na początek listy\n");
        printf("2 - dodawanie na koniec listy\n");
        printf("3 - usuwanie pierwszego elementu listy i zwracanie jego wartości\n");
        printf("4 - usuwanie ostatniego elementu listy i zwracanie jego wartości\n");
        printf("5 - odszukaj zadany element\n");
        printf("6 - dodaj element przed wskazanym\n");
        printf("7 - dodaj za wskazanym elementem\n");
        printf("8 - usuń wskazany element\n");
        printf("9 - wczytaj zawartość listy z pliku\n");
        printf("10 - zapisz zawartość listy do pliku\n");
        printf("11 - wyświetl zawartość listy\n");
        printf("Wybierz opcję: ");
        scanf("%d", &select);

        switch (select)
        {
            case 0:
                return 0;
                break;
            case 1:
                head = readFromFile("plik.txt");
                printf("Lista przed:\n");
                printList(head);
                push(&head, 5);
                printf("Lista po:\n");
                printList(head);
                break;
            case 2:
                head = readFromFile("plik.txt");
                printf("Lista przed:\n");
                printList(head);
                pushEnd(&head, 5);
                printf("Lista po:\n");
                printList(head);
                break;
            case 3:
                head = readFromFile("plik.txt");
                printf("Lista przed:\n");
                printList(head);
                int value_pop = pop(&head);
                if (value_pop == 9999) printf("Nie usunięto żadnego elementu ponieważ lista była pusta.\n");
                else printf("Wartość usuniętego elementu: %d\n", value_pop);
                printf("Lista po:\n");
                printList(head);
                break;
            case 4:
                head = readFromFile("plik.txt");
                printf("Lista przed:\n");
                printList(head);
                int value_popEnd = popEnd(&head);
                if (value_popEnd == 9999) printf("Nie usunięto żadnego elementu ponieważ lista była pusta.\n");
                else printf("Wartość usuniętego elementu: %d\n", value_popEnd);
                printf("Lista po:\n");
                printList(head);
                break;
            case 5:
                head = readFromFile("plik.txt");
                printf("Przeszukiwana lista:\n");
                printList(head);
                node element_find = find(head, 5);
                if (!element_find) printf("Nie znaleziono elementu w liście.\n");
                else 
                {
                    printf("Lista znalezionego elementu:\n");
                    printList(element_find);
                }
                break;
            case 6:
                head = readFromFile("plik.txt");
                printf("Lista:\n");
                printList(head);
                node element_pushBefore = find(head, 5);
                if (!element_pushBefore) printf("Nie znaleziono wskazywanego elementu w liście.\n");
                else 
                {
                    printf("Lista wskazanego elementu:\n");
                    printList(element_pushBefore);
                    pushBefore(&head, element_pushBefore, 4);
                    printf("Lista po dodaniu elementu o wartości 4 przed wskazanym elementem:\n");
                    printList(head);
                }
                break;
            case 7:
                head = readFromFile("plik.txt");
                printf("Lista:\n");
                printList(head);
                node element_pushAfter = find(head, 5);
                if (!element_pushAfter) printf("Nie znaleziono wskazywanego elementu w liście.\n");
                else 
                {
                    printf("Lista wskazanego elementu:\n");
                    printList(element_pushAfter);
                    pushAfter(&head, element_pushAfter, 4);
                    printf("Lista po dodaniu elementu o wartości 4 po wskazanym elementem:\n");
                    printList(head);
                }
                break;
            case 8:
                head = readFromFile("plik.txt");
                printf("Lista:\n");
                printList(head);
                node element_removeNode = find(head, 5);
                if (!element_removeNode) printf("Nie znaleziono wskazywanego elementu w liście.\n");
                else 
                {
                    printf("Lista wskazanego elementu:\n");
                    printList(element_removeNode);
                    removeNode(&head, element_removeNode);
                    printf("Lista po usunięciu wskazanego elementu:\n");
                    printList(head);
                }
                break;
            case 9:
                head = readFromFile("plik.txt");
                printf("Lista:\n");
                printList(head);
                break;
            case 10:
                head = readFromFile("plik.txt");
                printf("Lista do zapisania:\n");
                printList(head);
                int test = saveToFile(head, "plik.txt");
                if (test == 1) printf("Zapis do pliku powiodl sie.\n");
                else if (test == 0) printf("Zapis do pliku nie powiodl sie.\n");
                break;
            case 11:
                head = readFromFile("plik.txt");
                printf("Lista:\n");
                printList(head);
                break;
            default:
                printf("Niepoprawna cyfra.\n");
                break;
        }
    }
    else if (select == 2)
    {
        printf("Menu programu do list. Wybierz odpowiednią opcję.\n");
        printf("0 - Wyjscie z programu\n");
        printf("1 - dodaj element w kolejności\n");
        printf("2 - znajdowanie elementu o wskazanej wartości\n");
        printf("3 - usuwanie elementu wcześniej znalezionego\n");
        printf("4 - wczytanie listy do pliku (w porządku, ale w pliku nie musi być zachowany porządek)\n");
        printf("Wybierz opcję: ");
        scanf("%d", &select);

        int sentinel = 2;
        if (select > 0 && select < 5)
        {
            while(sentinel != 0 && sentinel != 1)
            {
                printf("Czy lista jest z wartownikiem?\n");
                printf("0 - Nie\n");
                printf("1 - Tak\n");
                printf("Wybierz opcję: ");
                scanf("%d", &sentinel);
            }
            /*if (sentinel == 1) //Odkomentować jeśli lista nie jest wczytywana z pliku
            {
                head = (node)malloc(sizeof(doublyLinkedListNode));
                head->data = 9999;
                (*head).next = 0;
                (*head).prev = 0;
            }*/
        }

        switch (select)
        {
            case 0:
                return 0;
                break;
            case 1:
                head = readFromFileInOrder("plik.txt", sentinel);
                printf("Lista przed:\n");
                printList(head);
                addElementInOrder(&head, 4, sentinel);
                printf("Lista po:\n");
                printList(head);
                break;
            case 2:
                head = readFromFileInOrder("plik.txt", sentinel);
                printf("Przeszukiwana lista:\n");
                printList(head);
                node element_findInOrder = findInOrder(head, 5, sentinel);
                if (!element_findInOrder || element_findInOrder->data == 9999) printf("Nie znaleziono elementu w liście.\n");
                else 
                {
                    printf("Lista znalezionego elementu:\n");
                    printList(element_findInOrder);
                }
                break;
            case 3:
                head = readFromFileInOrder("plik.txt", sentinel);
                printf("Lista:\n");
                printList(head);
                node element_removeElementInOrder = findInOrder(head, 5, sentinel);
                if (!element_removeElementInOrder || element_removeElementInOrder->data == 9999) printf("Nie znaleziono wskazywanego elementu w liście.\n");
                else 
                {
                    printf("Lista wskazanego elementu:\n");
                    printList(element_removeElementInOrder);
                    removeElementInOrder(&head, element_removeElementInOrder, sentinel);
                    printf("Lista po usunięciu wskazanego elementu:\n");
                    printList(head);
                }
                break;
            case 4:
                head = readFromFileInOrder("plik.txt", sentinel);
                printf("Lista:\n");
                printList(head);
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
            (*head).prev->next = 0;
            free(head);
            head = NULL;
        }
    }
    else
    {
        printf("Niepoprawna cyfra.\n");
    }
}