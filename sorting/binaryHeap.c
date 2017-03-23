#include "binaryHeap.h"

/* save the index of the last useful value */
void initializeBinaryHeap(BinaryHeap *bH,int *array, int lenght)
{
        if (lenght == 0) {
                return;
        }
        int len = lenght, i = 1;
        while ( len != 0) {
                len /= 2;
                i *= 2;
        }
        bH->lenght = i; 
        bH->numOfNodes = lenght;
        bH->heap = malloc(sizeof(int)*bH->lenght);
        for (int i = 0; i < bH->numOfNodes; i++) {
                bH->heap[i] = array[i];
        }
}

int isALeaf(BinaryHeap *bH, int leafIndex)
{
        /* Return true if the input node is a leaf, false otherwise */
        int leftSon = 2*leafIndex + 1;
        int rightSon = 2*leafIndex + 2;
        if (leftSon > bH->numOfNodes - 1 && rightSon >bH->numOfNodes - 1) {
          return true;
        } else {
          return false;
        }
}

void fixHeap(BinaryHeap *bH, int nodeIndex)
{       
        /* Check if the node is part of the binary tree */
        if (nodeIndex > bH->numOfNodes - 1) {
                return;
        }
        /* Check if the node is a leaf */
        if (isALeaf(bH, nodeIndex)) {
                return;
        }
            
        /* find the son with the minimum key */
        int minSonIndex; 
        int leftSonIndex = 2*nodeIndex + 1;
        int rightSonIndex = 2*nodeIndex + 2;

        if (leftSonIndex < bH->numOfNodes && rightSonIndex < bH->numOfNodes) {
                if (bH->heap[leftSonIndex] < bH->heap[rightSonIndex]) {
                        minSonIndex = leftSonIndex;
                } else {
                        minSonIndex = rightSonIndex;
                }
        } else {
                minSonIndex = leftSonIndex;
                
        }

        /* fix heap order property */

        if (bH->heap[nodeIndex] > bH->heap[minSonIndex]) {
                int tmp = bH->heap[nodeIndex];
                bH->heap[nodeIndex] = bH->heap[minSonIndex];
                bH->heap[minSonIndex] = tmp;
                fixHeap(bH, minSonIndex);
        }
}

void heapify(BinaryHeap *bH, int rootIndex)
{
        if ( bH->numOfNodes == 0) {
                return;
        }
        if (rootIndex > bH->numOfNodes - 1) {
                return;
        }
        heapify(bH, 2*rootIndex + 1); 
        heapify(bH, 2*rootIndex + 2);
        fixHeap(bH, rootIndex);

}

void removeLastLeaf(BinaryHeap *bH)
{     /* optimize memory allocation */ 
        bH->heap[bH->numOfNodes - 1] = 0;
        bH->numOfNodes--;
        if (bH->numOfNodes < (bH->lenght)/2) {
                bH->heap = realloc(bH->heap, sizeof(int)*(bH->lenght)/2);
                bH->lenght /= 2;
        }
}


int extractMin(BinaryHeap *bH)
{
        if (bH->numOfNodes < 0) {
                return 0;
        } else {
                /* swap the root with the last leaf and remove it */
                int minElem = bH->heap[0];
                bH->heap[0] = bH->heap[bH->numOfNodes - 1];
                bH->heap[bH->numOfNodes - 1] = minElem;
                removeLastLeaf(bH);
                fixHeap(bH, 0);
                return minElem;
        }
}
