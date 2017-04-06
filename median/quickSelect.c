/* Author: Christian Santapaola
 * C implementation of heapSelect algorithm for finding the median of an 
 * int array
 */

#include "median.h"
#include "sorting.h"

int quickSelect(int *array, int start,int end, int k)
{
        int pivot;
        partition(array, start, end, &pivot);
        if (k > pivot) {
                return quickSelect(array, pivot + 1, end, k);        
        } else if ( k < pivot) {
                return quickSelect(array, start, pivot - 1, k);
        } else {
                return array[k];
        }
}
