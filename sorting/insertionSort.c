/* Author: Christian Santapaola
 * C implementation of sorting algorithm insertionSort on int array
 * Order an array in cresent order
 * Complexity time T(n) = O(n^2)
 */
#include "sorting.h"

int insertionSort(int *array, int lenght, bool recursion)
{ /* choose beetween the recursive implementation or the iterative one.*/
        if ( array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
        /* menu for iterative or recursion*/
        if (recursion != 0) {
                recursiveInsertionSort(array, lenght);
        } else {
                iterativeInsertionSort(array, lenght);
        }
        return EXIT_SUCCESS;
}

int recursiveInsertionSort(int *array, int lenght)
{
        if ( array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
        if (lenght == 1) {
                return EXIT_SUCCESS;
        } else {
                recursiveInsertionSort(array, lenght - 1); 
                /* Ordered the array up to lenght - 1 */
                int j, val = array[lenght - 1];
                /* Search the right position to insert val*/
                for ( j = lenght - 2; j >= 0 && array[j] > val; j--) {
                        array[j + 1] = array[j];
                }
                /* Insert Val */
                array[j + 1] = val;
                return EXIT_SUCCESS;
        }
}

int iterativeInsertionSort(int *array, int lenght)
{        
        if ( array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
        int val, i, j;
        for ( i = 0; i < lenght; i++) {
                /* The Array between 0 and i is ordered */
                val = array[i];
                for ( j = i - 1; j >= 0 && array[j] > val; j--) {
                        array[j + 1] = array[j];
                }
                array[j + 1] = val;
        }
        return EXIT_SUCCESS;
}
