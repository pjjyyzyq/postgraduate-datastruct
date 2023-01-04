#include<iostream>
using namespace std;

typedef int ElemType;

// 循环单链表结构体定义
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *CLinkList;

// 带头结点循环单链表的初始化
bool InitList(CLinkList &L){
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL)
        return false;
    L->next=L;//这里指向自己，不指向NULL
    return L;
}

// 判断带头结点循环单链表是否为空
bool Empty_CLinkList(CLinkList L){
    if(L->next==L)//头结点指针域指向自身，则表为空
        return true;
    else
        return false;
}

// 判断结点*p是否为循环单链表的表尾结点
bool isTail(CLinkList L, LNode *p){
    if(p->next==L)//当前结点指针域指向头结点，则该结点为表尾结点
        return true;
    else
        return false;
}

// 循环双链表结构体定义
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *CDLinkList;

// 带头结点循环双链表的初始化
bool InitCDLinkList(CDLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));
    if(L==NULL)
        return false;//内存不足,上面malloc函数申请新内存失败
    L->next=L;//头结点的后指针指向自身
    L->prior=L;//头结点的前指针指向自身
    return true;    
}

// 判断带头结点循环双链表是否为空
bool Empty_CDLinkList(CDLinkList L){
    if(L->next==NULL)
        return true;
    else
        return false;
}

// 判断指定结点*p是否为循环链表表尾结点
bool isTail(CDLinkList L, DNode *p){
    if(p->next==L)
        return true;
    else
        return false;
}

// 带头结点循环双链表在指定结点*p后插入*s结点
bool InsertNextDNode(DNode *p, DNode *s){
    // 第一步检验参数的合法性
    if(p==NULL||s==NULL)
        return false;
    // 第二步实现函数功能
    s->next=p->next;//插入结点*s后继指针指向*p的后继结点
    // 这里与普通双链表不同，无需考虑*p是最后一个结点造成指针异常
    p->next->prior=s;//*p的后继结点的前驱指针指向插入结点*s
    s->prior=p;//插入结点*s的前驱指针指向*p结点
    p->next=s;//*p结点的后继指针指向插入结点*s
    return true;
}

// 带头结点循环双链表删除指定结点*p的后继结点
bool DeleteNextDNode(DNode *p){
    //第一步检验参数的合法性
    if(p==NULL)
        return false;
    // 第二步实现函数功能
    DNode *q=p->next;
    p->next=q->next;   
    // 这里也无需考虑*q是最后一个结点造成指针异常  
    q->next->prior=p;
    free(q);
    return true;
}


// 主函数
int main(){
    CLinkList L;
    InitList(L);
    return 0;
}