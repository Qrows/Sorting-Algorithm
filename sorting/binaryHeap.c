#include "binaryHeap.h"

void initializeBinaryHeap(BinaryHeap *bH,int *array, int lenght)
{
        int *cpArray;
        cpArray = malloc(sizeof(int)*lenght);
        for (int i = 0; i < lenght; i++) {
                cpArray[i] = array[i];
        }
        free(bH->heap);
        bH->heap = cpArray;
        bH->numOfNodes = lenght;
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
        } else  if (leftSonIndex < bH->numOfNodes && rightSonIndex >= bH->numOfNodes) {
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
{      
        int *cpArray = malloc(sizeof(int)*(bH->numOfNodes - 1));
        if (cpArray != NULL) {
                if (bH->numOfNodes > 1) {
                        for (int i = 0; i < bH->numOfNodes - 1; i++) {
                                cpArray[i] = bH->heap[i];
                        }
                } else if (bH->numOfNodes == 1) {
                        cpArray[0] = bH->heap[0];
                }
                free(bH->heap);
                bH->heap = cpArray;
                bH->numOfNodes--;
        } else {
                
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
