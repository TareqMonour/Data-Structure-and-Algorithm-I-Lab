#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int value;
    ListNode* next;
};

ListNode* head = NULL;
ListNode* tail = NULL;

void printList()
{
    ListNode* temp = head;

    while(temp!=NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

ListNode* createListNode(int data)
{
    ListNode* temp = (ListNode *)malloc(sizeof(ListNode));
    temp->value = data;
    temp->next = NULL;
    return temp;
}

void insertLast(int data)
{
    if(head==NULL)
    {
        head = createListNode(data);
        tail = head;
    }
    else
    {
        ListNode* temp = createListNode(data);
        tail->next = temp;
        tail = tail->next;
    }
}

void insertFirst(int data)
{

}

int main()
{
    insertLast(2);
    insertLast(5);
    insertLast(9);
    insertLast(7);
    printList();
}
