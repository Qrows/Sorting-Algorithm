CC = gcc
TARGET = SortingTest
CFLAGS = -Wall -Wextra -O2 -I ./sorting -I ./linked_ds/stack -I ./linked_ds/queue
VPATH = ./sorting:./linked_ds/stack:./linked_ds/queue

CFILE = ./sorting/main.c  ./sorting/binaryHeap.c  ./sorting/bubbleSort.c  ./sorting/bucketSort.c \
	./sorting/heapSort.c  ./sorting/insertionSort.c  ./sorting/integerSort.c  ./sorting/mergeSort.c \
	./sorting/printArray.c  ./sorting/quickSort.c  ./sorting/radixSort.c  ./sorting/selectionSort.c \
	./linked_ds/queue/queue.c ./linked_ds/stack/stack.c

HEADER = ./sorting/binaryHeap.h ./sorting/utilArray.h ./linked_ds/queue/queue.h ./linked_ds/stack/stack.h

#rules
$(TARGET) : $(CFILE) $(HEADER)
	$(CC) $(CFLAGS) $(HEADER) $(CFILE) -o $(TARGET) 

.phony: clean

clean:
