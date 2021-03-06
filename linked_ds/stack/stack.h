/* Author: Christian Santapaola
 * C implementation of Stack data structure implemented by linked list
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Record {
        int data;
        struct Record *next;
};
typedef struct Record Record;

struct Stack {
        Record *head;
};
typedef struct Stack Stack;

void initializeStack(Stack *stack);
int push(Stack *, int elem);
int pop(Stack *st, int *var);
bool stackIsEmpty(Stack *);
int getHead(Stack *);
int printStack(Stack *);
