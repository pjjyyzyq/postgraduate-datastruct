#include<iostream>
using namespace std;

/*给定两个递增的有序链表List1[n]和List2[m]，
请设计一个算法合并它们得到一个新链表，
新链表形如：如果n>=m，那么新链表为{A1,B1,A2,B2,...,Am,Bm,Am+1,...,An}；
如果n<=m，那么新链表为{A1,B1,A2,B2,...,An,Bn,Bn+1,...,Bm}。*/

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;

LinkList Merge(LinkList List1,LinkList List2){
    // p和q为工作指针，初始时分别指向List1和List2的首元结点
    LinkNode *p=List1->next,*q=List2->next;
    // MergeList为合并后新的链表
    LinkList MergeList;
    // 初始化新链表
    InitList(MergeList);
    // temp为工作指针，初始指向新链表的头结点
    LinkNode *temp=MergeList;
    while(p!=NULL&&q!=NULL){
        temp->next=p;
        temp=temp->next;
        p=p->next;
        temp->next=q;
        q=q->next;
        temp=temp->next;
    }
    // n>=m时
    if(p!=NULL)
        temp->next=p;
    // m>=n时
    else
        temp->next=q;
    // 释放List1和List2的头结点
    free(List1);
    free(List2);
    // 返回合并后链表的头指针
    return MergeList;
}