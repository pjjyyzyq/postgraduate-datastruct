#include<iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;

// 删除不带头结点单链表中值为x的结点(递归算法)
void delete_x(LinkList &L,int x){
    // 递归出口，L为空表时退出递归
    if(L==NULL){
        return;
    }
    // 当前递归的L所指向的结点值为x
    if(L->data==x){
        // 工作指针p，初始指向L
        LinkNode *p=L;
        // L指向下一个结点
        L=L->next;
        // 释放p所指向的结点
        free(p);
        // 调用下一个结点的递归，之前L已经指向下一个结点
        delete_x(L,x);
    }
    // 当前递归的L所指向的结点值不为x
    else{
        // 调用下一个结点的递归
        delete_x(L->next,x);
    }
}