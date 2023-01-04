#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkList;

void deleteList_between_min_max(LinkList &L, int min, int max){
    LinkNode *p=L;
    LinkNode *temp;
    // 每轮循环判断p的后继结点
    while(p->next!=NULL){
        if((p->next->data>=min)&&(p->next->data<=max)){
            temp=p->next;
            p->next=temp->next;
            free(temp);
        }
        else{
            p=p->next;
        }
    }
}