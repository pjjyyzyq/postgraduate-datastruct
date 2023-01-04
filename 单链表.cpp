#include<iostream>
#include<stdlib.h>
using namespace std;

// 插入结点默认为*s，工作结点或指定结点默认为*p

typedef int ElemType;

// 单链表结点类型的定义
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

// 不带头结点单链表的初始化
bool InitList_1(LinkList &L){
    L=NULL;//头指针指向空
    return true;
}

// 判断不带头结点单链表是否为空
bool Empty_1(LinkList L){
    if(L==NULL)
        return true;
    else
        return false;
}

// 不带头结点单链表按位序插入（在L第i个位置插入元素e,思路：先找到第i-1个结点，再在该结点后插一个数据域为e的结点）
bool ListInsert_1(LinkList &L,int i, ElemType e){
    if(i<1)//检查参数i的合法性,i=1表示在第1个位置即表头插入,则i<1时不合法
        return false;
    if(i==1){//不带头结点的单链表没有第0个结点，所以在第1个位置插入时要特殊处理
        LNode *s=(LNode*)malloc(sizeof(LNode));
        s->data=e;
        s->next=L;
        L=s;
        return true;
    }    
    LNode *p=L;//工作结点指针，开始指向头结点
    int j=1;//当前工作结点是第1个结点，无第0个结点
    while(p!=NULL&&j<i-1){//j=i-1时跳出循环，此时p指向第i-1个结点
        p=p->next;
        j++;
    }
    if(p==NULL)//p==NUll时说明i超出链表长度，i不合法
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));//申请一个结点大小的内存空间存储元素e对应的结点
    s->data=e;//结点的数据域为e
    s->next=p->next;//先连后面，结点的指针域为第i-1个结点的指针域
    p->next=s;//再连前面，第i-1个结点的指针域为s
    return true;
}

// 带头结点单链表的初始化
bool InitList_2(LinkList &L){
    L=(LNode*)malloc(sizeof(LNode));//为头结点在内存中分配一块空间！！！注意这里与不带头结点单链表有很大区别
    if(L==NULL){
        return false;//内存不足，分配失败
    }
    L->next=NULL;//头结点指针指向空
    return true;
}

// 判断带头结点单链表是否为空
bool Empty_2(LinkList L){
    if(L->next==NULL)
        return true;
    else
        return false;
}

// 带头结点单链表按位序插入（在L第i个位置插入元素e,思路：先找到第i-1个结点，再在该结点后插一个数据域为e的结点）
bool ListInsert_2(LinkList &L,int i, ElemType e){
    if(i<1)//检查参数i的合法性,i=1表示在第1个位置即表头插入,则i<1时不合法
        return false;
    LNode *p=L;//工作结点指针，开始指向头结点
    int j=0;//当前工作结点是第0个结点
    while(p!=NULL&&j<i-1){//j=i-1时跳出循环，此时p指向第i-1个结点
        p=p->next;
        j++;
    }
    if(p==NULL)//p==NUll时说明i超出链表长度，i不合法
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));//申请一个结点大小的内存空间存储元素e对应的结点
    s->data=e;//结点的数据域为e
    s->next=p->next;//先连后面，结点的指针域为第i-1个结点的指针域
    p->next=s;//再连前面，第i-1个结点的指针域为s
    return true;
}

// 带头结点单链表在指定结点*p后面插入元素e
bool InsertNextNode(LNode *p,ElemType e){
    if(p==NULL)//判断参数p的合法性
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));//申请一个结点大小的内存空间存储元素e对应的结点
    if(s==NULL)
        return false;//系统内存不足，s==NULL说明此次分配失败
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;  
}

// 带头结点单链表在指定结点*p前面插入元素e
bool InsertPriorNode(LNode *p, ElemType e){
    if(p==NULL)//判断参数p的合法性
        return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    if(s==NULL)
        return false;
    s->next=p->next;
    p->next=s;
    s->data=p->data;//交换*p,*s两节点的数据域
    p->data=e;
    return true;
}

// 带头结点单链表按位序i删除结点，该结点数据域的值存在e中
bool DeleteI(LinkList &L, int i, ElemType &e){
    if(i<1)//i<1时无意义，不合法
        return false;
    LNode *p=L;//p指向当前扫描到的结点，开始时指向头结点
    int j=0;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL)//i>链表长度时不合法
        return false;
    if(p->next==NULL)//第i-1个结点是最后一个结点时不合法
        return false;
    LNode *q=p->next;//q指向*p的后继结点即第i个结点
    // 这里不能p=p->next,而是额外定义一个新结点*q,因为在删除某个结点时，必须都要知道指向该结点和该结点前驱结点的两个指针
    e=q->data;
    p->next=q->next;
    free(q);
    return true;
}

// 带头结点单链表指定结点*P的删除
bool DeleteNode(LNode *p){
    if(p==NULL)
        return false;
    if(p->next==NULL)//该结点是最后一个结点时,后续代码无法实现删除,必须要传入头指针参数
        return false;
    LNode *q=p->next;
    p->data=q->data;
    p->next=q->next;
    free(q);
    return true;
}

// 带头结点单链表按位查找,返回单链表L第i个结点
LNode* GetElem(LinkList L, int i){
    if(i<0)//考虑i的合法性时先考虑i的边界情况,此处边界情况是i=0时可以返回头结点,i<0才不合法
        return NULL;
    LNode *p=L;
    int j=0;
    while(p!=NULL&&j<i){//循环找到第i个结点
        p=p->next;
        j++;
    }
    return p;
}

// 带头结点单链表按值查找,返回单链表中数据域为e的结点
LNode* LocateElem(LinkList L, ElemType e){
    LNode *p=L->next;
    while(p!=NULL&&p->data!=e)//循环找到数据域为e的结点
        p=p->next;
    return p;
}

// 带头结点单链表的建立(尾插法)
LinkList List_TailInsert(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    LNode *s, *r=L;//s为循环待插入结点指针，r为表尾指针
    while(scanf("%d",&x)!=EOF){
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
    }
    r->next=NULL;//表尾结点指针域指向空
    return L;
}

// 带头结点单链表的建立(头插法)
LinkList List_HeadInsert(LinkList &L){
    int x;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;//初始化时记得头结点的指针域指向空，养成习惯
    LNode *s;
    while(scanf("%d",&x)!=EOF){
        s=(LNode *)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
    }
    return L;
}

// 主函数
int mian(){
    LinkList L;
    List_TailInsert(L);
    return 0;
}