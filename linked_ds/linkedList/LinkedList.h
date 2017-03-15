/*
 *
 */

#include "Record.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
        Record *first;
        Record *last;
};
typedef struct LinkedList LinkedList;

void initializeLinkedList(LinkedList *llptr);
int insert(LinkedList *llptr, int elem);
int popFirst(LinkedList *llptr,int *retVal);
bool linkedListIsEmpty(LinkedList const * const llptr);
int printLl(LinkedList const * const llptr);
