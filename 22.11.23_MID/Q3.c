#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

typedef struct Node Node;
void display(Node* head);

int isCircular(struct Node* head)
{
	if (head == NULL)
		return 1;
	struct Node* temp;
	temp = head->next;

	while (temp != NULL && temp != head)
		temp = temp->next;

	return (temp == head);
}
struct Node* newnode(int data)
{
	struct Node* temp1;
	temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;
	return temp1;
}

int main()
{
	struct Node* head = newnode(2);
	head->next = newnode(5);
	head->next->next = newnode(7);
	head->next->next->next = newnode(8);
	head->next->next->next->next = newnode(10);

	if (isCircular(head))
		printf("Yes\n");
	else
		printf("No\n");

	// If not circular making it circular
	head->next->next->next->next = head;
	if (isCircular(head)){
		printf("Yes it is now a Circular Linked List\n");
		//display(head);
	}
	else
		printf("No it is not Circular\n");
	return 0;
}

/*
void display(Node* head){
    Node* temp2;
    printf("Created List: ");
    temp2=head;
    while(temp2!=head){
        printf("%d ", temp2->data);
        temp2=temp2->next;
    }
    return;

}

*/
