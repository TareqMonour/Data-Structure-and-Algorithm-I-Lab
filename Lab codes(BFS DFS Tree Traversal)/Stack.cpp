#include<bits/stdc++.h>
using namespace std;
int arr[100] , top=-1;

void push(int x)
{
    if(top>=99)
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
       top++;
       arr[top]=x; 
    }
}

int pop()
{
    if(top<=-1)
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else
    {
        int y = arr[top];
        top--;
        return y; 
    }
}

int main()
{
    cout<<"---> Stack <---"<<endl;
    push(20);
    push(1);
    push(5);
    pop();
    pop();
    pop();
    pop();
    
    //cout<<pop()<<endl;
    
    for(int i=0;i<=top;i++)
    {
        cout<<arr[i]<<endl;
    }
    
    return 0;
}