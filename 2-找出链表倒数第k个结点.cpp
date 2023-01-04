#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *link;
}LNode,*LinkList;

// 查找链表List倒数第k个结点，若查找成功，输出该结点data域的值，并返回1，否则只返回0
int Search_k(LinkList &List, int k){
    LNode *p=List->link,*q=List->link;
    int count=0;
    while(q!=NULL){
        if(count<k){
            count++;
        }
        else{
            p=p->link;
        }
        q=q->link;
    }
    if(count<k){
        return 0;
    }
    else{
        cout<<p->data;
        return 1;
    }
} 