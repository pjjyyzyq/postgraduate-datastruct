#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 将链表L拆分成两条奇偶链表，返回两条奇偶链表头结点指针L1，L2
void split(LinkList &L, LinkList *L1, LinkList *L2){
    // 遍历链表L的工作指针p，初始指向链表L的第1个结点
    LNode *p=L->next;
    // 初始化
    L1=L;
    L2=(LinkList)malloc(sizeof(LNode));
    LNode *p1=L1;
    LNode *p2=L2;
    while(p){
        // 奇链表
        p1->next=p;
        p1=p;
        p=p->next;
        // 偶链表
        p2->next=p;
        p2=p;
        if(p){
            p=p->next;
        }
    }
    // 容易忘，尾结点指向空
    p1->next=NULL;
    p2->next=NULL;
}