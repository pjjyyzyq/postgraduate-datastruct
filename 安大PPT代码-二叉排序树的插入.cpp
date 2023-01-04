#include<iostream>
using namespace std;

/*题目：在二叉排序树T中插入一个数据元素x*/

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

// PPT非递归实现
void BST_Insert(BiTree &T,ElemType x){
    // 保存插入结点s
    BiTNode *s;
    s=(BiTNode *)malloc(sizeof(BiTNode));
    s->data=x;
    s->lchild=s->rchild=NULL;
    // 寻找插入位置
    if(T==NULL){
        T=s;
    }
    else{
        // 定义工作结点指针p和其父节点指针pre
        BiTNode *p,*pre;
        // 从根结点开始遍历，寻找合适的插入位置
        p=T;
        while(p!=NULL){
            if(x==p->data)
                return;
            pre=p;
            else if(x<p->data)
                p=p->lchild;
            else
                p=p->rchild;
        }
        // 插入结点s
        if(x<pre->data)
            pre->lchild=s;
        else
            pre->rchild=s;
    }
}
