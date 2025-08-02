#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class SinglyLinkedList{
public:
    Node* head;
    SinglyLinkedList();
    void insert(int data); /// insert first
//    void insert_last(int data);
//    Node* search(int data);
//    void _delete(int data);
    void print();
};

SinglyLinkedList::SinglyLinkedList(){ /// constructor
    this->head = NULL;
}

void SinglyLinkedList::insert(int data){ /// insert first
    Node* node = new Node(data);
    if (head == NULL){
        head = node;
        return;
    }
    node->next = head;
    head = node;
}

void SinglyLinkedList::print(){
    cout << "SinglyLinkedList" << endl;
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl << endl;
}

int main(){
    SinglyLinkedList sll;
    sll.print();

    sll.insert(15);
    sll.print();
    sll.insert(100);
    sll.print();
    sll.insert(27);
    sll.
    sll.insert(100);
    sll.print();print();

//    Node n(10); /// obj
//    Node* node = new Node(10); /// pointer to obj
//    cout << node->data << endl;
//    cout << node->next << endl;
}
