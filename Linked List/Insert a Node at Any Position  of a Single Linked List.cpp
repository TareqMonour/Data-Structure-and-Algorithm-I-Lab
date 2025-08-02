#include <iostream>

using namespace std;

struct  Node
{
    int num;
    Node *next;
 }; //node constructed

  int size = 0;
  void insert(Node** head, int num){
    Node* new_Node = new Node();
    new_Node->num = num;
    new_Node->next = *head;
    *head = new_Node;
     size++;
}


// method to insert at a given position
void insert_Position(int pos, int data, Node** head)
{
    Node* new_node = new Node();
    new_node->num = data;
    new_node->next = NULL;

    // Invalid positions
    if(pos < 1 || pos > size + 1)
        printf("Invalid\n");

    // inserting first node
    else if(pos == 1){
        new_node->next = *head;
        *head = new_node;
        size++;
    }

    else
    {
        Node* temp = *head;

        // traverse till the current (pos-1)th node
        while(--pos > 1){
            temp = temp->next;
        }
        new_node->next= temp->next;
        temp->next = new_node;
        size++;
    }
}

  //Display all nodes
  void display_all_nodes(Node* node)
    {
      while(node!=NULL){
        cout << node->num << " ";
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;
    insert(&head,1);
    insert(&head,3);
    insert(&head,5);
    insert(&head,7);
    cout << "Original list:\n";
    display_all_nodes(head);
    int pos = 1, value = 12;
    cout << "\n\nPosition: " << pos << ", Value: " << value;
    insert_Position(pos, value, &head);
    cout << "\nUpdated list:\n";
    display_all_nodes(head);
    pos = 4, value = 14;
	cout << "\n\nPosition: " << pos << ", Value: " << value;
    insert_Position(pos, value, &head);
    cout << "\nUpdated list:\n";
    display_all_nodes(head);
    pos = 7, value = 18;
	cout << "\n\nPosition: " << pos << ", Value: " << value;
    insert_Position(pos, value, &head);
    cout << "\nUpdated list:\n";
    display_all_nodes(head);
    cout<<endl;
    return 0;
}
