#include<iostream>
using namespace std;

typedef int ElemType;

// 顺序队列结构体定义
#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int front, rear;
}SqQueue;

// 链队列结构体定义
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LiQueue;

// 顺序队列的初始化
bool InitQueue(SqQueue &Q){
    Q.front=0;
    Q.rear=0;//表示队尾指针指向入队时要插入的位置
    return true;
}

// 带头结点链队列的初始化
bool InitLiQueue_1(LiQueue &Q){
    // 这里Q是个LiQueue类型的变量，不是指针，所以用" . "访问front，rear指针
    Q.front=Q.rear=(LinkNode *)malloc(sizeof(LinkNode));
    if(Q.front==NULL||Q.rear==NULL)
        return false;
    Q.front->next=NULL;//头结点指针域初始指向空
    return true;
}

// 不带头结点链队列的初始化
bool InitLiQueue_2(LiQueue &Q){
    Q.front=Q.rear=NULL;
    return true;
}

// 顺序队列判空
bool Empty_1(SqQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}

// 带头结点链队列判空
bool Empty_2(LiQueue Q){
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}

// 不带头结点链队列判空
bool Empty_3(LiQueue Q){
    if(Q.front==NULL)
        return true;
    else
        return false;
}

// 顺序队列入队
bool EnQueue_1(SqQueue &Q, ElemType x){
    // 顺序队列入队前先判断队是否已满
    if((Q.rear+1)%MaxSize==Q.front)
        return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)&MaxSize;
    return true;
}

// 带头结点链队列入队
bool EnQueue_2(LiQueue &Q, ElemType x){
    // 链队列入队前无需判满
    // 申请新结点存储x
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    if(p==NULL)
        return false;
    p->data=x;
    p->next=NULL;
    // 把新结点连在队列队尾
    Q.rear->next=p;
    Q.rear=p;
    return true;
}

// 不带头结点链队列入队
bool EnQueue_3(LiQueue &Q, ElemType x){
    // 链队列入队前无需判满
    // 申请新结点存储x
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    if(p==NULL)
        return false;
    p->data=x;
    p->next=NULL;
    // 把新结点连在队列队尾
    if(Q.front==NULL)
        Q.front=p;
    if(Q.rear!=NULL)
        Q.rear->next=p;
    Q.rear=p;
    return true;
}

// 顺序队列出队
bool DeQueue_1(SqQueue &Q, ElemType &x){
    // 顺序队列出队前先判断队列是否为空
    if(Q.front==Q.rear)
        return false;//队空则报错
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;//队头指针后移
    return true;
}
// 带头结点链队列出队
bool DeQueue_2(LiQueue &Q, ElemType &x){
    // 带头结点链队列出队前要先判空
    if(Q.front==Q.rear)
        return false;//队空则报错
    LinkNode *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;//队头指针指向下一个结点
    free(p);
    return true;
}

// 不带头结点链队列出队
bool DeQueue_3(LiQueue &Q, ElemType &x){
    // 不带头结点链队列出队前要先判空
    if(Q.front==NULL)
        return false;//队空则报错
    LinkNode *p=Q.front;
    x=p->data;
    Q.front=p->next;//队头指针指向下一个结点
    free(p);
    return true;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
}