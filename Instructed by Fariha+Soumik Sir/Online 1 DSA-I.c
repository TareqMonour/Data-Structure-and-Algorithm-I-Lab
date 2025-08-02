#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int X;
    cin >> X;

    for(int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if (A[i]+A[j]==X)
                cout << A[i] << "+" << A[j] << "=" << X << endl;
        }
    }
}
/**
5
1 2 3 5 0
3
*/
