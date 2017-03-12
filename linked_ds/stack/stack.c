/* Autore: Christian Santapaola
 * implementazione C di una struttura dati stack o pila
 */

#include "stack.h"


int push(Stack *st, int elem)
{
        Record *rec = malloc(sizeof(rec));
        if ( rec == NULL) {
                return 1; /*error*/
        }
        rec->data = elem;
        if (st->head == NULL) {
               st->head = rec;
        } else {
                rec->next = st->head;
                st->head = rec;
        }
        return 0;
}

int pop(Stack *st)
{
        int elem = st->head->data;
        Record *recPtr = st->head;
        st->head = st->head->next;
        free(recPtr);
        return elem;
}

bool isEmpty(Stack *st)
{
        return st->head == NULL;
}

int getHead(Stack *st)
{
        if (st->head == NULL) {
        
        } else {
                return st->head->data;
        }
}

int printStack(Stack *st)
{
        if (st->head == NULL) {
                printf("NULL\n");
                return 0;
        } else {
                Record *curr = st->head;
                while ( curr != NULL) {
                        if ( curr->next != NULL) {
                                printf("%d->", curr->data);
                        } else {
                                printf("%d\n", curr->data);
                        }
                        curr = curr->next;
                }
                return 0;
        }
}
