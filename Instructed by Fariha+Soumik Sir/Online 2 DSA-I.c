#include<iostream>
using namespace std;

void sort_array(int A[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    int M[n];
    int D[n];
    for (int i=0; i<n; i++)
    {
        cin >> M[i];
    }
    for (int i=0; i<n; i++)
    {
        cin >> D[i];
    }
    int my_money = x1+x2;
    cout << "I got "<<x1<<"+"<<x2
         << "=" << my_money << " taka" << endl;

    sort_array(M, n);
    sort_array(D, n);

    int j=n-1;
    for(int i=0; i<n; i++)
    {
        cout << "cousin "<< i << " got " << M[i]
             <<"+"<<D[j]<<"= " << M[i]+D[j] << " taka" << endl;
        int money = M[i] + D[j];
        if (money>my_money)
        {
            cout << "no" << endl;
            return 0;
        }
        j--;
    }
    cout << "yes" << endl;
    return 0;
}
/**
5 6 6
2 3 4 1 5
2 1 9 8 5
*/
