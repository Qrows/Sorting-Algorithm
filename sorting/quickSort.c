/* Author: Christian Santapaola
 * C implementation of sorting Algorithm quickSort on int array
 * Complexity Time T(n) = O(n*log(n)) in the average case
 * T(n) = O(n^2) in the worst case (it does not happen very often)
 */

#include <stdbool.h>
#include "sorting.h"

int partition(int *, int, int);

void quickSort(int *array, int lenght, int recursion)
{
        if (recursion) {
                recursiveQuickSort(array,0,lenght - 1);
        } else {
          /* iterative not implemented yet */
        }
}

void recursiveQuickSort(int *array, int start, int end)
{
        if (start >= end ) {
                return;
        } else {
        int piv = partition(array, start, end);
        recursiveQuickSort(array, start, piv - 1);
        recursiveQuickSort(array, piv + 1, end);
        }
}

int partition(int *array, int i, int f)
{
  /* i = start of partition index
  *  f = end of partition index
  */
        int x = array[i];
        int inf = i;
        int sup = f + 1;
        while (true) {
                
                do {
                        inf++;
                } while ( inf < f && array[inf] < x);

                do {
                        sup--;
                } while ( array[sup] > x);

                if ( inf < sup ) {
                        swap(&array[inf], &array[sup]);
                } else {
                  break;
                }
        }
        swap(&array[i],&array[sup]);
        return sup;
}
