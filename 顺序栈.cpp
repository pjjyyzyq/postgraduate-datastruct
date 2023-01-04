#include<iostream>
using namespace std;

typedef int ElemType; 

// 顺序栈结构体定义
#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

// 顺序栈的初始化
void InitStack(SqStack &S){
    S.top=-1;//-1表示top指向栈顶元素，若为0，则表示top指向栈顶元素的下一个位置即下一次入栈插入元素位置
}

// 判断顺序栈是否为空
bool StackEmpty(SqStack S){
    if(S.top==-1)
        return true;
    else
        return false;
}

// 新元素x入栈
bool Push(SqStack &S, ElemType x){
    if(S.top==MaxSize-1)//栈满
        return false;
    S.data[++S.top]=x;
    return true;
}

// 出栈
bool Pop(SqStack &S, ElemType &x){
    if(S.top==-1)//栈空
        return false;
    x=S.data[S.top--];
    return true;
}

// 共享栈结构体定义
#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int top1;//1号栈栈顶指针
    int top2;//2号栈栈顶指针
}ShStack;

// 共享栈的初始化
void InitShStack(ShStack &S){
    S.top1=-1;
    S.top2=MaxSize;
}

// 共享栈1号栈新元素x入栈
bool Push_1(ShStack &S, ElemType x){
    if(S.top1+1==S.top2)//1号栈栈满
        return false;
    S.data[++S.top1]=x;
    return true;
}

// 共享栈1号栈出栈
bool Pop_1(ShStack &S, ElemType &x){
    if(S.top1==-1)//1号栈空
        return false;
    x=S.data[S.top1--];
    return true;
}

// 共享栈2号栈新元素x入栈
bool Push_2(ShStack &S, ElemType x){
    if(S.top2-1==S.top1)//2号栈满
        return false;
    S.data[--S.top2]=x;
    return true;
}

// 共享栈2号栈出栈
bool Pop_2(ShStack &S, ElemType &x){
    if(S.top2==MaxSize)//2号栈空
        return false;
    x=S.data[S.top2++];
    return true;
}

// 主函数
int main(){
    SqStack S;
    InitStack(S);
    return 0;
}