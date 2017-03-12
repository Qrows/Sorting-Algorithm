/*
 *
 */

 #include "stack.h"

int main(int argc, char *argv[])
{       
        if (argc != 2) {
          printf("Usage: %s numberOfInsert\n", argv[0]);
          return 1;
        }
        Stack *stack = malloc(sizeof(stack));
        int end = strtol(argv[1], NULL, 10);
        printf("isEmpty() = %i\n", isEmpty(stack));

        for (int i = 0; i < end; i++) {
                push(stack, i);
                printf("getHead() = %d\n", getHead(stack));
        }
        //printStack(stack);
        for (int i = 0; i < end; i++) {
                printf("pop() = %d\n", pop(stack));
                //printStack(stack);
        }
        printf("isEmpty() = %i\n", isEmpty(stack));
}

