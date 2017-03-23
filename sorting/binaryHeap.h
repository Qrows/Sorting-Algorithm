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

void initializeBinaryHeap(BinaryHeap* bH, int *array, int lenght);
void fixHeap(BinaryHeap *bH, int nodeIndex);
int isALeaf(BinaryHeap *bH, int leafIndex);
void heapify(BinaryHeap *bH, int rootIndex);
void removeLeaf(BinaryHeap *bH, int leafIndex);
int extractMin(BinaryHeap *bH);
