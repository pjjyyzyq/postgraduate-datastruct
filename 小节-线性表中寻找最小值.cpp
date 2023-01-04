#include<iostream>
using namespace std;

#define MaxSize 100

// 顺序表存储结构定义
typedef struct{
    int data[MaxSize];
    int len;
}SqList;

// 链表存储结构定义
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode,*LinkList;   

// 遍历数组选出最小值，并记录最小值Min
void SelectArrayMin(int A[],int n){
    // 最小值Min初始化为数组第一个元素的值
    int Min=A[0];
    for(int i=1;i<n;i++){
        if(A[i]<Min)
            Min=A[i];
    }
}

// 遍历顺序表选出最小值，并记录最小值Min
void SelectSqListMin(SqList L){
    // 最小值Min初始化为线性表第一个元素的值
    int Min=L.data[0];
    for(int i=1;i<L.len;i++){
        if(L.data[i]<Min)
            Min=L.data[i];
    }
}

// 遍历带头结点链表选出最小值，并记录最小值结点的前驱结点的指针pre和最小值Min
void SelectLinkListMin(LinkList head){
    // pre指向最小值结点的前驱结点，初始指向第一个结点的前驱结点
    LinkNode *pre=head;
    // 最小值Min初始化为第一个结点的数据域的值
    int Min=pre->next->data
    LinkNode *p=head->next;
    while(p->next!=NULL){
        if(pre->next->data>p->next->data)
            pre=p;
        p=p->next;
    }
    Min=pre->next->data;
}