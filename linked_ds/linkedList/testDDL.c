#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

int main(int argc, char *argv[])
{
        if ( argc != 2) {
                printf("usage: %s numberOfInsert\n", argv[0]);
                return 1;
        }
        int end = strtoul(argv[1], NULL, 10);
        //int end = atoi(argv[1]);
        DoubleLinkedList *dll = malloc(sizeof(dll));
        printf("DoubleLinkedList\n");
        printf("isEmpty = %i\n", isEmpty(dll));
        for ( int i = 0; i < end; i++) {
                insert(dll, i);               
        }
        printDll(dll);
        for ( int i = end; i >= 0; i--) {
                printf("deleteElem(elem = %d)\n",i);
                deleteElem(dll, i);
                printDll(dll);
        }
        printDll(dll);
        printf("isEmpty = %i\n", isEmpty(dll));
        return 0;
}  
