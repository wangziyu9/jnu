// 20xx#x
// Description:

// print hello world
// hello world

// Code:

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

#include <stdlib.h>
#include <stdio.h>
int main()
{
    // long *a = 0;
    // a = (long *)malloc(100 * sizeof(long));
    // for(int i = 0; i < 100; i++)
    // {
    //     a[i] = i;
    // }

    // for(long i = 0; i<100; i+=1)
    // {
    //     printf("%d ", *a++);
    // }
    // free(a);

    Node *head = NULL;
    int number;
    for (int i = 0; i < 100; i++)
    {
        number = i;

        Node *p = (Node *)malloc(sizeof(Node));
        p->value = number;
        p->next = NULL;

        Node *last = head;
        if (last)
        {
            while (last->next)
            {
                last = last->next;
            }
            last->next = p;
        }
        else
        {
            head = p;
        }
    }

    Node *p = head;
    Node *tmp = p;
    Node *last;
    int i = 0;

    while (p)
    {
        i++;
        if (i == 0)
        {
            tmp = p;
            printf("%d", tmp->value);
        }
        printf("%d ", p->value);
        last = p;
        p = p->next;
        
    }
    
    printf("hello world\n");
    last -> next = head;
    head = tmp->next;
    tmp -> next = NULL;

    Node *q = head;
    while (q)
    {
        printf("%d ", q->value);
        q = q->next;
    }

    
    getchar();
    return 0;
}

// Input:

// No input

// Output:

// hello world