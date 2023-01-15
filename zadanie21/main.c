#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"

int main()
{
    srand(time(NULL));
    sortType bubbleSortStats[1000];
    sortType insertSortStats[1000];
    sortType shellSortStats[1000];
    sortType quickSortStats[1000];

    int i;
    for (i = 0; i < 1000; i++)
    {
        int data[10000];
        int j;
        for (j = 0; j < 10000; j++)
        {
            data[j] = rand()%10000;
        }

        int data1[10000];
        memcpy(data1, data, sizeof(data));
        int data2[10000];
        memcpy(data2, data, sizeof(data));
        int data3[10000];
        memcpy(data3, data, sizeof(data));
        int data4[10000];
        memcpy(data4, data, sizeof(data));
        
        bubbleSort(data1, &bubbleSortStats[i]);
        insertSort(data2, &insertSortStats[i]);
        shellSort(data3, &shellSortStats[i]);
        quickSort(data4, 0, 10000-1, &quickSortStats[i]);
    }

    printf("\n-------------------Sortowanie babelkowe-------------------\n");
    printStats(bubbleSortStats);
    printf("\n-------------------Sortowanie przez wstawianie-------------------\n");
    printStats(insertSortStats);
    printf("\n-------------------Sortowanie metoda Shella-------------------\n");
    printStats(shellSortStats);
    printf("\n-------------------Sortowanie quick sort-------------------\n");
    printStats(quickSortStats);
    printf("\n");

    return 0;
}