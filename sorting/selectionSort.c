/* Author: Christian Santapaola
 * C implementation of sorting algorithm selectionSort
 * Complexity Time T(n) = O(n^2)
 */

#include "sorting.h"
#include "utilArray.h"

int selectionSort(int *array, int lenght, bool recursion)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }

        if (recursion) {
                recursiveSelectionSort(array, lenght - 1, lenght);
        } else {
                iterativeSelectionSort(array, lenght);
        }
        return EXIT_SUCCESS;
}

int iterativeSelectionSort(int *array, int lenght)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
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
        return EXIT_SUCCESS;
}

int recursiveSelectionSort(int *array, int index, int lenght)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if ( lenght <= 0 || index >= lenght || index < 0) {
                return EXIT_FAILURE;
        }

        if (index == 0) {
                return EXIT_SUCCESS;
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
        return EXIT_SUCCESS;
}

