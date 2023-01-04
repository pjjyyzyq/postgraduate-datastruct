#include<iostream>
using namespace std;

/*给定两个单链表，编写算法找出两个链表公共结点*/

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;


LinkList Search_com(LinkList L1, LinkList L2){
    int len1=Length(L1);
    int len2=Length(L2);
    // 较长链表指针longList，较短链表指针shortList
    LinkList longList,shortList;
    // 表长之差dist
    int dist;
    // 如果L1较长
    if(len1>len2){
        longList=L1->next;
        shortList=L2->next;
        dist=len1-len2;
    }
    // 如果L2较长
    else{
        longList=L2->next;
        shortList=L1->next;
        dist=len2-len1;
    }
    // 较长的链表向后遍历dist个结点
    while(dist--){
        longList=longList->next;
    }
    // 开始逐个比较两个链表的结点
    while(longList!=NULL){
        // 如果两个指针相等，则找到公共结点，返回其头结点指针
        if(longList==shortList){
            return longList;
        }
        // 两指针不相等，继续遍历下一个结点
        else{
            longList=longList->next;
            shortList=shortList->next;
        }
    }
    return NULL;
}
