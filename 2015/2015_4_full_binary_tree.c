// 2018#3
// Description:
// 判断一个二叉树是否是满二叉树

// Explain:
// 当二叉树为满二叉树，最下层节点应位于同一层，只需要得到每个分支的深度，即可判断是否为满二叉树
// 本解中，未使用二叉树的层序遍历，使用先序遍历递归遍历二叉树，
// 先序遍历函数附加一个整型变量参数，用于记录本层是第几层，
// 每递归一次，层数加一。直到节点为空，即为当前分支深度（分支包括空节点）
// 设置全局标记变量初值 1，当得到分支深度与之前得到的分支深度对比，若不一致，标识变量置为 0，非满二叉树
// 遍历所有分支，深度都一致，为满二叉树
// 
// 如二叉树：
// 零层             8
//                /  \
//               /    \
// 一层          7      9 
// 分支深度     /  \   (2)(2)
//            /    \ 
// 二层       5      7
// 分支深度 (3)(3) (3)(3)
// 
// 存在深度为 3 和 2 的节点，深度不同

// Code:

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

// 输入数字，按照顺序构建为二叉搜索树
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

        d = d + 1;
        preorderTraversal(root->lchild, d);
        preorderTraversal(root->rchild, d);
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
    preorderTraversal(root,0);

    // 判断标识变量
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

// Input/Output

// 1 -1
// is full binary tree

// 3 9 -1
// is NOT full binary tree

// 8 9 7 5 7 -1
// is NOT full binary tree

// 8 9 7 5 7 8 9 -1
// is full binary tree