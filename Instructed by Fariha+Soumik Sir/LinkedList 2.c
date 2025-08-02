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
    //cout << head->data;

    Node d2;
    d2.data = 20;
    d1.next = &d2;

    /// create node d3 which stores 23
    /// put the node at the beginning of the list
    Node d3;
    d3.data = 23;
    head = &d3;
    d3.next = &d1;

    /// print the data serially
    Node* temp = head;
    cout << temp->data << endl; /// 23
    temp = temp->next;
    cout << temp->data << endl; /// 10
    temp = temp->next;
    cout << temp->data << endl; /// 20
    temp = temp->next;
    cout << temp->data << endl; /// garbage

}
