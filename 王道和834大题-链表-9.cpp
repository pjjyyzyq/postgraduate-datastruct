#include<iostream>
using namespace std;

/* 给定一个带表头结点的单链表，设head为头指针，结点的结构为(data,next),data为整型元素，next为指针，
   试写出算法：按递增次序输出单链表中各结点的数据元素，
   并释放结点所占的存储空间(要求：不允许使用数组作为辅助空间)
*/

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;

// 循环每次找出最小值结点，输出其值并释放结点空间 
void CyCyc_Min_Delete(LinkList &head){
    // 循环直到仅剩头结点
    while(head->next!=NULL){
        // pre为最小值结点的前驱结点的指针
        LinkNode *pre=head;
        // p为工作指针
        LinkNode *p=head->next;
        // 循环直到找到最小值结点
        while(p->next!=NULL){
            if(p->next->data<pre->next->data){
                // 记住当前最小值结点的前驱
                pre=p;
            }
            // p指针不断后移
            p=p->next;
        }
        // 输出最小值结点的数据域
        print(pre->next->data);
        LinkNode* u=pre->next;
        pre->next=u->next;
        // 删除最小值结点，释放结点空间
        free(u);
    }
    // 删除头结点，释放结点空间
    free(head)
}