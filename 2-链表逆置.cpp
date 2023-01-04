#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkList;

// 实现链表的逆置，head是头结点指针
void reverse(LinkList &head){
    // 初始化
    LinkNode *p=head->next;
    head->next=NULL;
    // 因为事先不知道循环的次数，所以用while循环
    // 1.考虑循环实现什么？循环实现从第一个结点开始遍历链表的每个结点
    // 2.考虑循环变量是什么？循环变量是工作指针p
    // 3.考虑循环的条件是什么？循环变量p开始指向链表第一个结点，p最后指向链表的最后一个结点
    while(p!=NULL){
        // 4.每轮循环对结点p做什么？用头插法方式在头结点h之后插入结点p
        // 5.如何进入下一轮循环？p指向其后继结点（注意中间头插方式会断链，所以需要一个临时变量）
        LinkNode* temp=p->next;
        p->next=head->next;
        head->next=p;
        p=temp;
    }
}

// 实现链表的逆置，head是头结点指针
void reverse_1(LinkList &head){
    // 初始化
    LinkNode *p=head->next;
    LinkNode *pre=NULL;
    // 1.循环实现什么？遍历链表的每一个结点
    // 2.循环变量是什么？p
    // 3.循环条件是什么？第一轮循环p指向第一个结点，最后一轮循环p指向最后一个结点，p==NULL循环结束
    while(p!=NULL){
        // 4.每轮循环对循环变量p做什么？尾插法方式在头结点h后插入结点p
        // 5.如何进入下一轮循环？p指向其后继结点
        LinkNode *temp=p->next;
        // p是前面的结点，pre是后面的结点，尾插法方式是前面的直接连后面的
        p->next=pre;
        pre=p;
        p=temp;
    }
    head->next=pre;
}