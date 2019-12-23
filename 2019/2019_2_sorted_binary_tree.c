# include<stdlib.h>
# include<stdio.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *lchild;
    struct binaryTree *rchild;
}BiTNode;


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

void pret(BiTNode *root)
{
    if(root)
    {
        printf("%d ",root->data);
        pret(root->lchild);
        pret(root->rchild);
    }   
}

int main()
{
    BiTNode *root = NULL;
    int d = 0;
    int arr[100] = {8,9,7,5,7,-1};
    for(int i = 0; arr[i] != -1; i++)
    {
        root = insert(root, arr[i]);
    }
    pret(root);
    return 0;
}