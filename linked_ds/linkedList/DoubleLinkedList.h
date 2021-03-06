/*
 *
 */

#include <stdbool.h>
#include "Record.h"
#include <stdio.h>
#include <stdlib.h>

struct DoubleLinkedList {
        DoubleRecord *first;
        DoubleRecord *last;
};
typedef struct DoubleLinkedList DoubleLinkedList;

void initializeDoubleLinkedList(DoubleLinkedList *dllPtr);
int insert(DoubleLinkedList *dllptr, int elem);
bool doubleLinkedListIsEmpty(DoubleLinkedList const * const dllptr);
int deleteRecord(DoubleLinkedList *dllptr, DoubleRecord *recptr);
int deleteElem(DoubleLinkedList *dllptr, int elem);
int printDll(DoubleLinkedList const * const dlinkl);
