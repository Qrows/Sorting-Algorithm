/* Author: Christian Santapaola
 * C implementation of radixSort algorithm
 */

#include "sorting.h"
#include "../linked_ds/queue/queue.h"

void radixSort( int *array, int lenght)
{
        if ( lenght <= 1) {
                return;
        }
        int max = array[0];
        int i, j;
        int digit = 1;

        Queue *bucket[10];
        for (i = 0; i < 10; i++) {
                bucket[i] = malloc(sizeof(Queue));
                initializeQueue(bucket[i]);
        }
        for (i = 0; i < lenght; i++) {
                if (array[i] > max) {
                        max = array[i];
                }
        }
        while ( max / digit != 0) {
                for ( i = 0; i < lenght; i++) {
                        enqueue(bucket[ (array[i]/digit) % 10 ], array[i]);
                }
                i = 0;
                j = 0;
                while ( j < 10 ) {
                        if (!dequeue(bucket[j], &array[i])) {
                                i++;
                        }
                        if (queueIsEmpty(bucket[j])) {
                                j++;
                        }
                }
                digit *= 10;
        }
        for (i = 0; i < 10; i++) {
                free(bucket[i]);

        }
}



