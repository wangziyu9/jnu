# include<stdlib.h>
# include<stdio.h>

typedef struct binaryTree
{
    struct binaryTree *father;
    int data;
    int past;
    struct binaryTree *lchild;
    struct binaryTree *rchild;
}BiTNode, *BiTree;

// 这里设置一个变量，找到折返点。
// 因为涉及 return 出递归函数比较麻烦，所以先设一个全局变量
BiTNode * reentry = NULL;

// 插入元素，构建排序二叉树
BiTNode* insert(BiTNode *subroot, int d)
{    
    if(subroot == NULL)
    {
        BiTNode *tn = (BiTNode*)malloc(sizeof(BiTNode));
        tn->data = d;
        tn->past = 0; //
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

// 搜索排序二叉树
BiTNode* search(BiTNode *root, int target)
{
    if(root)
    {
        if(root->data == target);
        else if(root->data > target)
        {
            root = search(root->lchild, target);
        }
        else
        {
            root = search(root->rchild, target);
        }
    }
    return(root);
}

// 遍历二叉树，关联父节点
void mark_father(BiTNode *root)
{
    if(root->lchild)
    {
        root->lchild->father = root;
        mark_father(root->lchild);
    } 
    if(root->rchild)
    {
        root->rchild->father = root;
        mark_father(root->rchild);
    } 
}

// 从叶子节点回溯，标记节点
void track_father(BiTNode *node)
{
    if(node)
    {
        // printf("%d_",node->data);
        node->past = 1;
        if(node->father)
        {
            track_father(node->father);
        }
    }
}

// 找到折返点
void find_reentry_node(BiTNode *root)
{
    if(root)
    {
        if(root->lchild && root->rchild)
        {
            if(root->lchild->past == 1 && root->rchild->past == 1)
            {
                // printf("%d", root->data);
                reentry = root;
            }
        }
        find_reentry_node(root->lchild);
        find_reentry_node(root->rchild);
    }
    
}
void mret(BiTNode *root)
{
    if(root)
    {
        mret(root->lchild);
        mret(root->rchild);
        if(root->past == 1)
            printf("%d ",root->data);
    }   
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

void bundle(BiTNode * root, int A, int B)
{
    mark_father(root);
    // pret(root);
    
    BiTNode *A_node = NULL;
    BiTNode *B_node = NULL;
    A_node = search(root, A);
    B_node = search(root, B);
    track_father(A_node);
    track_father(B_node);

    find_reentry_node(root);
    mret(reentry);
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

    bundle(root, 3, 8);
    return 0;
}

// 8 9 7 5 7 3 6 -1
// 5 4 6 2 7 1 3 8 -1