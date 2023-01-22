// proszę wykonać sortowanie przez kopcowanie na tablicy o długości przynajmniej 1000 słów
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heapSort.h"

int main() {
    srand(time(0));

    char *wyrazy[1000];
    char litery[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 1000; i++) 
    {
        wyrazy[i]=(char*)malloc(sizeof(char) * 10);
        for (int j = 0; j < 10; j++) 
        {
            wyrazy[i][j] = litery[rand() % (sizeof(litery) - 1)];
        }
        wyrazy[i][10] = 0;
    }

    printf("Tablica przed sortowaniem: \n");
    for (int i = 0; i < 1000; i++) 
    {
        printf("%s ", wyrazy[i]);
    }
    printf("\n\n");

    hsort(wyrazy);

    printf("Tablica po sortowaniu: \n");
    for (int i = 0; i < 1000; i++) 
    {
        printf("%s ", wyrazy[i]);
    }
    printf("\n");

    return 0;
}