/* Author: Christian Santapaola
 * C implementation of sorting Algorithm quickSort on int array
 * Complexity Time T(n) = O(n*log(n)) in the average case
 * T(n) = O(n^2) in the worst case (it does not happen very often)
 */

#include <stdbool.h>
#include "sorting.h"
#include "../linked_ds/stack/stack.h"

int partition(int *, int, int);

void quickSort(int *array, int lenght, int recursion)
{
        if (recursion) {
                recursiveQuickSort(array,0,lenght - 1);
        } else {
                iterativeQuickSort(array, lenght);
        }
}

void recursiveQuickSort(int *array, int start, int end)
{
        if (start >= end ) {
                return;
        } else {
                int piv = partition(array, start, end);
                recursiveQuickSort(array, start, piv - 1);
                recursiveQuickSort(array, piv + 1, end);
        }
}

void iterativeQuickSort(int *array, int lenght)
{
        if ( lenght <= 1 ) {
                return;
        }
        Stack *stack = malloc(sizeof(stack));
        initializeStack(stack);
        if (stack == NULL) {
                printf("Run out of memory.\n");
                return;
        }
        int start = 0, end = 0, piv = 0;
        if (push(stack, lenght - 1)) {
                return ;
        }
        if (push(stack, 0)) {
                return;
        }
        /* while the stack is not empty push 
         * inside the index of sub-array to sort */
        while (!stackIsEmpty(stack)) {
                /* pop the index of the subArray to partionate*/
                if (pop(stack, &start)) {
                        return;
                }
                if (pop(stack, &end)) {
                        return;
                }
                piv = partition(array, start, end);
                /*insert in the stack the two subArray to sort*/
                if (start < piv - 1) {
                        if (push(stack, piv - 1)) {
                                         return;
                        }
                        if (push(stack, start)) {
                                         return;
                        }
                }
                if (piv + 1 < end ) {
                        if (push(stack, end)) {
                                return;
                        }
                        if (push(stack, piv + 1)) {
                                return;
                        }
                }
         }
}

int partition(int *array, int i, int f)
{
  /* i = start of partition index
  *  f = end of partition index
  */
        int x = array[i];
        int inf = i;
        int sup = f + 1;
        while (true) {
                
                do {
                        inf++;
                } while ( inf < f && array[inf] < x);

                do {
                        sup--;
                } while ( array[sup] > x);

                if ( inf < sup ) {
                        swap(&array[inf], &array[sup]);
                } else {
                  break;
                }
        }
        swap(&array[i],&array[sup]);
        return sup;
}
