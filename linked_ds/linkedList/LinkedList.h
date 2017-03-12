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

int insert(LinkedList *llptr, int elem);
int popFirst(LinkedList *llptr);
bool isEmpty(LinkedList const * const llptr);
int printLl(LinkedList const * const llptr);
