#include<iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;

// 王道 带头结点单链表的逆置
LinkList Reverse_1(LinkList L){
    // 工作结点指针p，其后继结点指针r用于防止断链
    LinkNode *p,*r;
    // 工作指针p初始指向链表第一个元素结点
    p=L->next;
    // 头结点与链表断开
    L->next=NULL;
    // 逐个遍历链表除头结点外剩下的元素结点
    while(p!=NULL){
        // r指向p结点的后继即下一个元素结点
        r=p->next;
        // 开始头插，前面不设置r的画在这里会断链
        p->next=L->next;
        L->next=p;
        // 工作指针指向下一个元素结点
        p=r;
    }
    return L;
}

// 王道 带头结点单链表的逆置 第二种方法
void Reverse_2(LinkList L){
    // 
    LinkList *pre,*p,*r;
    // 工作指针p初始指向链表头结点后的第一个元素结点
    p=L->next;
    // r指向工作结点的后继结点
    r=p->next;
    // 第一个元素结点与后继元素结点断链，脱离链表
    while(r!=NULL){
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;
    }
    L->next=p;
    return L;
}

// 834大题 不带头结点单链表的逆置 类似王道第二种方法
void Reverse_3(LinkList &L){
    LinkNode *p=NULL;
    // q为工作指针，初始指向链表的头结点
    LinkNode *q=L;
    // 逐个遍历链表的结点
    while(q!=NULL){
        // 头指针指向后继结点即下一个结点，这里类似r的作用，防止断链
        L=L->next;
        // 到着头插
        q->next=p;
        p=q;
        // 工作指针q指向下一个元素结点
        q=L;
    }
    // 头指针指向链表第一个结点
    L=p;
}