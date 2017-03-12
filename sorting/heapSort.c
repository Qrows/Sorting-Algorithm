/* Author: Christian Santapaola
 * C implementation of sorting Algorithm heapSort
 * with Binary Heap implemented with an Array
 * if i is a father index, his son's are in position 2*i + 1 and 2*i + 2
 * complexity time T(n) = O(n*log(n))
 */
#include "sorting.h"
#include "binaryHeap.h"

void heapSort(int *array, int lenght)
{
        BinaryHeap *bh = malloc(sizeof(bh));
        initializeBinaryHeap(bh, array, lenght);
        heapify(bh, 0);
        for (int i = 0; i < lenght; i++) {
                array[i] = extractMin(bh);
        }
}
