#include <stdio.h>
#include "lib.h"

void bubbleSort(int tab[], sortType *stats)
{
    int i, j, temp;
    for (i = 0; i < 10000-1; i++) 
    {
        for (j = 0; j < 10000-i-1; j++) 
        {
            stats->porownania++;
            if (tab[j] > tab[j+1]) 
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                stats->podstawienia++;
            }
        }
    }
}

void insertSort(int tab[], sortType *stats) 
{
    int i, key, j;
    for (i = 1; i < 10000; i++) 
    {
        key = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > key) 
        {
            stats->porownania++;
            tab[j + 1] = tab[j];
            stats->podstawienia++;
            j--;
        }
        tab[j + 1] = key;
    }
}

void shellSort(int tab[], sortType *stats)
{
    int gap, i, j, temp;
    for (gap = 10000/2; gap > 0; gap /= 2) 
    {
        for (i = gap; i < 10000; i++) 
        {
            temp = tab[i];
            for (j = i; j >= gap && tab[j - gap] > temp; j -= gap) 
            {
                stats->porownania++;
                tab[j] = tab[j - gap];
                stats->podstawienia++;
            }
            tab[j] = temp;
        }
    }
}

void quickSort(int tab[], int low, int high, sortType *stats)
{
    int pivot, i, j, temp;
    if (low < high) 
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (tab[i] <= tab[pivot] && i <= high) 
            {
                stats->porownania++;
                i++;
            }
            while (tab[j] > tab[pivot] && j >= low) 
            {
                stats->porownania++;
                j--;
            }
            if (i < j) 
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
                stats->podstawienia++;
            }
        }
        temp = tab[j];
        tab[j] = tab[pivot];
        tab[pivot] = temp;
        stats->podstawienia++;
        quickSort(tab, low, j - 1, stats);
        quickSort(tab, j + 1, high, stats);
    }
}

void printStats(sortType tab[])
{
    int minPorownania = tab[0].porownania;
    int maxPorownania = tab[0].porownania;
    double sredniaPorownania = tab[0].porownania;
    int minPodstawienia = tab[0].podstawienia;
    int maxPodstawienia = tab[0].podstawienia;
    double sredniaPodstawienia = tab[0].podstawienia;
    int i;
    for (i = 1; i < 1000; i++)
    {
        if (tab[i].porownania < minPorownania) minPorownania = tab[i].porownania;
        if (tab[i].porownania > maxPorownania) maxPorownania = tab[i].porownania;
        sredniaPorownania += tab[i].porownania;
        if (tab[i].podstawienia < minPodstawienia) minPodstawienia = tab[i].podstawienia;
        if (tab[i].podstawienia > maxPodstawienia) maxPodstawienia = tab[i].podstawienia;
        sredniaPodstawienia += tab[i].podstawienia;
    }
    sredniaPorownania = sredniaPorownania/1000;
    sredniaPodstawienia = sredniaPodstawienia/1000;

    printf("Porownania:\tMIN = %d\tMAX = %d\tSREDNIA = %.2lf\n", minPorownania, maxPorownania, sredniaPorownania);
    printf("Podstawienia:\tMIN = %d\tMAX = %d\tSREDNIA = %.2lf\n", minPodstawienia, maxPodstawienia, sredniaPodstawienia);
}