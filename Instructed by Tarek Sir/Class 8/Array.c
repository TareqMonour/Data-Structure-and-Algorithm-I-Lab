#include<iostream>
using namespace std;
void printArray(int arr[], int n)
{
    printf("The elements of the array: ");
    for(int i=0; i<n; i++)
    {
        /// printf("%d ", arr[i]);
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}
int main()
{
    /// freopen("input.txt", "r", stdin);
    /// freopen("output.txt", "w", stdout);

    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        /// scanf("%d", &arr[i]);
        cin >> arr[i];
    }
    printArray(arr, n);
    return 0;
}
