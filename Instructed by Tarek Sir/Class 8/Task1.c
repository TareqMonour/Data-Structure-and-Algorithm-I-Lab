#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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


int main()
{
    vector< int > myVector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reverse(myVector.begin(), myVector.begin()+5);
    /// printVector(myVector);
    reverse(myVector.end()-5, myVector.end());
    printVector(myVector);
    return 0;
}
