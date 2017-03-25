/* Author: Christian Santapaola
 * C implementation of sorting algorithm bucketSort
 */

#include "sorting.h"
#include "queue.h"

int bucketSort(int *array , int lenght, int maxNum)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if ( lenght < 0) {
                return EXIT_FAILURE;
        }
        if ( maxNum < 0 ) {
                return EXIT_FAILURE;
        }
        Queue *bucket[maxNum];
        int i, j;
        /* initialize the Queue parameter */
        for (i = 0; i < maxNum; i++) {
                bucket[i] = malloc(sizeof(Queue));
                if (bucket[i] == NULL) {
                        return EXIT_FAILURE;
                }
                initializeQueue(bucket[i]);
        }
        /* enqueue the value */
        for (i = 0; i < lenght; i++) {
                enqueue(bucket[array[i]], array[i]);
        }
        /* deque the ordered value into the array */
        i = 0;
        j = 0;
        while(i < maxNum) {
                /* if dequeue works (the queue is not empty)*/
                if (!dequeue(bucket[i],&array[j])) {
                        j++;
                }
                if (queueIsEmpty(bucket[i])) {
                        i++;
                }
        }
        for(i = 0; i < maxNum; i++) {
                free(bucket[i]);
        }
        return EXIT_SUCCESS;
}
