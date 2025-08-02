#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    ///scanf("%d",&n);
    cin >> n;

    /// printf("%d\n",n);
    cout << n << "\n";

    ///int arr[5];
    vector<int> arr(5); /// size 5
    for (int i=0;i<5;i++){
        cout << arr[i];
    }

    for (int i=0;i<5;i++){
        cin >> arr[i];
    }
    arr.push_back(100);
    arr.push_back(200);

    for (int i=0;i<arr.size();i++){
        cout << arr[i];
    }
    cout << "\n" << arr.size() << endl;
}
