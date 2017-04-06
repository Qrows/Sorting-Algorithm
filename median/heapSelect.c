/* Author: Christian Santapaola
 * function for finding the median of a int array
 * Complexity time: O(n*log(n))
 */

#include <stdlib.h>
#include "binaryHeap.h"
#include "median.h"

int heapSelect(int *array, int lenght, int k)
{
        /*return the median value */
        if ( k > lenght ) {
                return 1;
        }
        BinaryHeap *bh = malloc(sizeof(bh));
        initializeBinaryHeap(bh, array, lenght);
        heapify(bh, 0);
        int value = 0;
        for (int i = 0; i <= k; i++) {
                extractMin(bh, &value);
        }
        free(bh);
        return value;
}

