#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkList;

// 将q结点插入到p结点之后
void Insert(LinkNode *p, LinkNode *q){
    // 头插法方式
    // 先连后面
    q->next=p->next;
    // 再连前面
    p->next=q;
    
    // 尾插法方式
    // 设置一个临时指针变量保存原先p结点的后继链表，防止断链
    LinkNode *temp=p->next;
    // 直接先连前面，即在前面的结点直接连接后面的结点
    p->next=q;
    // 再连后面
    q->next=temp; 
}



typedef struct DLinkNode{
    ElemType data;
    struct DLinkNode *prior,*next;
}DLinkNode,*DLinkList;

void InsertD(DLinkNode *p, DLinkNode *q){
    // 将q结点插入到p结点之后
    // 先连后面
    q->next=p->next;
    p->next->prior=q;
    // 再连前面
    p->next=q;
    q->prior=p;

    // 将q结点插入到p结点之前
    // 可看做对称的操作
    // 先连前面
    q->prior=p->prior;
    p->prior->next=q;
    // 再连后面
    p->prior=q;
    q->next=p;
}