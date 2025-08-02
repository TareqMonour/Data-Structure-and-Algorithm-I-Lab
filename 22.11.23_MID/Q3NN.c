#include<stdio.h>
struct list
{
    int data;
    struct list *next;

};
int main()
{
    struct list *a,*b,*c,*d,*e;
    a=(struct list*)malloc(sizeof(struct list));
    b=(struct list*)malloc(sizeof(struct list));
    c=(struct list*)malloc(sizeof(struct list));
    d=(struct list*)malloc(sizeof(struct list));
    e=(struct list*)malloc(sizeof(struct list));

    a->data=2;
    a->next=NULL;
    b->data=5;
    b->next=NULL;
    c->data=7;
    c->next=NULL;
    d->data=8;
    d->next=NULL;
    e->data=10;
    e->next=NULL;

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=a;
    int count=1;
    struct list *temp=a;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
        if(a==temp)
        {
            count=0;
            printf("\nIt is a Circular Linked List");
            break;
        }

    }
    printf("\n");
    if(count==1)
    {
        printf("\nIt's a singly linked list");
    }


}
