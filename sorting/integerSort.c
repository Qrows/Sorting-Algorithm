/* Author: Christian Santapaola
 * C implementation of sorting algorithm integerSort
 * to order an array of integer between 0 and last
 * Complexity time = O(n + k) where k is the maximum value of the
 * intervall [0,k]
 */

#include "sorting.h"

int integerSort(int *array, int lenght, int maxNum)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
        int max = 0;
        for (int i = 0 ; i < lenght; i++) {
                /* checks if there are negative value into the array*/
                if (array[i] < 0) {
                        return EXIT_FAILURE;
                } else if (array[i] > max) {
                        max = array[i];
                }
        }
        if (max > maxNum) {
                return EXIT_FAILURE;
        }
        int *mvArray = malloc(sizeof(int)*maxNum);
        if (mvArray == NULL) {
                return EXIT_FAILURE;
        }
        int i,j;
        for ( i = 0; i < maxNum; i++) {
                mvArray[i] = 0;
        }
        for ( i = 0; i < lenght; i++) {
                mvArray[array[i]]++;
        }
        j = 0;
        for ( i = 0; i < maxNum; i++) {
                while (mvArray[i] > 0) {
                        array[j] = i;
                        mvArray[i]--;
                        j++;
                }
        }
        free(mvArray);
        return EXIT_SUCCESS;
}
