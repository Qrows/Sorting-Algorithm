/* Author: Christian Santapaola
 * C implementation of some sorting algorithm
 */

#include <stdlib.h>
#include <stdbool.h>

/* insertionSort*/
int insertionSort(int *Array, int len, bool recursion);
/*recursive insertionSort */
int recursiveInsertionSort(int *array, int lenght);
/*iterative insertionSort */
int iterativeInsertionSort(int *array, int lenght);
/*selectionSort*/
int selectionSort(int *array, int lenght, bool recursion);
/*recursive selectionSort*/
int recursiveSelectionSort(int *array, int index , int lenght);
/*iterative selectionSort*/
int iterativeSelectionSort(int *array, int lenght);
/* bubbleSort */
int bubbleSort(int *array, int lenght);
/* heapSort */
int heapSort(int *array, int lenght);
/*mergeSort*/
int mergeSort(int *array, int lenght, bool recursion);
/* merge procedure */
int merge(int*array, int start, int piv, int end);
/*recursive mergeSort*/
int recursiveMergeSort(int *array, int start ,int end);
/*iterative mergeSort*/
int iterativeMergeSort(int *array, int lenght);
/* quickSort */
int quickSort(int *array, int lenght, bool recursion);
/* partition function for quicksort */
int partition(int *array, int i,int f, int *returnSup);
/* recursive quickSort*/
int recursiveQuickSort(int *array, int start, int end);
/* iterative quickSort */
int iterativeQuickSort(int *array, int lenght);
/*integerSort*/
int integerSort(int *array, int lenght, int end);
/* bucketSort */
int bucketSort(int *array, int lenght, int maxNum);
/* radixSort */
int radixSort(int *array, int lenght);
