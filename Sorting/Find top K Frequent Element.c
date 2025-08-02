#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an element and its frequency
typedef struct {
    int element;
    int frequency;
} ElementFrequency;

// Min-heap comparison function for ElementFrequency
int compare(const void *a, const void *b) {
    return ((ElementFrequency *)a)->frequency - ((ElementFrequency *)b)->frequency;
}

// Function to find the top k frequent elements
void topKFrequent(int nums[], int numsSize, int k) {
    // Create a hash map to store element frequencies
    int *frequencyMap = (int *)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        frequencyMap[nums[i]]++;
    }

    // Create an array of ElementFrequency structures
    ElementFrequency *elementFrequency = (ElementFrequency *)malloc(numsSize * sizeof(ElementFrequency));
    for (int i = 0; i < numsSize; i++) {
        elementFrequency[i].element = i; // Assuming elements are non-negative integers
        elementFrequency[i].frequency = frequencyMap[i];
    }

    // Create a min-heap to store the top k frequent elements
    qsort(elementFrequency, numsSize, sizeof(ElementFrequency), compare);

    // Print the top k frequent elements
    printf("Top %d frequent elements: ", k);
    for (int i = numsSize - 1; i >= numsSize - k; i--) {
        printf("%d ", elementFrequency[i].element);
    }
    printf("\n");

    // Free allocated memory
    free(frequencyMap);
    free(elementFrequency);
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    printf("Input array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    topKFrequent(nums, numsSize, k);

    return 0;
}

