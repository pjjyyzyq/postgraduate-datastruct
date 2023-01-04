#include<iostream>
using namespace std;

typedef int ElemType;

// 链栈结构体定义
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
} *LiStack;

// 链栈更推荐不带头结点的实现方式
// 不带头结点链栈的初始化
bool InitLiStack_1(LiStack &S){
    S=NULL;
    return true;
}

// 带头结点链栈的初始化
bool InitLiStack_2(LiStack &S){
    S=(LinkNode *)malloc(sizeof(LinkNode));
    if(S==NULL)
        return false;
    S->next=NULL;
    return true;
}

// 不带头结点链栈中新元素x入栈
bool Push_1(LiStack &S, ElemType x){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    if(p==NULL)//注意每次用malloc函数申请内存后要考虑申请失败的情况，这一点容易忘
        return false;
    p->data=x;
    // 头指针指向栈顶，入栈等于让头指针指向新结点
    p->next=S;
    S=p;
    return true;
}

// 带头结点链栈中新元素x入栈
bool Push_2(LiStack &S, ElemType x){
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    if(p==NULL)
        return false;
    p->data=x;
    // 头结点指针域指向栈顶，入栈等于在头结点后插一个新结点
    p->next=S->next;
    S->next=p;
    return true;
}

// 不带头结点链栈中出栈
bool Pop_1(LiStack &S, ElemType &x){
    if(S==NULL)
        return false;
    LinkNode *p=S;
    x=p->data;
    S=p->next;
    free(p);
    return true;
}
// 带头结点链栈中出栈
bool Pop_2(LiStack &S, ElemType &x){
    if(S->next==NULL)
        return false;
    LinkNode *p=S->next;
    x=p->data;
    S->next=p->next;
    free(p);
    return true;
}

// 不带头结点链栈判空
bool Empty_1(LiStack S){
    if(S==NULL)
        return true;
    else
        return false;
}

// 带头结点链栈读栈顶
bool GetTop_1(LiStack S, ElemType &x){
    if(S->next==NULL)
        return false;
    x=S->next->data;
    return true;
}

// 不带头结点链栈读栈顶
bool GetTop_2(LiStack S, ElemType &x{
    if(S==NULL)
        return false;
    x=S->data;
    return true;
}

// 带头结点链栈的销毁
void DestoryStack_1(LiStack &S){
    LinkNode *p=S->next;
    LinkNode *q;
    while(p!=NULL){
        q=p;
        p=p->next;
        free(q);
    }
    free(S);
    S=NULL;
}

// 不带头结点链栈的销毁
void DestoryStack_2(LiStack &S){
    LinkNode *p;
    while(S!=NULL){
        p=S;
        S=S->next;
        free(p);   
    }
    S=NULL;
}

// 带头结点链栈判空
bool Empty_2(LiStack S){
    if(S->next==NULL)
        return true;
    else
        return false;
}

int main(){
    LiStack S;
    InitLiStack_1(S);
    return 0;
}