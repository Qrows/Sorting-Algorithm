/* Author: Christian Santapaola
 * C implementation of some sorting algorithm
 */

#include <stdlib.h>
#include <stdbool.h>

/* insertionSort*/
void insertionSort(int *Array, int len, int recursion);
/*recursive insertionSort */
void recursiveInsertionSort(int *array, int lenght);
/*iterative insertionSort */
void iterativeInsertionSort(int *array, int lenght);
/*selectionSort*/
void selectionSort(int *array, int lenght, int recursion);
/*recursive selectionSort*/
void recursiveSelectionSort(int *array, int index , int lenght);
/*iterative selectionSort*/
void iterativeSelectionSort(int *array, int lenght);
/* bubbleSort */
void bubbleSort(int *array, int lenght);
/* heapSort */
void heapSort(int *array, int lenght);
/*mergeSort*/
void mergeSort(int *array, int lenght, int recursion);
/*recursive mergeSort*/
void recursiveMergeSort(int *array, int start ,int end);
/*iterative mergeSort*/
void iterativeMergeSort(int *array, int lenght);
/* quickSort */
void quickSort(int *array, int lenght, int recursion);
/* recursive quickSort*/
void recursiveQuickSort(int *array, int start, int end);
/* iterative quickSort */
void iterativeQuickSort(int *array, int lenght);
/*integerSort*/
void integerSort(int *array, int lenght, int end);
/* bucketSort */
void bucketSort(int *array, int lenght, int maxNum);
/* radixSort */
void radixSort(int *array, int lenght);
