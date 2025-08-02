// C++ program to sort an array in
// decreasing order of their frequency
#include "bits/stdc++.h"
using namespace std;

// Function that return the index
// upto all the array elements are
// updated.
int sortByFreq(int* arr, int n)
{

	// Initialise maxE = -1
	int maxE = -1;

	// Find the maximum element of
	// arr[]
	for (int i = 0; i < n; i++) {
		maxE = max(maxE, arr[i]);
	}

	// Create frequency array freq[]
	int freq[maxE + 1] = { 0 };

	// Update the frequency array as
	// per the occurrence of element in
	// arr[]
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	// Initialise cnt to 0
	int cnt = 0;

	// Traversing freq[]
	for (int i = 0; i <= maxE; i++) {

		// If freq of an element is
		// greater than 0 update the
		// value of arr[] at index cnt
		// & increment cnt
		if (freq[i] > 0) {

			int value = 100000 - i;
			arr[cnt] = 100000 * freq[i] + value;
			cnt++;
		}
	}

	// Return cnt
	return cnt;
}

// Function that print array arr[]
// elements in sorted order
void printSortedArray(int* arr, int cnt)
{

	// Traversing arr[] till index cnt
	for (int i = 0; i < cnt; i++) {

		// Find frequency of elements
		int frequency = arr[i] / 100000;

		// Find value at index i
		int value = 100000 - (arr[i] % 100000);

		// Traversing till frequency
		// to print value at index i
		for (int j = 0; j < frequency; j++) {
			cout << value << ' ';
		}
	}
}

// Driver code
int main()
{

	int arr[] = { 4, 4, 5, 6, 4, 2, 2, 8, 5 };

	// Size of array arr[]
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call to get cnt
	int cnt = sortByFreq(arr, n);

	// Sort the arr[] in decreasing order
	sort(arr, arr + cnt, greater<int>());

	// Function that prints elements
	// in decreasing order
	printSortedArray(arr, cnt);

	return 0;
}
