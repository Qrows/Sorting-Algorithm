#include <stdio.h>
#include <time.h>
#include "utilArray.h"
#include "sorting.h"


void randomValue(int *, int, int);
void copyArray(int *, int *, int);

int main(int argc, char *argv[])
{       
        if (argc != 2 ) {
                printf("Usage: %s lenght\nlenght is an integer.\n", argv[0]);
                return EXIT_FAILURE;
        }

        int lenght = strtol(argv[1],NULL,10);
        int array[lenght];
        int cpArray[lenght];

        void (*rFunc[])(int *, int, int) ={ insertionSort, selectionSort,
                                            mergeSort, quickSort };

        void (*oiFunc[])(int *, int) = { heapSort, radixSort };

        void (*intFunc[])(int *, int, int) = {integerSort, bucketSort};
        
        char *rFuncName[] = { "insertionSort","selectionSort","mergeSort",
                              "quickSort"};
        char *oiFuncName[] = {"heapSort", "radixSort" };

        char *intFuncName[] = {"integerSort", "bucketSort"};
        
        int i = 0, recursion = 0, maxNumber = 4*lenght;

        int rFuncLenght = 4;
        int oiFuncLenght = 2;
        int intFuncLenght = 2;

        srand(time(NULL));

        randomValue(array, lenght, maxNumber);
        copyArray(cpArray, array, lenght);
        
        while ( i < rFuncLenght ) {
        printf("%s\n", "Not sorted Array: ");
        printIntArray(array, &lenght);
        
        rFunc[i](array, lenght , recursion);
        printf("%s(array, lenght = %d, recursion = %d)\n",
               rFuncName[i], lenght, recursion);
        
        printf("%s\n", "Sorted Array: ");
        printIntArray(array, &lenght);
        printf("\n");
        copyArray(array, cpArray, lenght);
        i++;
        }

        recursion = !recursion;
        i = 0;
        while ( i < rFuncLenght ) {
        printf("%s\n", "Not sorted Array: ");
        printIntArray(array, &lenght);
        
        rFunc[i](array, lenght , recursion);
        printf("%s(array, lenght = %d, recursion = %d)\n",
               rFuncName[i], lenght, recursion);
        
        printf("%s\n", "Sorted Array: ");
        printIntArray(array, &lenght);
        printf("\n");
        copyArray(array, cpArray, lenght);
        i++;
        }

        i = 0;
        while ( i < oiFuncLenght ) {
        printf("%s\n", "Not sorted Array: ");
        printIntArray(array, &lenght);

        oiFunc[i](array, lenght);
        printf("%s(array, lenght = %d)\n",
               oiFuncName[i], lenght);

        printf("%s\n", "Sorted Array: ");
        printIntArray(array, &lenght);
        printf("\n");
        copyArray(array, cpArray, lenght);
        i++;
        }

        i = 0;
        while ( i < intFuncLenght ) {
        printf("%s\n", "Not sorted Array: ");
        printIntArray(array, &lenght);
        
        intFunc[i](array, lenght , maxNumber);
        printf("%s(array, lenght = %d, maxNum = %d)\n",
               intFuncName[i], lenght, maxNumber);
        
        printf("%s\n", "Sorted Array: ");
        printIntArray(array, &lenght);
        printf("\n");
        copyArray(array, cpArray, lenght);
        i++;
        }

        printf("\n");
        return EXIT_SUCCESS;
}

void randomValue(int *array,int lenght, int maxValue)
{
        for ( int i = 0; i < lenght; i++) {
                array[i] = rand() % maxValue;
        }
}

void copyArray(int *array, int* cpArray, int lenght)
{
  for ( int i = 0; i < lenght; i++) {
        array[i] = cpArray[i];
  }
}
