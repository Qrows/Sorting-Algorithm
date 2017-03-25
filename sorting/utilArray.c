/* Author: Christian Santapaola
 * some utility for print an int array
 */

#include <stdio.h>
#include <stdlib.h>
#include "utilArray.h"

void swap(int *elem1, int *elem2) {
        int tmp = *elem1;
        *elem1 = *elem2;
        *elem2 = tmp;
}

void printIntArray(int *Array, int *lenght)
{
        printf("[ ");
        for (int i = 0; i < *lenght; i++) {

          if ( i != *lenght - 1 ) {
                printf("%d, ", Array[i]);
          } else {
                printf("%d", Array[i]);
          }

          if ( i % 15 == 0 && i != 0 ) { 
            /* per non andare a capo al primo elemento(i = 0) */
            printf("\n  ");
          }
        }
        printf("]\n");
}

void printDoubleArray(double *Array, int *lenght)
{
        printf("[ ");

        for (int i = 0; i < *lenght; i++) {

          if ( i != *lenght - 1 ) {
                printf("%.2f, ", Array[i]);
          } else {
                printf("%.2f", Array[i]);
          }

          if (i % 15 == 0 && i != 0 ) {
            printf("\n  ");
          }
        }

        printf("]\n");
}

void randomValue(int *array,int lenght, int maxValue)
{
        for ( int i = 0; i < lenght; i++) {
                array[i] = rand() % maxValue;
        }
}

void copyArray(int *array, int* cpArray, int lenght)
{
  for ( int i = 0; i < lenght; i++) {
        array[i] = cpArray[i];
  }
}
