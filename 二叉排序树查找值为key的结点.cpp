#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 在二叉排序树中查找值为key的结点（非递归实现）
BiTNode *BST_Search(BiTree T,int key){
    // key==T->data时查找成功返回结点指针，T==NULL时查找失败返回NULL
    while(T!=NULL&&key!=T->data){
        if(key<T->data)
            T=T->lchild;
        else
            T=T->rchild;
    }
    return T;
}

// 在二叉排序树中查找值key的结点（递归实现）
BiTNode *BST_Search_Recursion(BiTree T,int key){
    // 递归出口 查找失败
    if(T==NULL)
        return NULL;
    // 递归出口 查找成功
    if(key==T->data)
        return T;
    else if(key<T->data)
        return BST_Search(T->lchild,key);
    else
        return BST_Search(T->rchild,key);
}
