#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

void randomValue(int *, int, int);
void copyArray(int *, int *, int);

int main(int argc, char *argv[])
{       
        if (argc != 2 ) {
                printf("Usage: %s lenght\nlenght is an integer.\n", argv[0]);
                return 1;
        }
        int lenght = strtol(argv[1],NULL,10);
        int array[lenght];
        int cpArray[lenght];

        srand(time(NULL));

        randomValue(array, lenght, 4*lenght);
        copyArray(cpArray, array, lenght);

        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("insertionSort(array,lenght = %d, recursion = true)\n",lenght);
        insertionSort(array, lenght, 1);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");
        
        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("insertionSort(array,lenght = %d, recursion = false)\n",lenght);
        insertionSort(array, lenght, 0);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");
        
        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("selectionSort(array,lenght = %d, recursion = true)\n",lenght);
        selectionSort(array, lenght, 1);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");
        
        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("selectionSort(array,lenght = %d, recursion = false)\n",lenght);
        selectionSort(array, lenght, 0);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");
        
        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("bubbleSort(array,lenght = %d)\n",lenght);
        bubbleSort(array, lenght);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");
        
        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("heapSort(array,lenght = %d)\n",lenght);
        heapSort(array, lenght);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");

        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("mergeSort(array,lenght = %d, recursion = True)\n",lenght);
        mergeSort(array,lenght, 1);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");

        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("mergeSort(array,lenght = %d,recursion = False)\n",lenght);
        mergeSort(array,lenght, 0);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");
        
        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("quickSort(array,lenght = %d,recursion = True)\n",lenght);
        quickSort(array,lenght,1);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n"); 

        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("quickSort(array,lenght = %d,recursion = false)\n",lenght);
        quickSort(array,lenght,0);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n"); 


        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("integerSort(array,lenght = %d, %d)\n",lenght, 4*lenght);
        integerSort(array, lenght, 4*lenght);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");

        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("bucketSort(array,lenght = %d, %d)\n",lenght, 4*lenght);
        bucketSort(array, lenght, 4*lenght);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");

        copyArray(array, cpArray, lenght);
        printf("Not sorted Array: \n");
        printIntArray(array, &lenght);
        printf("radixSort(array,lenght = %d)\n",lenght);
        radixSort(array, lenght);
        printf("Sorted Array: \n");
        printIntArray(array, &lenght);
        printf("\n");


        printf("\n");
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
