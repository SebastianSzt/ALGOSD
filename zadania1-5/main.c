#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(int argc, char** argv)
{
    node* head = NULL;
    int select = 1;

    while (select)
    {
        //1,2,5,6
        printf("Menu programu do list. Wybierz odpowiednią opcję.\n");
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
        printf("11 - usuń wszystkie wartości val z listy iteracynie\n");
        printf("12 - usuń wszystkie wartości val z listy rekurencyjnie\n");
        printf("13 - odwróć listę iteracyjnie\n");
        printf("14 - odwróć listę rekurencyjnie\n");
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
            case 3:
                push(&head, 3);
                push(&head, 2);
                push(&head, 1);
                printf("Lista przed usunieciem pierwszego elementu:\n");
                WyswietlListe(head);
                pop(&head);
                printf("Lista po usunieciu pierwszego elementu:\n");
                WyswietlListe(head);
                break;
            case 4:
                push(&head, 3);
                push(&head, 2);
                push(&head, 1);
                printf("Lista przed usunieciem ostatniego elementu:\n");
                WyswietlListe(head);
                popEnd(&head);
                printf("Lista po usunieciu ostatniego elementu:\n");
                WyswietlListe(head);
                break;
            case 5:
            {
                push(&head, 3);
                push(&head, 2);
                push(&head, 1);
                push(&head->next, 0);
                push(&head, 10);
                printf("Lista:\n");
                WyswietlListe(head);
                node* current = find(head, 0);
                printf("Lista szukanego elementu:\n");
                WyswietlListe(current);
                break;
            }
            case 6:
            {
                push(&head, 3);
                push(&head, 2);
                push(&head, 1);
                push(&head->next, 0);
                push(&head, 10);
                printf("Lista przed:\n");
                WyswietlListe(head);
                node* current = find(head, 0);
                pushBefore(&head, current, 100);
                printf("Lista po:\n");
                WyswietlListe(head);
                break;
            }
            case 7:
            {
                push(&head, 3);
                push(&head, 2);
                push(&head, 1);
                push(&head->next, 0);
                push(&head, 10);
                printf("Lista przed:\n");
                WyswietlListe(head);
                node* current = find(head, 0);
                pushAfter(&head, current, 100);
                printf("Lista po:\n");
                WyswietlListe(head);
                break;
            }
            case 8:
            {
                push(&head, 3);
                push(&head, 2);
                push(&head, 1);
                push(&head->next, 0);
                push(&head, 10);
                printf("Lista przed:\n");
                WyswietlListe(head);
                node* current = find(head, 0);
                removeNode(&head, current);
                printf("Lista po:\n");
                WyswietlListe(head);
                break;
            }
            case 9:
            {
                head = readFromFile("plik.txt");
                WyswietlListe(head);
                break;
            }
            case 10:
            {
                head = readFromFile("plik.txt");
                pushEnd(&head, 1);
                pushEnd(&head, 2);
                pushEnd(&head, 3);
                int test;
                test = saveToFile(head, "plik.txt");
                if (test == 1) printf("Zapis do pliku powiodl sie.\n");
                else if (test == 0) printf("Zapis do pliku nie powiodl sie.\n");
                break;
            }
            case 11:
            {
                head = readFromFile("plik.txt");
                printf("Lista przed:\n");
                WyswietlListe(head);
                removeAll_iteratively(&head, 2);
                printf("Lista po:\n");
                WyswietlListe(head);
                break;
            }
            //Nie działa
            case 12:
            {
                // head = readFromFile("plik.txt");
                // printf("Lista przed:\n");
                // WyswietlListe(head);
                // removeAll_recursively(&head, 2);
                // printf("Lista po:\n");
                // WyswietlListe(head);
                break;
            }
            //Nie działa
            case 13:
            {
                head = readFromFile("plik.txt");
                printf("Lista przed:\n");
                WyswietlListe(head);
                node* revert;
                revert = revert_iteratively(head);
                printf("Lista po:\n");
                WyswietlListe(revert);
                break;
            }
            //Nie działa
            case 14:
            {
                head = readFromFile("plik.txt");
                printf("Lista przed:\n");
                WyswietlListe(head);
                revert_recursively(head);
                printf("Lista po:\n");
                WyswietlListe(head);
                break;
            }
            default:
                printf("Niepoprawna cyfra.\n");
                break;
        }
        exit(0);
    }
}