/* Author:Christian Santapaola
 * C implementation of Linked List data structure
 */

#include "LinkedList.h"

int insert(LinkedList *linkl, int elem)
{
        Record *rec = malloc(sizeof(rec));
        if (rec == NULL ) {
                return 1; /*error*/
        }
        rec->data = elem;
        if ( linkl->first == NULL ) {
                linkl->first = rec;
                linkl->last = rec;
        } else {
                linkl->last->next = rec;
                linkl->last = rec;
        }
        return 0;/*all went fine*/
}

int popFirst(LinkedList *linkl)
{
        int retData = linkl->first->data;
        Record *recPtr = linkl->first;
        linkl->first = linkl->first->next;
        free(recPtr);
        return retData;
}

bool isEmpty(LinkedList const * const linkl)
{
        return linkl->first == NULL;
}

int printLl(LinkedList const * const linkl)
{
        if (isEmpty(linkl)) {
                printf("NULL\n");
                return 0;
        } else {
                Record *curr = linkl->first;
                while (curr != NULL) {
                        if (curr->next != NULL) {
                                printf("%d->", curr->data);
                        } else {
                                printf("%d;\n", curr->data);
                        }
                        curr = curr->next;
                }
                return 0;
        }
}
