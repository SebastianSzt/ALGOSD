#include <stdio.h>
#include <stdlib.h>
#include "circularLinkedList.h"

int main()
{
    node head = NULL;

    printf("Menu programu dla listy jednokierunkowej cyklicznej. Wybierz odpowiednią opcję.\n");
    printf("0 - Wyjscie z programu\n");
    printf("1 - dodawanie na początek listy\n");
    printf("2 - dodawanie na koniec listy\n");
    printf("3 - usuwanie pierwszego elementu listy\n");
    printf("4 - usuwanie ostatniego elementu listy\n");
    printf("5 - odszukaj zadany element\n");
    printf("6 - dodaj element przed wskazanym\n");
    printf("7 - dodaj za wskazanym elementem\n");
    printf("8 - usuń wskazany element\n");
    printf("9 - wczytaj zawartość listy z pliku\n");
    printf("10 - zapisz zawartość listy do pliku\n");
    printf("11 - wyświetl zawartość listy\n");
    printf("12 - usuń co k-ty element aż na liście pozostanie tylko jeden element\n");
    printf("13 - usuń z listy a wszystkie wystąpienia elementów z listy b\n");
    printf("Wybierz opcję: ");
    int select;
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
            push(&head, 3);
            push(&head, 2);
            push(&head, 1);
            printf("Lista po:\n");
            printList(head);
            break;
        case 2:
            head = readFromFile("plik.txt");
            printf("Lista przed:\n");
            printList(head);
            pushEnd(&head, 1);
            pushEnd(&head, 2);
            pushEnd(&head, 3);
            printf("Lista po:\n");
            printList(head);
            break;
        case 3:
            head = readFromFile("plik.txt");
            printf("Lista przed:\n");
            printList(head);
            pop(&head);
            printf("Lista po:\n");
            printList(head);
            break;
        case 4:
            head = readFromFile("plik.txt");
            printf("Lista przed:\n");
            printList(head);
            popEnd(&head);
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
                pushBefore(element_pushBefore, 4);
                printf("Lista po dodaniu elementu przed wskazanym elementem:\n");
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
                pushAfter(element_pushAfter, 6);
                printf("Lista po dodaniu elementu za wskazanym elementem:\n");
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
        case 12:
            head = readFromFile("plik.txt");
            printf("Lista:\n");
            printList(head);
            int k = 3;
            removeEveryK(&head, k);
            printf("Lista po usuwaniu co %d element:\n", k);
            printList(head);
            break;
        case 13:
            head = readFromFile("plik.txt");
            printf("Lista a:\n");
            printList(head);
            node head_b = NULL;
            push(&head_b, 3);
            push(&head_b, 2);
            push(&head_b, 2);
            push(&head_b, 1);
            push(&head_b, 4);
            push(&head_b, 9);
            printf("Lista b:\n");
            printList(head_b);
            diffList(&head, head_b);
            printf("Lista a po usunieciu wszystkich wystąpien elementow z listy b:\n");
            printList(head);
            break;
        default:
            printf("Niepoprawna cyfra.\n");
            break;
    }
}