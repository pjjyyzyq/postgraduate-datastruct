#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 将链表La拆分大于0和小于0的两条链表，并返回该两条链表的头结点指针Lb，Lc
void split(LinkList &La, LinkList *Lb, LinkList *Lc){
    // 工作指针pa，用于遍历链表La
    LNode *pa=La->next;
    // 初始化Lb，Lc，为了节省空间让Lb使用原链表的头结点
    Lb=La;
    Lc=(LinkList)malloc(sizeof(LNode));
    // Lb，Lc链表的尾指针
    LNode *pb=Lb;
    LNode *pc=Lc;
    while(pa!=NULL){
        if(pa->data<0){
            pb->next=pa;
            pb=pa;
        }
        if(pa->data>0){
            pc->next=pa;
            pc=pa;
        }
        pa=pa->next;
    }
    // 链表拆分完成后记得将尾结点next指针置为空
    pb->next=NULL;
    pc->next=NULL;
}