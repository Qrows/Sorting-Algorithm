CC = gcc
TARGET = MedianTest
CFLAGS = -Wall -Wextra -O2 -I ../sorting -I ../linked_ds/stack
VPATH = ../sorting:../linked_ds/stack

CFILE = test.c ../sorting/binaryHeap.c  ../sorting/utilArray.c \
       	../sorting/quickSort.c ../linked_ds/stack/stack.c heapSelect.c quickSelect.c

HEADER = ../sorting/binaryHeap.h ../sorting/utilArray.h median.h ../linked_ds/stack/stack.h

#rule
$(TARGET) : $(CFILE) $(HEADER)
	$(CC) $(CFLAGS) $(HEADER) $(CFILE) -o $(TARGET)	

.phony: clean

clean:
