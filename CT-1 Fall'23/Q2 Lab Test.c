#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int lastOcc = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int currentElement = arr[mid];
        int frequency = 1;

        while (mid < right && arr[mid] == arr[mid + 1]) {
            frequency++;
            mid++;
        }

        if (frequency == target) {
            lastOcc = arr[mid];
            left = mid + 1;
        } else if (frequency < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return lastOcc;
}

int main() {
    //int sorted_arr[] = {3, 4, 4, 5, 5, 5, 5, 6, 6, 7, 8};
    int sorted_arr[]={5,5,5,5,4,4,6,6,7,8,3};
    int targetFrequency = 2;
    int n = sizeof(sorted_arr) / sizeof(sorted_arr[0]);

    int lastOcc = binarySearch(sorted_arr, n, targetFrequency);

    if (lastOcc != -1) {
        printf("Last occurrence of %d with frequency %d is %d\n", targetFrequency, lastOcc, lastOcc);
    } else {
        printf("Element with frequency %d not found\n", targetFrequency);
    }

    return 0;
}
