# include<stdio.h>
# include<stdlib.h>

typedef struct linkedList
{
    int data;
    struct linkedList * next;
}Node;

int main()
{
    Node *head = NULL;
    Node *last = NULL;
    int d = 0;
    do{
        scanf("%d", &d);
        if(d != -1)
        {
            Node *p = (Node*)malloc(sizeof(Node));
            p->data = d;
            p->next = NULL;
           
            if (head == NULL) {
                head = p;
                last = head;
            }
            else
            {
                 last->next = p;
                 last = p;
            }
        }
        else
        {
            break;
        } 
    }while(d != -1);

    Node *h = head;
    while (h)
    {
        printf("%d ", h->data);
        h = h->next;
    }
        
    return 0;
}
