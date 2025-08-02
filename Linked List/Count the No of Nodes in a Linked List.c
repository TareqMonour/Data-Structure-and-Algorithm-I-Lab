#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}   *first = NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *) malloc (sizeof (struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *) malloc (sizeof (struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int Rcount(struct Node *p)
{
    if (p == 0)
        return 0;
    else
        return count (p->next) + 1;
}

int Rcount2(struct Node *p)
{
    int x = 0;
    if (p)
    {
        x = Rcount2 (p->next);
        return x + 1;
    }
    else
        return x;
}

int main()
{
    int A[] = { 8, 3, 7, 12 };
    create (A, 4);
    printf ("Count %d\n", count (first));
    return 0;
}
