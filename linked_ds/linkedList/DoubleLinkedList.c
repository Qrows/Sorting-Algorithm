/*
 *
 */

#include "DoubleLinkedList.h"

void initializeDoubleLinkedList(DoubleLinkedList *dlinkl)
{
        /* set pointer to first and last to NULL*/
        dlinkl->first = NULL;
        dlinkl->last = NULL;
}

int insert( DoubleLinkedList *dlinkl, int elem)
{
        DoubleRecord *rec = malloc(sizeof(rec));
        if ( rec == NULL) {
                return 1;
        }
        rec->data = elem;
        rec->prev = NULL;
        rec->next = NULL;
        if ( dlinkl->first == NULL) {
                dlinkl->first = rec;
                dlinkl->last = rec;
        } else {
                dlinkl->last->next = rec;
                rec->prev = dlinkl->last;
                dlinkl->last = rec;
        }
        return 0; 
}

bool doubleLinkedListIsEmpty(DoubleLinkedList const * const dlinkl)
{
        if (dlinkl->first == NULL) {
                return true;
        } else {
                return false;
        }
}

int deleteRecord(DoubleLinkedList *dlinkl,DoubleRecord *rec)
{ /* delete a given record on the double linked list */
        if ( dlinkl->first == rec ) {
                if (rec->next != NULL) {
                        (rec->next)->prev = NULL;
                } 
                dlinkl->first = rec->next;
                rec->next = NULL;
                free(rec);
        } else if ( dlinkl->last == rec) {
                (rec->prev)->next = NULL;
                dlinkl->last = rec->prev;
                rec->prev = NULL;
                free(rec);
        } else {
                (rec->prev)->next = rec->next;
                (rec->next)->prev = rec->prev;
                free(rec);
        }
        return 0;
}

int deleteElem(DoubleLinkedList *dlinkl, int elem)
{
        DoubleRecord *currs, *currl;
        currs = dlinkl->first; // current from start
        currl = dlinkl->last;  // current from last
        while (currs != NULL && currl != NULL) {
                if (currs->data == elem) {
                        deleteRecord(dlinkl, currs);
                        return 0;
                } else if (currl->data == elem) {
                        deleteRecord(dlinkl, currl);
                        return 0;
                }

          currs = currs->next;
          currl = currl->prev;
        }
        return 1;
}

int printDll(DoubleLinkedList const * const dlinkl)
{
        if (doubleLinkedListIsEmpty(dlinkl)) {
                printf("NULL\n");
                return 0;
        } else {
                DoubleRecord *curr = dlinkl->first;
                while (curr != NULL) {
                        if (curr->next != NULL) {
                                printf("<-%d->", curr->data);
                        } else {
                                printf("<-%d;\n", curr->data);
                        }
                        curr = curr->next;
                }
                return 0;
        }
}
