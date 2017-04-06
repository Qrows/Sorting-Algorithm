#include "median.h"
#include "utilArray.h"
#include "sorting.h"
#include <time.h>
#include <errno.h>

int main(int argc, char *argv[])
{
        if (argc != 2) {
                printf("Usage: %s <array_lenght>\n", argv[0]);
                return EXIT_FAILURE;
        }
        char *errorPtr = NULL;
        errno = 0;
        int lenght = strtol(argv[1], &errorPtr, 10);
        if (*errorPtr != '\0') {
                fprintf(stderr, "%s is an invalid Number!\n", argv[1]);
                return EXIT_FAILURE;
        } else if ( errno == ERANGE) {
                fprintf(stderr, "Overflow detected!,%s is too big!\n",
                                argv[1]);
                return EXIT_FAILURE;
        }
        int *array = malloc(sizeof(int) * lenght);
        if (array == NULL) {
                fprintf(stderr,
                        "Run out of memory!\n"
                        "Malloc can't allocate new memory!\n");
                return EXIT_FAILURE;
        }
        int *cpArray = malloc(sizeof(int) * lenght);
        if (cpArray == NULL) {
                fprintf(stderr, 
                        "Run out of memory!\n"
                        "Malloc can't allocate new memory!\n");
                return EXIT_FAILURE;
        }
        int median;
        int qmedian;
        srand(time(NULL));


        randomValue(array, lenght, 4*lenght);
        copyArray(cpArray , array, lenght);
        printIntArray(array, &lenght);
        
        median = heapSelect(array, lenght, lenght/2);
        copyArray(array, cpArray, lenght);
        qmedian = quickSelect(array, 0, lenght - 1, lenght/2);
        quickSort(array, lenght, 0);
        printIntArray(array, &lenght);
        
        free(array);
        free(cpArray);
        
        printf("median is %d\nqmedian is %d\n", median, qmedian);
        return EXIT_SUCCESS;
}
