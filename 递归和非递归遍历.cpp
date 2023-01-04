#include<iostream>
using namespace std;

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// 递归实现二叉树的先序遍历，教材标准写法
void PreOrder_1(BiTree T){
    if(T!=NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// 递归实现二叉树的先序遍历，第二种写法，更常用
void PreOrder_2(BiTree T){
    if(T==NULL) return;
    visit(T);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

// 递归实现二叉树的先序遍历，第三种写法，少一层递归深度
void PreOrder_3(BiTree T){
    if(T==NULL) return;
    visit(T);
    if(T->lchild!=NULL)
        PreOrder(T->lchild);
    if(T->rchild!=NULL)
        PreOrder(T->rchild);
}

// 递归实现二叉树的中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}

// 递归实现二叉树的后续遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 非递归实现二叉树的先序遍历，背
void PreOrderNR(BiTree T){
    // 初始化一个辅助栈
    InitStack(S);
    // 工作指针p，初始指向根节点
    BiTree p=T;
    while(p||!IsEmpty(S)){
        if(p){
            visit(p)
            Push(S,p);
            p=p->lchild
        }
        else{
            Pop(S,p);
            p=p->rchild;
        }
    }
}

// 非递归实现二叉树的中序遍历，背
void InOrderNR(BiTree T){
    // 初始化一个辅助栈
    InitStack(S);
    // 工作指针p，初始指向根节点
    BiTree p=T;
    while(p||!IsEmpty(S)){
        if(p){
            Push(S,p);
            p=p->lchild
        }
        else{
            Pop(S,p);
            visit(p);//与先序遍历的区别就是visit的位置，中序是在出栈后，先序是在入栈前
            p=p->rchild;
        }
    }
}

// 后序遍历二叉树的非递归算法
void PostOrderNR(BiTree T){
    // 初始化一个辅助栈
    InitStack(S);
    // p为工作指针
    BiTree p;
    BiTree r=NULL;
    while(p||!IsEmpty(S)){
        if(p){
            Push(p);
            p->lchild;
        }
        else{
            // 读栈顶元素
            GetTop(S,p);
            // 若右孩子存在，且未被访问过
            if(p->rchild&&p->rchild!=r)
                p=p->rchild;
            // 若无左孩子也无右孩子
            else{
                Pop(S,p);
                visit(p);
                r=p;
                p=NULL;
            }
        }
    }
}
