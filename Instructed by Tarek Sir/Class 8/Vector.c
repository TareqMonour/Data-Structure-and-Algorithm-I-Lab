#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printSizeCapacity(vector< int > myVector)
{
    cout << "The size of the vector: " << myVector.size() << endl;
    cout << "The capacity of the vector: " << myVector.capacity() << endl;
}
void printVector(vector< int > v)
{
    printf("The elements of the vector: ");
    for(int i=0; i<v.size(); i++)
    {
        /// printf("%d ", arr[i]);
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

void sortVectorAsc(vector< int > &v)
{
    sort(v.begin(), v.end(), less<int>());
}

void sortVectorDesc(vector< int > &v)
{
    sort(v.begin(), v.end(), greater<int>());
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n; cin >> n;

    vector< int > myVector(n, 0);
    for(int i=0; i<n; i++)
    {
        cin >> myVector[i];
        /// scanf("%d", &myVector[i]);
    }

    cout << "Before applying sorting algorithm....";
    printVector(myVector);

    sortVectorAsc(myVector);

    cout << "After applying sorting algorithm....";
    printVector(myVector);

    cout << myVector.back() << endl;
    myVector.pop_back();
    printVector(myVector);

    cout << myVector.front() << endl;


}
