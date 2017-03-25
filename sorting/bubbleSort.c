/* Author: Christian Santapaola
 * C implementation of sorting algorithm BubbleSort
 * Complexity time T(n) = O(n^2)
 */

#include "sorting.h"
#include "utilArray.h"

int bubbleSort(int *array, int lenght)
{
        if ( array == NULL) {
                return EXIT_FAILURE;
        }
        if ( lenght < 0 ) {
                return EXIT_FAILURE;
        }
        int i, j;
        int swFlag = true;
        for ( i = 0; i < lenght && swFlag; i++) {
                swFlag = false;
                for (j = 0; j < lenght - 1 - i; j ++) {
                        if (array[j] > array[j + 1]) {
                                swap(&array[j],&array[j + 1]);
                                swFlag = true;
                        }
                }   
        }
        return EXIT_SUCCESS;
}
