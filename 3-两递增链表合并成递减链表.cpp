#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkList;

LinkList merge(LinkList &la,LinkList &lb){
    /* 思路：遍历la，lb，每次循环比较链表工作结点选出最小的结点，
    将该结点以头插法方式插入到lc头结点之后 */
    LinkList lc;
    lc->next=NULL;
    LinkNode *pa=la->next;
    LinkNode *pb=lb->next;
    LinkNode *temp;
    while(pa&&pb){
        // pa结点值较小
        if(pa->data<pb->data){
            temp=pa->next;
            pa->next=lc->next;
            lc->next=pa;
            pa=temp;
        }
        // pb结点值较小
        else{
            temp=pb->next;
            pb->next=lc->next;
            lc->next=pb;
            pb=temp;
        }

    }
    // 如果pa未遍历完
    while(pa){
        temp=pa->next;
        pa->next=lc->next;
        lc->next=pa;
        pa=temp;
    }
    // 如果pb未遍历完
    while(pb){
        temp=pb->next;
        pb->next=lc->next;
        lc->next=pb;
        pb=temp;
    }
    return lc;
}
