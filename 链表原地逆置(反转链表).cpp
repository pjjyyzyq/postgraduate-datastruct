#include<iostream>
using namespace std;

/*试编写算法将带头结点的单链表就地（无需额外的辅助空间）逆置*/

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;

// 头插法逆置
void reverse(LinkList &L){
    LinkNode *p,*r;
    p=L->next;
    L->next=NULL;
    // 原地逆置要先遍历再头插，每遍历一个头插一个
    while(p!=NULL){
        // r先保存当前结点的下一个结点
        r=p->next;
        // 当前结点插入到头结点之后
        p->next=L->next;
        L->next=p;
        // p指向下一个结点r
        p=r;
    }
}

// 双指针法逆置
void reverse_1(LinkList &L){
    LinkNode *pre=NULL,*p=L;
    while(p!=NULL){
        LinkNode *temp=p->next;
        pre=p;
        p=temp;
        // 指针反转
        p->next=pre;
    }
    L->next=pre;
}