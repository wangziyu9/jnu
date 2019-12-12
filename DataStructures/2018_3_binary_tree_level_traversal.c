// 2018#3
// Description:
// 输出一个二叉树的最大宽度

// Explain:
// 使用先序遍历递归遍历二叉树，写入二维数组，实现二叉树层序输出
// 先序遍历函数附加一个整型变量参数，用于记录本层是第几层，
// 每递归一次，层数加一。当节点非空，将值写入二维数组对应层
// 由于左子树节点总是在前，故能够保证每层节点有序
// 如二叉树：
// 
// 零层     8
//        / \
// 一层   7   9 
//      / \
// 二层 5   7
// 数组为 
// 8 0 0……
// 7 9 0
// 5 7 0
// ……

// Code:

# include<stdlib.h>
# include<stdio.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *lchild;
    struct binaryTree *rchild;
}BiTNode;

// 建立二维数组，存储层序遍历节点值
int nd[100][100] = {0};

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

void insert2array(int level, int value)
{
    for(int i = 0; i < 100; i++)
    {
        if(nd[level][i] == 0)
        {
            nd[level][i] = value;
            break;
        }
    }
}

// 递归实现先序遍历
void preorderTraversal(BiTNode *root, int d)
{
    if(root)
    {
        // printf("node at the %d th level, ", d);
        // printf("value is：%d\n",root->data);
        insert2array(d, root->data);

        // 对应层数的记录加一
        d = d + 1;
        preorderTraversal(root->lchild, d);
        preorderTraversal(root->rchild, d);
    }
}

int main()
{
    BiTNode *root = NULL;
    int d = 0;

    // 循环输入数字构建二叉树，以 -1 结束
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

    // 双循环输出二维数组
    for(int level = 0; level < 100; level++)
    {
        if(nd[level][0] != 0)
        {
            printf("\nthe %d th level\n", level);
            for(int i = 0; i < 100; i++)
            {
                if(nd[level][i] != 0)
                {
                    printf("%d ",nd[level][i]);
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
        
    return 0;
}

// Input/Output

// 1 -1
// the 0 th level
// 1 

// 8 9 7 5 7 -1
// the 0 th level
// 8 
// the 1 th level
// 7 9 
// the 2 th level
// 5 7

// 8 9 7 5 7 8 9 -1
// the 0 th level
// 8 
// the 1 th level
// 7 9 
// the 2 th level
// 5 7 8 9