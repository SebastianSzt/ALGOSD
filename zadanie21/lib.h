typedef struct sortType{
    int porownania;
    int podstawienia;
} sortType;

void bubbleSort(int tab[], sortType *stats);
void insertSort(int tab[], sortType *stats);
void shellSort(int tab[], sortType *stats);
void quickSort(int tab[], int low, int high, sortType *stats);
void printStats(sortType tab[]);