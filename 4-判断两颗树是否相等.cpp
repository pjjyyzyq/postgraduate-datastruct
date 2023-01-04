#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 判断二叉树Ta,Tb是否相等，若相等返回1，否则返回0
int judge(BiTree Ta, BiTree Tb){
    if(Ta==NULL&&Tb==NULL){
        return 1;
    }
    if(Ta==NULL||Tb==NULL){
        return 0;
    }
    if(Ta->data!=Tb->data){
        return 0;
    }
    return judge(Ta->lchild,Tb->lchild)&&judge(Ta->rchild,Tb->rchild);
}