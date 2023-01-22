#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void heapify(char** tab, int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && strcmp(tab[left], tab[largest]) > 0)
        largest = left;

    if (right < n && strcmp(tab[right], tab[largest]) > 0)
        largest = right;

    if (largest != i) 
    {
        char* tmp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = tmp;
        heapify(tab, n, largest);
    }
}

void hsort(char **tab) 
{
    for (int i = 1000 / 2 - 1; i >= 0; i--)
        heapify(tab, 1000, i);

    for (int i = 1000 - 1; i >= 0; i--) 
    {
        char* tmp = tab[0];
        tab[0] = tab[i];
        tab[i] = tmp;
        heapify(tab, i, 0);
    }
}