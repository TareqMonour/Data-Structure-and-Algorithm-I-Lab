#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};


int main(){
    Node* head=NULL;
    Node d1;
    d1.data = 10;
    head = &d1;
    cout << head->data;

    Node d2;
    d2.data = 20;
    d1.next = &d2;

    /// create node d3 which stores 23
    /// put the node at the beginning of the list

}
