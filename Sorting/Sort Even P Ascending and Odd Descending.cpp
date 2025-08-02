// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Utility function to print
// the contents of the array
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// To do two way sort. Make comparator function
// for the inbuilt sort function of c++ such that
// odd numbers are placed before even in descending
// and ascending order respectively
bool compare(int a, int b)
{

	// If both numbers are even,
	// smaller number should
	// be placed at lower index
	if (a % 2 == 0 && b % 2 == 0)
		return a < b;

	// If both numbers are odd larger number
	// should be placed at lower index
	if (a % 2 != 0 && b % 2 != 0)
		return b < a;

	// If a is odd and b is even,
	// a should be placed before b
	if (a % 2 != 0)
		return true;

	// If b is odd and a is even,
	// b should be placed before a
	return false;
}

// Driver code
int main()
{
	int arr[] = { 1, 3, 2, 7, 5, 4 };
	int n = sizeof(arr) / sizeof(int);

	// Sort the array
	sort(arr, arr + n, compare);

	// Print the sorted array
	printArr(arr, n);

	return 0;
}

// This code is contributed by Nikhil Yadav

