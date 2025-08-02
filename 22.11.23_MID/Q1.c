#include<stdio.h>
void sortInWaveForm(int arr[], int n)
{
	Sort(arr,n);
	for (int i=0; i<n-1; i += 2)
		swap(&arr[i], &arr[i+1]);
}
void Sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int arr[] = {3,2,1,4};
	//printf("The Given Array is: %d", arr[]);
	int n = sizeof(arr)/sizeof(arr[0]);
	sortInWaveForm(arr, n);
    printf("Sorted Array in Wave Form is: ");
	for (int i=0; i<n; i++)
	printf("%d ",arr[i]);
	return 0;
}


