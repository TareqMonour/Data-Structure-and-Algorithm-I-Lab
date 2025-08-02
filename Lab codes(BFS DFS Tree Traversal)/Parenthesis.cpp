#include<bits/stdc++.h>
using namespace std;

int arr[100], top=-1;

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
        return-1;
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
    cout<<"--> Stack <--"<<endl;
    
    //char s[3] = {'c','a','t'};
    
    //string ss = "level";
    
    string ss;
    cin>>ss;
    
    for(int i=0;i<ss.size();i++)
    {
        //cout<<ss[i]<<endl;
        if(ss[i]=='('||ss[i]=='['||ss[i]=='{')
        {
            push(ss[i]);
        }
        else
        {
            if(ss[i]==')'&&pop()!='(')
            {
                cout<<"Invalid"<<endl;
                return 0;
            }
            else if(ss[i]=='}'&&pop()!='{')
            {
                cout<<"Invalid"<<endl;
                return 0;
            }
            else if(ss[i]==']'&&pop()!='[')
            {
                cout<<"Invalid"<<endl;
                return 0;
            }
        }
        
    }
    
    cout<<"Valid"<<endl;
    
    // bool p_check = true ; 
    // int k = 0;
    
    // while(!isEmpty())
    // {
    //   //cout<<(char)pop()<<endl; 
    //   if(pop()!=ss[k])
    //   {
    //       p_check=false;
    //   }
    //   k++;
    // }
    
    // if(p_check==true)
    // {
    //   cout<<"Palindrome "<<endl; 
    // }
    // else
    // {
    //     cout<<"Not is Palindrome "<<endl;
    // }
    
    
    // push(20);
    // push(1);
    // push(5);
    // pop();
    // pop();
    // pop();
    
    // if(isEmpty())
    // {
    //     cout<<"Stack is Empty "<<endl;
    // }
    // else
    // {
    //     cout<<"Stack is Not Empty "<<endl;
    // }
    
    
    //cout<<pop()<<endl;
    
    // for(int i=0; i<=top;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    
    return 0;
}