#include<iostream>
#include<cstdio>
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
    void insert_last(int data);
    Node* search(int data);
    bool _delete(int data);
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

void SinglyLinkedList::insert_last(int data){
    Node* node = new Node(data);
    if (head == NULL){
        head = node;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = node;
}

Node* SinglyLinkedList::search(int data){
    Node* temp = head;
    while(temp!=NULL){
        if (temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

bool  SinglyLinkedList::_delete(int data){
    if (head == NULL){
        return false;
    } else if (head->data == data){
        head = head->next;
        return true;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        if (temp->next->data == data){  /// temp == B , temp->next == C
            temp->next = temp->next->next;
            return true;
        }
        temp = temp->next;
    }
    return false;
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
    bool deleted = sll._delete(0);
    cout << "0 deleted " << deleted << endl;
    sll.print();

    sll.insert_last(0);
    sll.print();

    deleted = sll._delete(0);
    cout << "0 deleted " << deleted << endl;
    sll.print();

    sll.insert(15);
    sll.print();
    sll.insert(100);
    sll.print();
    sll.insert_last(500);
    sll.insert_last(600);
    sll.insert_last(700);
    sll.print();

    Node* found_node = sll.search(15);
    if (found_node!=NULL) cout << "found " << found_node->data << endl;
    else printf("15 not found\n");

    found_node = sll.search(800);
    if (found_node!=NULL) cout << "found " << found_node->data << endl;
    else printf("800 not found\n") ;

//    Node n(10); /// obj
//    Node* node = new Node(10); /// pointer to obj
//    cout << node->data << endl;
//    cout << node->next << endl;
}
