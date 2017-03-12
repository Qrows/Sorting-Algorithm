/*
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main(int argc, char *argv[])
{
        if ( argc != 2) {
                printf("usage: %s numberOfInsert\n", argv[0]);
                return 1;
        }
        int end = strtoul(argv[1], NULL, 10);
        //int end = atoi(argv[1]);
        LinkedList *ll = malloc(sizeof(ll));
        printf("LinkedList\n");
        printf("isEmpty = %i\n", isEmpty(ll));
        for ( int i = 0; i < end; i++) {
                insert(ll, i);               
        }
        printLl(ll);
        for ( int i = 0; i < end; i++) {
                printf("popfirst = %d\n", popFirst(ll));
                printLl(ll);
        }
        printLl(ll);
        printf("isEmpty = %i\n", isEmpty(ll));
        return 0;
}       
