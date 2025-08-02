#include <iostream>
using namespace std;

// Function to sort array containing 0, 1 and 2
void sort012(int arr[], int n)
{
	// Initialisation
	int l=0;
	int r=n-1;

	for(int i=0;i<n && i<=r;){
		// current element is 0
		if(arr[i]==0){
			swap(arr[l],arr[i]);
			l++;
			i++;
		}
		// current element is 2
		else if(arr[i]==2){
			swap(arr[i],arr[r]);
			r--;
		}
		// current element is 1
		else{
			i++;
		}
	}
}

// Function to print array arr[]
void printArray(int arr[], int arr_size)
{
	// Iterate and print every element
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
}

// Driver Code
int main()
{
	int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	sort012(arr, n);

	printArray(arr, n);

	return 0;
}
