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
    int d = 0;
    do{
        scanf("%d", &d);
        if(d != -1)
        {
            Node *p = (Node*)malloc(sizeof(Node));
            p->data = d;
            p->next = NULL;
            Node *last = head;
            if(last){
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
