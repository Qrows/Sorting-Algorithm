/*
 */
#include "queue.h"

int main(int argc, char *argv[])
{
        if ( argc != 2 ) {
                printf("Usage: %s numOfEnqueue/Dequeue\n", argv[1]);
        } else {
                int num = strtol(argv[1], NULL, 10);
                Queue *queue = malloc(sizeof(queue));
                printf("isEmpty(queue) = %d\n", isEmpty(queue));
                for (int i = 0; i < num; i++) {
                        printf("enqueue(queue, %d)\n", i);
                        enqueue(queue, i);
                        printQueue(queue);
                }
                printf("isEmpty(queue) = %d\n", isEmpty(queue));
                printf("printQueue(queue)\n");
                printQueue(queue);
                int deque;
                for (int i = 0; i < num; i++) {
                        printf("dequeue(queue)");
                        dequeue(queue, &deque);
                        printf(" = %d\n", deque);
                        printf("isEmpty(queue) = %d\n", isEmpty(queue));
                        printQueue(queue);

                }
                printf("isEmpty(queue) = %d\n", isEmpty(queue));
        }

}
