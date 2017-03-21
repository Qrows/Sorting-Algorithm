/* Author: Christian Santapaola
 * C implementation of sorting algorithm integerSort
 * to order an array of integer between 0 and last
 * Complexity time = O(n)
 */

#include "sorting.h"

void integerSort(int *array, int lenght, int last)
{
       int *mvArray = malloc(sizeof(int)*last);
       int i,j;
       for ( i = 0; i < last; i++) {
                mvArray[i] = 0;
       }
       for ( i = 0; i < lenght; i++) {
                mvArray[array[i]]++;
       }
       j = 0;
       for ( i = 0; i < last; i++) {
                while (mvArray[i] > 0) {
                        array[j] = i;
                        mvArray[i]--;
                        j++;
                }
       }
       free(mvArray);
}
