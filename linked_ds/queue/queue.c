/*
 *
 */

#include "queue.h"

void initializeQueue(Queue *queue)
{
        queue->first = NULL;
        queue->last = NULL;
}

int enqueue(Queue *queue, int data)
{
        Record *rec = malloc(sizeof(rec));
        if (rec == NULL) {
                printf("Runned out of Memory!\n");
                return 1;
        }
        rec->data = data;
        if ( queue->first == NULL) {
                queue->first = rec;
                queue->last = rec;
                return 0;
        } else {
                rec->prev = queue->last;
                (queue->last)->next = rec;
                queue->last = rec;
                return 0;
        }
}

int dequeue(Queue *queue, int *returnValue)
{
        /* deque the first record on the queue
         * return a pointer to the removed first Record */
        if ( queue->first == NULL) {
                return 1;
        } else {
                Record *recPtr = queue->first;
                int val = queue->first->data;
                queue->first = (queue->first)->next;
                if (queue->first != NULL) {
                        queue->first->prev = NULL;
                } else {
                        queue->last = NULL;
                }
                free(recPtr);
                *returnValue = val;
                return 0;
        }
}

bool queueIsEmpty(Queue *queue)
{
        if (queue->first == NULL) {
                return true;
        } else {
                return false;
        }
}

void printQueue(Queue *queue)
{
        if (queue->first == NULL) {
                printf("NULL\n");
        } else {
                Record *curr = queue->first;
                while (curr != NULL) {
                        if ( curr->next != NULL ) {
                                printf("%d<-", curr->data);
                        } else {
                                printf("%d;\n", curr->data);
                        }
                        curr = curr->next;
                }
        }
} 
