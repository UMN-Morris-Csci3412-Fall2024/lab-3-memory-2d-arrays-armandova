#include "mergesort.h"
#include <stdlib.h>

void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
    int leftSize = midPoint - startIndex;
    int rightSize = endIndex - midPoint;
    
    int *leftArray = (int *)malloc(leftSize * sizeof(int));
    int *rightArray = (int *)malloc(rightSize * sizeof(int));

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = values[startIndex + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArray[i] = values[midPoint + i];
    }

    int leftIndex = 0, rightIndex = 0, sortedIndex = startIndex;
    int leftMax = leftSize - 1;
    int rightMax = rightSize - 1;

    while (leftIndex <= leftMax && rightIndex <= rightMax) {

        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            values[sortedIndex++] = leftArray[leftIndex++];
        } else {
            values[sortedIndex++] = rightArray[rightIndex++];
        }

        if (leftArray[leftMax] >= rightArray[rightMax]) {
            values[--endIndex] = leftArray[leftMax--];
        } else {
            values[--endIndex] = rightArray[rightMax--];
        }
    }

    while (leftIndex <= leftMax) {
        values[sortedIndex++] = leftArray[leftIndex++];
    }

    while (rightIndex <= rightMax) {
        values[sortedIndex++] = rightArray[rightIndex++];
    }
    free(leftArray);
    free(rightArray);
}

void mergesort(int size, int values[]) {
   // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  //
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.
    for (int currentSize = 1; currentSize < size; currentSize *= 2) {
        for (int startIndex = 0; startIndex < size - currentSize; startIndex += 2 * currentSize) {
            int midPoint = startIndex + currentSize;
            int endIndex = (startIndex + 2 * currentSize < size) ? startIndex + 2 * currentSize : size;

            mergeRanges(values, startIndex, midPoint, endIndex);
        }
    }
}
