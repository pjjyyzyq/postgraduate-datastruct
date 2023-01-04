#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 找出链表Head的中间结点，比如链表长度为3返回第2个结点指针，链表长度为4返回2个结点指针。
LNode* SearchMid(LinkList &Head){
    // 采用双指针遍历模板
    LNode *p=Head,*q=Head;
    // q为空或q->next为空跳出循环
    while(q&&q->next){
        // p每轮循环向后走一步
        p=p->next;
        // q每轮循环向后走两步
        q=q->next->next;
    }
    return p;
}