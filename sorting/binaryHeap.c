#include "binaryHeap.h"

/* save the index of the last useful value */
int initializeBinaryHeap(BinaryHeap *bH,int *array, int lenght)
{
        if (bH == NULL) {
                return EXIT_FAILURE;
        }
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
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
        return EXIT_SUCCESS;
}

bool isALeaf(BinaryHeap *bH, int leafIndex)
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

int fixHeap(BinaryHeap *bH, int nodeIndex)
{       
        if ( bH == NULL) {
                return EXIT_FAILURE;
        }
        /* Check if the node is part of the binary tree */
        if (nodeIndex > bH->numOfNodes - 1) {
                return EXIT_FAILURE;
        }
        /* Check if the node is a leaf */
        if (isALeaf(bH, nodeIndex)) {
                return EXIT_SUCCESS;
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

        return EXIT_SUCCESS;
}

int heapify(BinaryHeap *bH, int rootIndex)
{
        if (bH == NULL) {
                return EXIT_FAILURE;
        }
        if ( bH->numOfNodes == 0) {
                return EXIT_FAILURE;
        }
        if (rootIndex > bH->numOfNodes - 1) {
                return EXIT_FAILURE;
        }
        heapify(bH, 2*rootIndex + 1); 
        heapify(bH, 2*rootIndex + 2);
        fixHeap(bH, rootIndex);
        return EXIT_SUCCESS;

}

int removeLastLeaf(BinaryHeap *bH)
{     /* optimize memory allocation */ 
        bH->heap[bH->numOfNodes - 1] = 0;
        bH->numOfNodes--;
        if (bH->numOfNodes < (bH->lenght)/2) {
                bH->heap = realloc(bH->heap, sizeof(int)*(bH->lenght)/2);
                if (bH->heap == NULL) {
                        return EXIT_FAILURE;
                }
                bH->lenght /= 2;
        }
        return EXIT_SUCCESS;
}


int extractMin(BinaryHeap *bH, int* returnMin)
{
        if (bH->numOfNodes < 0) {
                return EXIT_FAILURE;
        } else {
                /* swap the root with the last leaf and remove it */
                int minElem = bH->heap[0];
                bH->heap[0] = bH->heap[bH->numOfNodes - 1];
                bH->heap[bH->numOfNodes - 1] = minElem;
                removeLastLeaf(bH);
                fixHeap(bH, 0);
                *returnMin = minElem;
                return EXIT_SUCCESS;
        }
}
