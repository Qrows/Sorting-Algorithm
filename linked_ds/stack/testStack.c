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
        int result;
        for (int i = 0; i < end; i++) {
                push(stack, i);
                push(stack, 100 + i);
                pop(stack, &result);
        }
        printStack(stack);

        for (int i = 0; i < end; i++) {
                pop(stack, &result);
                printf("pop() = %d\n", result);
                printStack(stack);
        }
        printf("isEmpty() = %i\n", isEmpty(stack));
}

