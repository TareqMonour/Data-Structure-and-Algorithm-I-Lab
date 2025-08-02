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

bool isEmpty()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout<<"---> Stack <---"<<endl;
    
    //char s[3] = {'c','a','t'};
    //string ss = "cat";
    string ss;
    
    cin>>ss;
    
    for(int i=0; i<ss.size();i++)
    {
        //cout<<ss[i]<<endl;
        push(ss[i]);
    }
    
    bool p_check = true;
    int k=0;
    while(!isEmpty())
    {
       //cout<<(char)pop()<<endl;
       if(pop()!=ss[k])
       {
           p_check = false;
       }
       k++;
    }
    
    if(p_check==true)
    {
       cout<<"Palindrome"<<endl; 
    }
    else
    {
       cout<<"Not a Palindrome"<<endl; 
    }
    // push(20);
    // push(1);
    // push(5);
    // pop();
    // pop();
    // pop();
    
    // if(isEmpty())
    // {
    //     cout<<"Stack is isEmpty"<<endl;
    // }
    // else
    // {
    //     cout<<"Stack is not isEmpty"<<endl;
    // }
    
    
    //cout<<pop()<<endl;
    
    // for(int i=0;i<=top;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    
    return 0;
}