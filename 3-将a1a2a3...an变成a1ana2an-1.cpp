#include<iostream>
using namespace std;

typedef struct LNode{
    int data;
    struct LNode *next;
}Node;

void ListChange(Node *h){
    // 第一步先找到链表的中间结点
    Node *p=h,*q=h;
    while(q&&q->next){
        p->next;
        q=q->next->next;
    }
    // 第二步把链表中间结点之后的链表逆置，此时把中间结点p看做头结点用头插法
    // 临时头结点headtemp初始指向p
    Node* headtemp=p;    
    // 工作结点p先指向头结点后第一个结点
    p=headtemp->next;
    // 头结点先断链
    headtemp->next=NULL;
    Node* temp;
    while(p){
        temp=p->next;
        p->next=headtemp->next;
        headtemp->next=p;
        p=temp;
    }
    // 第三步将前后两个链表合并
    // p指向前半部分链表的第一个结点
    p=h->next;
    // s指向后半部分链表的第一个结点
    Node* s=headtemp->next;
    while(s){
        // 防止断链
        temp=s->next;
        // 插入操作
        s->next=p->next;
        p->next=s;
        // p，s指针向后移一位
        p=s->next;
        s=temp;
    }
}

