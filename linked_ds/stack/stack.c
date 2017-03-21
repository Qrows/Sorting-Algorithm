/* Author: Christian Santapaola
 */

#include "stack.h"

void initializeStack(Stack *st)
{
        st->head = NULL;
}

int push(Stack *st, int elem)
{
        Record *rec = malloc(sizeof(Record));
        if ( rec == NULL) {
                return 1; /*error*/
        }
        rec->data = elem;
        if (st->head == NULL)  { 
               (st->head) = rec;
               rec->next = NULL;
        } else {
                rec->next = st->head;
                (st->head) = rec;
        }
        return 0;
}

int pop(Stack *st, int *var)
{
        if (st->head == NULL) { 
                return 1;
        }
        int elem = (st->head)->data;
        Record *recPtr =(st->head);
        (st->head) = (st->head)->next;
        recPtr->next = NULL;
        *var = elem;
        free(recPtr);
        return 0;
}

bool stackIsEmpty(Stack *st)
{
        return (st->head) == NULL;
}

int getHead(Stack *st)
{
        if ((st->head) == NULL) {
                return -1; 
        } else {
                return st->head->data;
        }
}

int printStack(Stack *st)
{
        printf("hello world!\n");
        printf("st->head = %p", st->head);
        if ((st->head) == NULL) {
                printf("NULL\n");
                return 0;
        } else {
                Record *curr = (st->head);
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
