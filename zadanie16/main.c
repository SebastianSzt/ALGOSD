#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

int main()
{
    node root1 = NULL;
    node root2 = NULL;

    printf("Menu programu dla drzewa binarnego. Wybierz odpowiednia opcje.\n");
    printf("0 - Wyjscie z programu\n");
    printf("1 - porownanie dwóch drzew binarnych\n");
    printf("Wybierz opcję: ");
    int select;
    scanf("%d", &select);

    switch (select)
    {
        case 0:
            return 0;
            break;
        case 1:
            insert(&root1, 5);
            insert(&root1, 3);
            insert(&root1, 7);
            insert(&root1, 1);
            insert(&root1, 2);
            insert(&root1, 4);
            insert(&root1, 8);
            insert(&root1, 9);
            insert(&root1, 6);
            printf("Pierwsze drzewo:\n");
            printTree(root1);
            insert(&root2, 5);
            insert(&root2, 3);
            insert(&root2, 7);
            insert(&root2, 6);
            insert(&root2, 1);
            insert(&root2, 2);
            insert(&root2, 4);
            insert(&root2, 8);
            insert(&root2, 9);
            printf("Drugie drzewo:\n");
            printTree(root2);
            if (containSameValues(&root1, &root2)) printf("\n\nDrzewa sa takie same.\n");
            else printf("\n\nDrzewa sa rozne\n");
            break;
        default:
            printf("Niepoprawna cyfra.\n");
            break;
    }
}