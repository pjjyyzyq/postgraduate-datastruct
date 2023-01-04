#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 后序方式实现，返回树T的深度
int depth(BiTree T){
    if(T==NULL){
        return 0;
    }
    // 左
    int leftdepth=depth(T->lchild)+1;
    // 右
    int rightdepth=depth(T->rchild)+1;
    // 根
    return leftdepth>rightdepth?leftdepth+1:rightdepth+1;
}