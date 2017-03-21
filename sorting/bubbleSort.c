/* Author: Christian Santapaola
 * C implementation of sorting algorithm BubbleSort
 * Complexity time T(n) = O(n^2)
 */

#include "sorting.h"
#include "utilArray.h"

void bubbleSort(int *array, int lenght)
{
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
}
