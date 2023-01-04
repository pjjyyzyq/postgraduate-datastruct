#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

// 删除链表L的偶数结点
void Delete(LinkList &L){
    LNode *p=L;
    LNode *temp;
    while(p->next!=NULL){
        if(p->next->data%2==0){
            temp=p->next;
            p->next=temp->next;
            free(temp);
        }
        p=p->next;
    }
}