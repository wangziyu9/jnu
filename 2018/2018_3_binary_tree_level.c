# include<stdlib.h>
# include<stdio.h>

int p[100][100] = {0};

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

void lvlt(BiTNode *root)
{
    int row, i, j;
    p[0][0] = root;

    for(row = 0; row < 100; row++)
    {
        for(i = 0; i < 100; i++)
        {
            if(p[row][i])
            {
                if(p[row][i]->lchild)
                {
                    p[row+1][j] = p[row][i]->lchild;
                    j++
                }
                if(p[row][i]->rchild)
                {
                    p[row+1][j] = p[row][i]->rchild;
                    j++
                }
            }
            else
            {
                continue;
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
    pret(root);
    return 0;
}