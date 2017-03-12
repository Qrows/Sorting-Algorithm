/* Author: Christian Santapaola
 * C implementation of some sorting algorithm
 */


/* print in the standard output an int array */
void printIntArray(int *array, int *lenghtPtr);
/* print in the standard output a double array */
void printDoubleArray(double *array, int *lenghtPtr);
/* swap 2 element inside an Array */
void swap(int *elem1, int *elem2);

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
/*integerSort*/
void integerSort(int *array, int lenght, int end);
