#include<iostream>
using namespace std;

/*要求二叉树按二叉链表形式存储，
写出一个建立二叉树的算法*/

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef int ElemType;

// 按先序遍历序列建立二叉树，二叉树先序遍历的引申
bool CreatBiTree(BiTree &T){
    ElemType x;
    cin>>x;
    // 输入x值为0表示当前指针指向空结点
    if(x==0)
        T==NULL;
    else{
        // 在内存当中分配一块结点空间
        T=(BiTree)malloc(sizeof(BiTNode));
        // 内存不足，分配失败
        if(T==NULL)
            return false;
        // 将输入的x存储在当前指针所指结点的数据域
        T->data=x;
        // 递归建立当前指针所指结点的左子树
        CreatBiTree(T->lchild);
        // 递归建立当前指针所指结点的右子树
        CreatBiTree(T->rchild);
    }
    return true
}