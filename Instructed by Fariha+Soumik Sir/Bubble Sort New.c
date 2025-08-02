#include<iostream>
using namespace std;





int main(){
    int A[] = {6, 5, 4, 7, 3, 8, 0, -12, 46, 9};
    int n = sizeof(A)/sizeof(A[0]);


    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){ /// 6-0 = 6
            if (A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    for (int i=0;i<n;i++){
        cout << A[i] << endl;
    }

}
