#include<iostream>
using namespace std;

typedef int ElemType;

// 双链表结点类型的定义
typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;//前驱结点指针和后继结点指针
}DNode,*DLinkList;

// 带头结点双链表的初始化
bool InitDLinkList(DLinkList &L){
    L=(DNode *)malloc(sizeof(DNode));//分配一个头结点
    if(L==NULL)
        return false;//内存分配失败
    L->prior=NULL;//头结点前驱指针永远指向NULL
    L->next=NULL;//头结点之后暂时没有结点,后继指针指向NULL
    return true;
}

// 带头结点双链表判断是否为空
bool Empty(DLinkList L){
    if(L->next==NULL)
        return true;
    else
        return false;
}

// 带头结点双链表在指定结点*p后面插入结点*s
bool InsertNextDNode(DNode *p, DNode *s){
    // 第一步检验参数的合法性
    if(p==NULL||s==NULL)
        return false;
    // 第二步再考虑函数要实现的功能
    // 先连后面的
    s->next=p->next;
    if(p->next!=NULL)//防止*p是链表最后一个结点从而p->next==NULL
        p->next->prior=s;
    // 再连前面的
    s->prior=p;
    p->next=s;
    return true;
}

// 带头结点双链表在指定结点*p前面插入结点*s
bool InsertPriorDNode(DNode *p, DNode *s){
    // 第一步检验参数的合法性
    if(p==NULL||s==NULL)
        return false;
    // 第二步实现函数的功能
    return InsertNextDNode(p->prior,s);
}

// 带头结点双链表删除指定结点*p的后继结点
bool DeleteNextDNode(DNode *p){
    //第一步检验参数的合法性
    if(p==NULL)
        return false;
    // 第二步实现函数功能
    DNode *q=p->next;
    if(q==NULL)//p结点没有后继，返回false
        return false;
    p->next=q->next;//
    if(q->next!=NULL)//q结点不是最后一个结点，才能连前面
        q->next->prior=p;
    free(q);
    return true;
}

// 销毁带头结点双链表
void DestoryList(DLinkList &L){
    // 循环删除头结点的后继结点
    while(L->next!=NULL)
        DeleteNextDNode(L);//删除头结点的后继结点
    free(L);//释放头结点
    L=NULL;//头指针指向空
}

// 带头结点双链表的后向遍历
void traversal(DLinkList L){
    DNode *p=L->next;
    while(p!=NULL){
        p=p->next;
    }    
}


// 主函数
int mian(){
    DLinkList L;
    InitDLinkList(L);
    return 0;
}