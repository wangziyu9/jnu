# include<stdio.h>
# include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList LinkedListInit()
{
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    if(L == NULL)
    {
        printf("申请内存失败\n");
    }
    L->next = NULL;
}

LinkedList LinkedListCreatHead()
{
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;

    int x;
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

LinkedList LinkedListCreateTail()
{
    Node *L;
    L = (Node*)malloc(sizeof(Node));
    L->next = NULL;
    Node *r;
    r = L;
    int x;
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}

LinkedList LinkedListInsert(LinkedList L, int i, int x)
{
    Node *pre;
    pre = L;
    int temp = 0;
    for(temp = 1; temp < i; temp++)
    {
        pre = pre->next;
    }
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;
    return L;
}

LinkedList LinkedListDelete(LinkedList L, int x)
{
    Node *p, *pre;
    p = L->next;
    while (p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p);
    return L;
}

int main()  
{  
    LinkedList list,start;  
/*  printf("请输入单链表的数据：");  
    list = LinkedListCreateHead(); 
    for(start = list->next; start != NULL; start = start->next) 
        printf("%d ",start->data); 
    printf("/n"); 
*/  printf("请输入单链表的数据：");   
    list = LinkedListCreateTail();  
    for(start = list->next; start != NULL; start = start->next)  
        printf("%d ",start->data);  
    printf("/n");  
    int i;  
    int x;  
    printf("请输入插入数据的位置：");  
    scanf("%d",&i);  
    printf("请输入插入数据的值：");  
    scanf("%d",&x);  
    LinkedListInsert(list,i,x);  
    for(start = list->next; start != NULL; start = start->next)  
        printf("%d ",start->data);  
    printf("/n");  
    printf("请输入要删除的元素的值：");  
    scanf("%d",&x);  
    LinkedListDelete(list,x);   
    for(start = list->next; start != NULL; start = start->next)  
        printf("%d ",start->data);  
    printf("/n");  
      
    return 0;  
}  