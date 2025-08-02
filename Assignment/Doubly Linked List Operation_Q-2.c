#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct DoublyLinkedList
{
    struct Node* head;
    struct Node* tail;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct DoublyLinkedList* list, int data)
{
    struct Node* newNode = createNode(data);

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void deleteNode(struct DoublyLinkedList* list, int data)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                list->head = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            else
            {
                list->tail = current->prev;
            }

            free(current);
            return;
        }
        current = current->next;
    }
    printf("Node with Data %d not Found in the List.\n", data);
}

struct Node* search(struct DoublyLinkedList* list, int data)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}
void traverse(struct DoublyLinkedList* list)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int sizeCount(struct DoublyLinkedList* list)
{
    int count = 0;
    struct Node* current = list->head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void freeList(struct DoublyLinkedList* list)
{
    struct Node* current = list->head;
    struct Node* nextNode;

    while (current != NULL)
    {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
}

int main()
{
    struct DoublyLinkedList myList;
    myList.head = NULL;
    myList.tail = NULL;

    insertAtBeginning(&myList, 3);
    insertAtBeginning(&myList, 7);
    insertAtBeginning(&myList, 1);

    printf("Desired Doubly Linked List: ");
    traverse(&myList);

    printf("Size of the Doubly Linked List: %d\n", sizeCount(&myList));

    struct Node* searchResult = search(&myList, 7);
    if (searchResult != NULL)
    {
        printf("Node with data %d Found.\n", searchResult->data);
    }
    else
    {
        printf("Node not Found.\n");
    }

    deleteNode(&myList, 7);
    printf("Doubly Linked List after Deletion: ");
    traverse(&myList);
    printf("Size of the Doubly Linked List after Deletion: %d\n", sizeCount(&myList));
    freeList(&myList);

    return 0;
}
