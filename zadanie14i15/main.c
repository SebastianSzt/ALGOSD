#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

int main()
{
    node root = NULL;

    printf("Menu programu dla drzewa binarnego. Wybierz odpowiednia opcje.\n");
    printf("0 - Wyjscie z programu\n");
    printf("1 - dodawanie\n");
    printf("2 - usuwanie\n");
    printf("3 - szukanie\n");
    printf("4 - wyznaczanie maksimum\n");
    printf("5 - wyznaczanie minimum\n");
    printf("6 - wyznaczanie poprzednika\n");
    printf("7 - wyznaczanie nastepnika\n");
    printf("8 - drukowanie zawartosci utworzonego drzewa\n");
    printf("9 - zapis do pliku\n");
    printf("10 - wczytanie z pliku\n");
    printf("Wybierz opcję: ");
    int select;
    scanf("%d", &select);

    switch (select)
    {
        case 0:
            return 0;
            break;
        case 1:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            break;
        case 2:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            removeNode(&root, "5");
            printf("\n\n\n Nowe drzewo:\n");
            printTree(root);
            break;
        case 3:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            node new = find(&root, "3");
            printf("\n\n\n Drzewo znalezionego wyrazu:\n");
            printTree(new);
            break;
        case 4:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            char* max = treeMax(root);
            printf("Maksimum: %s\n", max);
            break;
        case 5:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            char* min = treeMin(root);
            printf("Minimum: %s\n", min);
            break;
        case 6:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            char* a = ancestor(root);
            printf("Poprzednik: %s\n", a);
            break;
        case 7:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            char* d = descendant(root);
            printf("Nastepnik: %s\n", d);
            break;
        case 8:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            break;
        case 9:
            insert(&root, "5");
            insert(&root, "3");
            insert(&root, "7");
            insert(&root, "1");
            insert(&root, "2");
            insert(&root, "4");
            insert(&root, "8");
            insert(&root, "9");
            insert(&root, "6");
            printf("Drzewo:\n");
            printTree(root);
            saveToFile(root);
            break;
        case 10:
            readFromFile(&root, "plik1.txt");
            printf("Drzewo z pliku:\n");
            printTree(root);
            break;
        default:
            printf("Niepoprawna cyfra.\n");
            break;
    }
}