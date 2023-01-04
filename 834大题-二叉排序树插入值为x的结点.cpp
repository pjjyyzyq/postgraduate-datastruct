#include<iostream>
using namespace std;

/*题目：在二叉排序树T中插入一个数据元素x*/

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 834非递归实现
void BST_Insert(BiTree &T,ElemType x){
     // 保存新结点
    BiTNode *p=(BiTNode *)malloc(sizeof(BiTNode));
    p->data=x;
    p->lchild=p->rchild=NULL;
    // !T相当于T==NULL，即原二叉排序树中无结点时
    if(!T){
        T=p;
    }
    // 原二叉排序树非空时
    else{
        // q指向待插入结点的父结点，初始指向根节点
        BiTNode *q=T;
        // 遍历寻找待插入结点的父节点
        while(q->lchild!=NULL||q->rchild!=NULL){
            if(x==q->data){
                return;
            }
            else if(x<q->data){
                if(q->lchild!=NULL)
                    q=q->lchild;
                // q->lchild==NULL时
                else
                    break;
            }
            // x>q->data时
            else{
                if(q->rchild!=NULL)
                    q=q->rchild;
                // q->rchild==NULL时
                else
                    break;
            }
        }
        if(x<q->data)
            q->lchild=p;
        else
            q->rchild=p;
    }
}

// 递归实现
void BST_Insert_Recursion(BiTree &T,ElemType x){
    // 找到最终插入位置，也是递归出口
    if(T==NULL){
        T=(BiTNode *)malloc(sizeof(BiTNode));
        T->data=x;
        T->lchild=T->rchild=NULL;
        // 结束函数
        return ;
    }
    // 二叉排序树中存在相同关键字的结点，插入失败
    else if(x==T->data) 
        return ;
    else if(x<T->data)
        return BST_Insert(T->lchild,x);
    else
        return BST_Insert(T->rchild,x);
}

