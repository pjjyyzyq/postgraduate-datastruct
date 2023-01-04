#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType weight;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 二叉树的带权路径长度是所有叶子结点的带权路径长度之和

// 先序方式，返回二叉树的带权路径长度wpl
int WPL(BiTree root,int depth){
    static int wpl=0;
    if(root){
        // 根
        if(root->rchild==NULL&&root->rchild==NULL){
            // 叶子结点的带权路径长度等于深度乘以权重
            wpl+=(root->weight)*depth;
        }
        // 左
        WPL(root->lchild,depth+1);
        // 右
        WPL(root->rchild,depth+1);
    }
    return wpl;
}

int main(){
    BiTree root;
    // 默认根节点是第一层
    WPL(root,1);
}