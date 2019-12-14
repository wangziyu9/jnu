// 2017#3
// Description:
// 判断一个二叉树是否是满二叉树

// Explain:
// 先序递归遍历二叉树，每递归一次判断节点左右子树都存在或都不存在，如果都成立则为严格二叉树
// 
// 如二叉树：
// 零层             8
//                /  \
//               /    \
// 一层          7      9 
// 存在分支    (1)(0)  (1)(1)
//            / 
// 二层       5 
// 存在分支 (1)(1)


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
int isStrictBT = 1;

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

// 递归实现先序遍历，并且判断
void preorderTraversal(BiTNode *root)
{
    if(root)
    {
        // printf("node at the %d th level, ", d);
        // printf("value is：%d\n",root->data);

        if((root->lchild && root->rchild) || (!root->lchild && !root->rchild))
        {
            
        }
        else
        {
            isStrictBT = 0;
        }
        printf("%d ",root->data);
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }   
}

// 二叉树后序遍历
void postorderTraversal(BiTNode *root)
{
    if(root)
    {
        postorderTraversal(root->lchild);
        postorderTraversal(root->rchild);
        printf("%d ",root->data);
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
    printf("\nPreorder Traversal:\n");
    preorderTraversal(root);
    printf("\nPostorder Traversal:\n");
    postorderTraversal(root);



    // 判断标识变量
    if(isStrictBT)
    {
        printf("\nis strict binary tree\n");
    }
    else
    {
        printf("\nis NOT strict binary tree\n");
    }
    
    return 0;
}

// Input/Output

// 8 9 7 5 -1

// Preorder Traversal:
// 8 7 5 9 
// Postorder Traversal:
// 5 7 9 8 
// is NOT strict binary tree