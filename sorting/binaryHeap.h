/* Author: Christian Santapaola
 * C implementation of a Binary Heap data struct for order int.
 * - add check for memory error.
 */

#include <stdlib.h>
#include <stdbool.h>

struct binaryHeap {

        int *heap;
        int numOfNodes;
        int lenght;
};
typedef struct binaryHeap BinaryHeap;

int initializeBinaryHeap(BinaryHeap* bH, int *array, int lenght);
int fixHeap(BinaryHeap *bH, int nodeIndex);
bool isALeaf(BinaryHeap *bH, int leafIndex);
int heapify(BinaryHeap *bH, int rootIndex);
int removeLeaf(BinaryHeap *bH, int leafIndex);
int extractMin(BinaryHeap *bH, int* returnMin);
