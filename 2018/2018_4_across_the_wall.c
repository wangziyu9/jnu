// 2018#3
// Description:
// 城墙问题，每次只能穿一道墙，设计一个算法计算一个人从一个点到另一个点穿过的墙的数量

// Explain:
// 将城墙抽象成二叉树，
// 将问题转化为二叉树两节点间的路径问题
// 
//       5
//      / \
//     4   6
//    /     \
//   2       7
//  / \       \
// 1   3(A)    8(B)
// 
// 构建一个能够追溯到父节点的二叉树
// 从起点和终点向上追溯，经过的节点做标记，
// 假设起点在左侧，终点在右侧，
// 找到最深层的公共父节点，后序遍历左子树，前序遍历右子树
// 即可输出路径

// Code:

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
int route_length = 0;

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
        node->past = 1;
        if(node->father)
        {
            track_father(node->father);
        }
    }
}

// 找到折返点
// 当某节点左右子树都被经过，该节点为折返点
// 本实现非常丑陋，但是 it works
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

// 前中后序三种遍历，只会输出路径经过的节点
void preorderTraversal(BiTNode *root)
{
    if(root)
    {
        if(root->past == 1)
        {
            route_length++;
            printf("%d ",root->data);
        }
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }   
}
void inorderTraversal(BiTNode *root)
{
    if(root)
    {
        inorderTraversal(root->lchild);
        if(root->past == 1)
        {
            route_length++;
            printf("%d ",root->data);
        }
            
        inorderTraversal(root->rchild);
    }   
}
void postorderTraversal(BiTNode *root)
{
    if(root)
    {
        postorderTraversal(root->lchild);
        postorderTraversal(root->rchild);
        if(root->past == 1)
        {
            route_length++;
            printf("%d ",root->data);
        }
    }   
}

void bundle(BiTNode * root, int A, int B)
{
    mark_father(root);
    
    BiTNode *A_node = NULL;
    BiTNode *B_node = NULL;
    A_node = search(root, A);
    B_node = search(root, B);
    track_father(A_node);
    track_father(B_node);
    find_reentry_node(root);

    postorderTraversal(reentry->lchild);
    inorderTraversal(reentry->rchild);

    printf("\nroute length:%d\n",route_length);
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

// Input/Output:

// 5 4 6 2 7 1 3 8 -1
// 3 2 4 6 7 8 
// route length:6

// 10 5 4 6 2 7 1 3 8 -1
// 3 2 4 6 7 8 
// route length:6
