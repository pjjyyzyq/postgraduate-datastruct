#include<iostream>
using namespace std;

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;

// 删除带头结点单链表中值为x的结点(非递归算法)
void delete_x(LinkList &L){
    // 工作结点p，初始指向头结点
    LinkNode *p=L;
    // 每次对p的后继结点进行操作，这样在删除结点时无需再定义一个pre指针
    while(p->next!=NULL){
        // 如果p的后继结点data为x
        if(p->next->data==x){
            // 用r指向待删除结点
            LinkNode *r=p->next;
            // 将待删除结点从链表中剔除
            p->next=r->next;
            // 释放待删除结点空间
            free(r);
        }
        // 如果p的后继结点data不为x
        else{
            p=p->next;
        }
    }
}