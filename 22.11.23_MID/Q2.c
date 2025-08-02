#include <stdio.h>

int findMin(int nums[], int numsSize) {
    int left = 0;
    int right = numsSize - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int nums[] = {3,4,5,1,2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int minElement = findMin(nums, numsSize);
    //printf("The Original Array was: %d ", nums[]);
    printf("The original Array was Rotated in : %d Times\n", minElement);

    return 0;
}


