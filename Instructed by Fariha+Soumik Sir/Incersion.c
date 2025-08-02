#include<iostream>
using namespace std;


int main(){
    int A[] = {6, 5, 4, 7, 3};
    int n = sizeof(A)/sizeof(A[0]);

    cout << "unsorted array\n";
    for (int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl << endl;


    for (int i=1;i<n;i++){
        int key = A[i];
        int j=i-1;
        cout << "key = A[" <<i<< "] = " << key << endl;
        while( A[j]>key && j>=0){
            A[j+1] = A[j];
            cout << "moving " << A[j+1] << endl;
            j = j-1;
        }
        A[j+1] = key;
        cout << "key in A[" << j+1 <<"]" << endl;


        cout << "after itr " << i <<endl;
        for (int i=0;i<n;i++){
            cout << A[i] << " ";
        }
        cout << endl << endl;
    }

    cout << "sorted array\n";
    for (int i=0;i<n;i++){
        cout << A[i] << " ";
    }
    cout << endl;

}
