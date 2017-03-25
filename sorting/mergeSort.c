/* Author: Christian Santapaola
 * C implementation of sorting algorithm mergeSort
 * both iterative and recursive
 * Complexity Time T(n) = O(n*log(n))
 */

#include "sorting.h"

int mergeSort(int *array, int lenght, bool recursion)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }
        if (recursion) {
                recursiveMergeSort(array, 0 , lenght - 1);
        } else {
                iterativeMergeSort(array, lenght);
        }
        return EXIT_SUCCESS;

}       

int recursiveMergeSort(int *array, int start, int end)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (start < 0 || end < 0) {
                return EXIT_FAILURE;
        }

        if (start >= end) {
                return EXIT_FAILURE;
        } else {
                int m = (start + end)/2;
                recursiveMergeSort(array, start, m);
                recursiveMergeSort(array, m + 1, end);
                merge(array, start, m, end);
                return EXIT_SUCCESS;
        }
}

int iterativeMergeSort(int *array, int lenght)
{
        if (array == NULL) {
                return EXIT_FAILURE;
        }
        if (lenght <= 0) {
                return EXIT_FAILURE;
        }      
        int i;
        int shift = 1;
        int end;
        while (shift < lenght) {
                i = 0;
                while ( i < lenght - shift ) {
                        end = i + 2*shift - 1;
                        if (lenght - 1 < end) {
                                end = lenght - 1;
                        }
                        merge(array, i, i + shift - 1, end);
                        i += 2*shift;
                }
                shift *= 2;
        }
        return EXIT_SUCCESS;
}

int merge(int *array, int i1, int end1, int end2)
{
        /* merge 2 consecutive sorted sequence inside an array
         * i1 = start of the first sequence inside the array
         * end1 = end of the first sequence
         * end2 = end of the second sequence
         * */

        if ( array == NULL) {
                return EXIT_FAILURE;
        }
        if ( i1 < 0 || end1 < 0 || end2 < 0) {
                return EXIT_FAILURE;
        }
        if (end2 < i1 + 1) {
                return EXIT_FAILURE;
        }

        int lenght = end2 - i1 + 1;
        int *mvArray = malloc(sizeof(int)*lenght);

        if ( mvArray == NULL ) {
                return EXIT_FAILURE;
        }

        int i2 = end1 + 1;
        int i = 0;
        int icp = i1;
        /* copy the ordered array in mvArray*/
        while ( i1 <= end1 && i2 <= end2 ) {
                if ( array[i1] <= array[i2] ) {
                        mvArray[i] = array[i1];
                        i1++;
                        i++;
                } else {
                        mvArray[i] = array[i2];
                        i2++;
                        i++;
                }
        }
        /* copy the final element in mvArray*/
        if ( i1 <= end1 ) {
                while ( i1 <= end1 ) {
                        mvArray[i] = array[i1];
                        i1++;
                        i++;
                }
        } else { 
                while ( i2 <= end2 ) {
                        mvArray[i] = array[i2];
                        i2++;
                        i++;
                }
        }
        /* copy mvArray in array[i1:end2]*/
        i = 0;
        while ( i < lenght && icp <= end2 ) {
                array[icp] = mvArray[i];
                i++;
                icp++;
        }
        free(mvArray);
        return EXIT_SUCCESS;
}
