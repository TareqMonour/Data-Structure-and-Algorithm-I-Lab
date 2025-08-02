#include<stdio.h>
void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    for(int boundaryLine=n-2; boundaryLine>=0; boundaryLine--)
    {
        for(int i=0; i<=boundaryLine; i++)
        {
            if(arr[i]<arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}


int main()
{
    int arr[11]={4,5,6,5,3,6,7,8,4,5,5};
    int n = 11;
    printArray(arr, n);
    bubbleSort(arr, n);
    printArray(arr, n);
    return 0;
}
