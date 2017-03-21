/* Author: Christian Santapaola
 * C implementation of sorting algorithm selectionSort
 * Complexity Time T(n) = O(n^2)
 */

#include "sorting.h"
#include "utilArray.h"

void selectionSort(int *array, int lenght, int recursion)
{
        if (recursion != 0) {
                recursiveSelectionSort(array, lenght - 1, lenght);
        } else {
                iterativeSelectionSort(array, lenght);
        }
}

void iterativeSelectionSort(int *array, int lenght)
{
        int minIndex, j;
        /* seleziona il k-esimo elemento */
        for (int i = 0; i < lenght; i++) {
          /* trova il minimo tra k e lenght */
                minIndex = i;
                for (j = i; j < lenght; j++) {
                        if (array[minIndex] > array[j]) {
                                minIndex = j;
                        }
                }
                swap(&array[i], &array[minIndex]);
        }
}

void recursiveSelectionSort(int *array, int index, int lenght)
{
        if (index < 0) {
        /* se l'indice della parte ordianata è minore di 0 non fare niente */
        } else {
                recursiveSelectionSort(array, index - 1, lenght);
                int minIndex = index;
                for ( int i = index; i < lenght; i++) {
                        if (array[minIndex] > array[i]) {
                                minIndex = i;
                        }
                }
                swap(&array[index], &array[minIndex]);
        }       
}

