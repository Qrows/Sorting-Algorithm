/* Author: Christian Santapaola
 * C implementation of a Queue data structure made with linked list
 * for store int data;
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Record {
        int data;
        struct Record *next;
        struct Record *prev;
};
typedef struct Record Record;

struct Queue {
        Record *first;
        Record *last;
};
typedef struct Queue Queue;

int initializeQueue(Queue *queue);
int enqueue(Queue *queue, int data);
int dequeue(Queue *queue, int *returnValue);
bool isEmpty(Queue *queue);
void printQueue(Queue *queue);
