# include<stdlib.h>
# include<stdio.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *lchild;
    struct binaryTree *rchild;
}BiTree;


BiTree* insert(BiTree *subroot, int d)
{    
    if(subroot == NULL)
    {
        BiTree *tn = (BiTree*)malloc(sizeof(BiTree));
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

void pret(BiTree *root)
{
    if(root)
    {
        printf("%d ",root->data);
        pret(root->lchild);
        pret(root->rchild);
    }   
}


void CountLeaf(BiTree * t, int *count)
{
    if(t)
    {
        if(t->lchild == NULL && t->rchild == NULL)
        {
            (*count)++;
        }
        CountLeaf(t->lchild, count);
        CountLeaf(t->rchild, count);
    }   
}


int main()
{
    BiTree *root = NULL;
    int d = 0;
    int arr[100] = {8,9,7,5,7,-1};
    for(int i = 0; arr[i] != -1; i++)
    {
        root = insert(root, arr[i]);
    }
    int count = 0;
    CountLeaf(root, &count);
    printf("count of leafnode is:%d\n", count);
    return 0;
}