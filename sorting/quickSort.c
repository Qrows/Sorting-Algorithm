/* Author: Christian Santapaola
 * C implementation of sorting Algorithm quickSort on int array
 * Complexity Time T(n) = O(n*log(n)) in the average case
 * T(n) = O(n^2) in the worst case (it does not happen very often)
 */

#include "sorting.h"
#include "stack.h"
#include "utilArray.h"

int quickSort(int *array, int lenght, bool recursion)
{
        if ( array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
        if (recursion) {
                recursiveQuickSort(array,0,lenght - 1);
        } else {
                iterativeQuickSort(array, lenght);
        }
        return EXIT_SUCCESS;
}

int recursiveQuickSort(int *array, int start, int end)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (start < 0 || end < 0) {
                return EXIT_FAILURE;
        }
        if (start >= end ) {
                return EXIT_FAILURE;
        } else {
                int piv;
                if (partition(array, start, end, &piv)) {
                        /* if partition fails */
                        return EXIT_FAILURE;
                }
                recursiveQuickSort(array, start, piv - 1);
                recursiveQuickSort(array, piv + 1, end);
                return EXIT_SUCCESS;
        }
}

int iterativeQuickSort(int *array, int lenght)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
        if ( lenght == 1 ) {
                return EXIT_SUCCESS;
        }

        Stack *stack = malloc(sizeof(stack));

        if (stack == NULL) {
                return EXIT_FAILURE;
        }

        initializeStack(stack);
        int start = 0, end = 0, piv = 0;

        /* if push failed return with error code */
        if (push(stack, lenght - 1)) {
                return EXIT_FAILURE;
        }
        if (push(stack, 0)) {
                return EXIT_FAILURE;
        }
        /* while the stack is not empty push 
         * inside the index of sub-array to sort */
        while (!stackIsEmpty(stack)) {

                /* pop the index of the subArray to partionate*/
                if (pop(stack, &start)) {
                        return EXIT_FAILURE;
                }
                if (pop(stack, &end)) {
                        return EXIT_FAILURE;
                }

                if (partition(array, start, end, &piv)) {
                        /* if partition fails close */
                        return EXIT_FAILURE;
                }
                /*insert in the stack the two subArray to sort*/
                if (start < piv - 1) {
                        if (push(stack, piv - 1)) {
                                return EXIT_FAILURE;
                        }
                        if (push(stack, start)) {
                                return EXIT_FAILURE;
                        }
                }
                if (piv + 1 < end ) {
                        if (push(stack, end)) {
                                return EXIT_FAILURE;
                        }
                        if (push(stack, piv + 1)) {
                                return EXIT_FAILURE;
                        }
                }
        }
        return EXIT_SUCCESS;
}

int partition(int *array, int i, int f, int*returnSup)
{
        /* i = start of partition index
         *  f = end of partition index
         */
        if ( array == NULL) {
                //returnSup = NULL;
                return EXIT_FAILURE;
        }
        if ( i < 0 || f < 0) {
                //returnSup = NULL;
                return EXIT_FAILURE;
        }
        int x = array[i];
        int inf = i;
        int sup = f + 1;
        /* move 2 index one at the start the latter at the end of the array
        */
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
        *returnSup = sup;
        return EXIT_SUCCESS;
}
