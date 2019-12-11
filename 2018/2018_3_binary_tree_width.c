// 2018#3
// Description:
// 输出一个二叉树的最大宽度

// Explain:
// 未使用二叉树的层序遍历
// 本解中，建立一个一维数组，用于存储每一层的节点数量
// 使用先序遍历递归遍历二叉树，
// 先序遍历函数附加一个整型变量参数，用于记录本层是第几层，
// 每递归一次，层数加一。当节点非空，数组对层数记录数字加一
// 如二叉树：
// 
// 零层     8
//        / \
// 一层   7   9 
//      / \
// 二层 5   7
// 数组为 {1,2,2,0,……}，最大宽度为 2

// Code:

# include<stdlib.h>
# include<stdio.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *lchild;
    struct binaryTree *rchild;
}BiTNode;

int width[100]= {0,};
int depth = 0;

// 输入数字，按照顺序构建为二叉排序树
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

// 递归实现先序遍历
void preorderTraversal(BiTNode *root, int d)
{
    if(root)
    {
        // printf("node at the %d th level, ", d);
        // printf("value is：%d\n",root->data);

        // 对应层数的记录加一
        width[d] += 1;
        d = d + 1;
        preorderTraversal(root->lchild, d);
        preorderTraversal(root->rchild, d);
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
    preorderTraversal(root,0);

    // 遍历数组得到最大宽度
    int max = 0;
    for(int i = 0; i < 100; i++)
    {
        if(width[i] > max)
            max = width[i];
    }
    printf("the max width of binary tree is:%d", max);
    
    return 0;
}

// Input/Output

// 1 -1
// 1

// 8 9 7 5 7 -1
// 2

// 8 9 7 5 7 8 9 -1
// 4