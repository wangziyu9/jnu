# include<stdlib.h>
# include<stdio.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *lchild;
    struct binaryTree *rchild;
}BiTNode;

int depth = 0;
int isFullBT = 1;

BiTNode* insert(BiTNode *subroot, int d)
{    
    if(subroot == NULL)
    {
        BiTNode *tn = (BiTNode*)malloc(sizeof(BiTNode));
        tn->data = d;
        tn->lchild = NULL;
        tn->rchild = NULL;
        subroot = tn;
    }
    else if(d < subroot->data)
    {
        // printf("%d ",subroot->data);
        subroot->lchild = insert(subroot->lchild, d);
    }
    else
    {
        subroot->rchild = insert(subroot->rchild, d);
    }
    return subroot;
}

void pret(BiTNode *root, int d)
{
    if(root)
    {
        // printf("depth %d ", d);
        // printf("%d\n",root->data);
        d = d + 1;
        pret(root->lchild, d);
        pret(root->rchild, d);
    }
    else
    {
        if(depth == 0)
        {
            depth = d;
        }
        else
        {
            if(depth != d)
            {
                isFullBT = 0;
            }
        }
        
    }
}

int main()
{
    BiTNode *root = NULL;
    int d = 0;
    while (1)
    {
        scanf("%d", &d);
        if(d == -1)
        {
            break;
        }
        root = insert(root, d);
    }
    pret(root,0);

    if(isFullBT)
    {
        printf("is full binary tree");
    }
    else
    {
        printf("is NOT full binary tree");
    }
    
    return 0;
}

// 1 -1
// is full binary tree

// 8 9 7 5 7 -1
// is NOT full binary tree

// 8 9 7 5 7 8 9 -1
// is full binary tree