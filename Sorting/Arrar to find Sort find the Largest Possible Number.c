#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    char ab[20], ba[20];

    // Convert numbers to strings and concatenate for comparison
    sprintf(ab, "%d%d", *(const int*)a, *(const int*)b);
    sprintf(ba, "%d%d", *(const int*)b, *(const int*)a);

    // Compare the concatenated strings
    return strcmp(ba, ab);
}

// Function to find the largest possible number
void findLargestNumber(int arr[], int n) {
    // Sort the array using custom comparison function
    qsort(arr, n, sizeof(arr[0]), compare);

    // Print the sorted array as the largest possible number
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {82, 12, 8, 10, 3, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Input array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Largest possible number: ");
    findLargestNumber(arr, n);

    return 0;
}

