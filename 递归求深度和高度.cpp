#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*根节点的高度等于二叉树的深度*/

/*结点的深度表示该结点到根节点的距离，二叉树的深度等于其所有结点的最大深度，
根节点的深度为1，根节点的孩子结点深度为2*/
int depth(BiTree T){
    // 递归终止条件，即递归出口
    if(T==NULL){
        return 0;
    }
    else{
        // 后续遍历求树的高度间接求树的深度（因为树的高度等于树的深度），按左右中顺序递归
        int depthLeft=depth(T->lchild);
        int depthRight=depth(T->rchild);
        int depthVal=max(depthLeft,depthRight)+1;
        return depthVal;
    }
}

/*结点的高度表示该节点到叶子结点的距离，二叉树的高度等于其所有结点到叶子结点的最大距离
叶子结点的高度*/
int height(BiTree T){
    // 递归终止条件，即递归出口
    if(T==NULL){
        return 0;
    }
    else{
        // 后续遍历，左右中
        int lefthight=depth(T->lchild);
        int righthight=depth(T->rchild);
        int height=max(lefthight,righthight)+1;
        return height;
    }
}