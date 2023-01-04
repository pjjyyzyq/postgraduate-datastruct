#include<iostream>
using namespace std;

/*假设有两个按元素递增次序排列的线性表，
均以单链表形式存储。
请编写算法将这两个单链表归并为一个按元素递减次序排列的单链表，
并要求利用原来两个单链表的结点存放归并后的单链表*/

typedef struct LinkNode{
    int data;
    struct LinkNode *next; 
}LinkNode,*LinkList;

void MergeList(LinkList &La,LinkList &Lb){
    // pa和pb分别为La和Lb的工作指针，初始时分别指向La和Lb的首元结点
    LinkNode *pa=La->next,*pb=Lb->next;
    // r临时存放后继结点指针
    LinkNode *r;
    while(pa!=NULL&&pb!=NULL){
        // pa当前指向结点值更小
        if(pa->data<=pb->data){
            // r临时存放pa当前指向结点的后继结点指针
            r=pa->next;
            // pa插在La头结点后面
            pa->next=La->next;
            La->next=pa;
            // pa指向后一个结点
            pa=r;
        }
        // pb当前指向结点值更小
        else{
            // r临时存放pb当前指向结点的后继结点指针
            r=pb->next;
            // pb插在La头结点后面
            pb->next=La->next;
            La->next=pb;
            // pb指向后一个结点
            pb=r;
        }
    }
}