/*
 *
 */

#include "queue.h"

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

Record *dequeue(Queue *queue)
{
        /* deque the first record on the queue
         * return a pointer to the removed first Record */
        if ( queue->first == NULL) {
                return NULL;
        } else {
                Record *recPtr = queue->first;
                queue->first = (queue->first)->next;
                if (queue->first != NULL) {
                        queue->first->prev = NULL;
                } else {
                        queue->last = NULL;
                }
                return recPtr;
        }
}

bool isEmpty(Queue *queue)
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
