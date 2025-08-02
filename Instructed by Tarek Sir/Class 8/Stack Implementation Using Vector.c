#include<iostream>
#include<vector>
using namespace std;
class Stack
{
private:
    vector< int > myVector;
public:
    void push(int z)
    {
        myVector.push_back(z);
    }
    void pop()
    {
        if(myVector.size()==0)
            return;
        else
            myVector.pop_back();
    }
    int top()
    {
        if(myVector.size()==0)
            return -1;
        else
            return myVector.back();
    }
    bool isEmpty()
    {
        /// return myVector.size()==0;
        if(myVector.size()==0)
            return true;
        else
            return false;
    }
};
int main()
{
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    while(myStack.isEmpty()==0)
    {
        cout << myStack.top() << endl;
        myStack.pop();
    }
}
