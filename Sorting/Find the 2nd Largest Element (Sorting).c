// C program to find second largest element in an array
#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int cmpfunc(const void* a, const void* b)
{
	return (*(int*)b - *(int*)a);
}

/* Function to print the second largest elements */
void print2largest(int arr[], int arr_size)
{
	// sort the array in descending order
	qsort(arr, arr_size, sizeof(int), cmpfunc);
	// start from second element as first
	// element is the largest
	for (int i = 1; i < arr_size; i++) {
		// if the element is not equal
		// to the largest element
		if (arr[i] != arr[0]) {
			printf("The second largest element is %d\n",
				arr[i]);
			return;
		}
	}
	printf("There is no second largest element\n");
}

/* Driver program to test above function */
int main()
{
	int arr[] = { 12, 35, 1, 10, 34, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	print2largest(arr, n);
	return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
