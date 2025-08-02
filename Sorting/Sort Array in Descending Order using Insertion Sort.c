#include <stdio.h>
void print_array(int arr[], int size)
{
for (int i = 0; i < size; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
}
void insertion_sort(int arr[], int size)
{
for (int step = 1; step < size; step++)
{
int key = arr[step];
int j = step - 1;
while (key > arr[j] && j >= 0)
{
// For ascending order, change key> arr[j] to key < arr[j].
arr[j + 1] = arr[j];
--j;
}
arr[j + 1] = key;
}
}
int main()
{
int arr[] = {15, 50, -27, -4, 10};
int size = sizeof(arr) / sizeof(arr[0]);
insertion_sort(arr, size);
printf("Sorted array in descending order:\n");
print_array(arr, size);
}

