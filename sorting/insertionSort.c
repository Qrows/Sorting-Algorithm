/* Author: Christian Santapaola
 * C implementation of sorting algorithm insertionSort on int array
 * Order an array in cresent order
 * Complexity time T(n) = O(n^2)
 */
#include "sorting.h"
#include <stdio.h>

void insertionSort(int *Array, int lenght, int recursion)
{ /* choose beetween the recursive implementation or the iterative one.*/
  if (recursion != 0) {
    recursiveInsertionSort(Array, lenght);
  } else {
    iterativeInsertionSort(Array, lenght);
  }
}

void recursiveInsertionSort(int *array, int lenght)
{
  if (lenght < 1) {

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
  }
}

void iterativeInsertionSort(int *array, int lenght)
{
  int val, i, j;
  for ( i = 0; i < lenght; i++) {
    /* The Array between 0 and i is ordered */
    val = array[i];
    for ( j = i - 1; j >= 0 && array[j] > val; j--) {
      array[j + 1] = array[j];
  }
    array[j + 1] = val;
  }
}
