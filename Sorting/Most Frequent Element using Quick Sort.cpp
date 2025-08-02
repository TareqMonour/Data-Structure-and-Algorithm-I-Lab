#include <bits/stdc++.h>
using namespace std;

struct ele {
	int val, count;
};

void swap(struct ele* a, struct ele* b)
{
	struct ele temp = *a;
	*a = *b;
	*b = temp;
}

int partition(struct ele arr[], int low, int high)
{
	struct ele pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j].count < pivot.count || (arr[j].count == pivot.count && arr[j].val > pivot.val)) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}

	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quicksort(struct ele arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

void sortByFrequency(int arr[], int n)
{
	struct ele element[n];
	for (int i = 0; i < n; i++) {
		element[i].val = arr[i];
		element[i].count = 0;
	}

	for (int i = 0; i < n; i++) {
		int j;
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j])
				break;

		if (i == j)
			element[i].count++;
		else
			element[j].count++;
	}

	quicksort(element, 0, n - 1);

	for (int i = n - 1, index = 0; i >= 0; i--) {
		for (int j = 0; j < element[i].count; j++)
			arr[index++] = element[i].val;
	}
}

int main()
{
	int arr[] = { 2, 5, 2, 8, 5, 6, 8, 8};
	int n = sizeof(arr) / sizeof(arr[0]);

	sortByFrequency(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}

// This code is contributed by Vaibhav Saroj

