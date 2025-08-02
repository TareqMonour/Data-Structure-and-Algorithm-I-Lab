#include <stdio.h>

// user-defined function that finds the peak index of the mountain array
int findPeakIndex(int array[], int size) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low < high) {
        mid = low + (high - low) / 2;

        // compares mid of the array with the next element
        if (array[mid] >= array[mid + 1]) {
            // if the above condition is true, sets high = mid
            high = mid;
        } else {
            // if the condition becomes false array[mid] >= array[mid + 1] sets low = mid + 1
            low = mid + 1;
        }
    }

    return low;
}

// driver code
int main() {
    int mountainArray[] = {4, 2, 7, 9, 8, 3, 1};
    int size = sizeof(mountainArray) / sizeof(mountainArray[0]);

    // function calling
    int peakindex = findPeakIndex(mountainArray, size);

    // prints the peak index of the mountain array
    printf("The peak index of the mountain array is: %d\n", peakindex);

    return 0;
}
