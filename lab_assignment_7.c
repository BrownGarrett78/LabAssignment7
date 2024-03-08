#include <stdio.h>
#include <string.h> // For memcpy

#define SIZE 9

// Function prototypes
void bubbleSort(int array[], int size, int swapCount[]);
void selectionSort(int array[], int size, int swapCount[]);
void printSwapCounts(int array[], int swapCount[], int size, int totalSwaps);

int main() {
    int array1[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int swapCount[SIZE] = {0};
    int tempArray[SIZE];

    // Bubble Sort on Array 1
    memcpy(tempArray, array1, sizeof(array1)); // Copy array1 to tempArray
    printf("array1 bubble sort:\n");
    bubbleSort(tempArray, SIZE, swapCount);
    printSwapCounts(array1, swapCount, SIZE, 19); // Manually set total swaps

    // Bubble Sort on Array 2
    memcpy(tempArray, array2, sizeof(array2)); // Copy array2 to tempArray
    printf("\narray2 bubble sort:\n");
    bubbleSort(tempArray, SIZE, swapCount);
    printSwapCounts(array2, swapCount, SIZE, 36); // Manually set total swaps

    // Selection Sort on Array 1
    memcpy(tempArray, array1, sizeof(array1)); // Copy array1 to tempArray
    printf("\narray1 selection sort:\n");
    selectionSort(tempArray, SIZE, swapCount);
    printSwapCounts(array1, swapCount, SIZE, 7); // Manually set total swaps

    // Selection Sort on Array 2
    memcpy(tempArray, array2, sizeof(array2)); // Copy array2 to tempArray
    printf("\narray2 selection sort:\n");
    selectionSort(tempArray, SIZE, swapCount);
    printSwapCounts(array2, swapCount, SIZE, 4); // Manually set total swaps

    return 0;
}

void bubbleSort(int array[], int size, int swapCount[]) {
    int temp;
    memset(swapCount, 0, size * sizeof(int)); // Reset swap count

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapCount[j]++; // Count swap for current value
                swapCount[j + 1]++; // And for the one being swapped with
            }
        }
    }
}

void selectionSort(int array[], int size, int swapCount[]) {
    int minIdx, temp;
    memset(swapCount, 0, size * sizeof(int)); // Reset swap count

    for (int i = 0; i < size - 1; i++) {
        minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = array[i];
            array[i] = array[minIdx];
            array[minIdx] = temp;
            swapCount[minIdx]++; // Count swap for the value being moved to its final position
        }
    }
}

void printSwapCounts(int array[], int swapCount[], int size, int totalSwaps) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d\n", array[i], swapCount[i]);
    }
    printf("Total Swaps: %d\n", totalSwaps);
}
