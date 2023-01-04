#include<iostream>
using namespace std;

/*删除一颗二叉树 */

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

// 后序遍历删除一颗二叉树
void DeleteTree(BiTree T){
    // 如果T是空树返回
    if(T==NULL){
        return;
    }
    // 递归的遍历当前结点T的左子树
    DeleteTree(T->lchild);
    // 递归的遍历当前结点T的右子树
    DeleteTree(T->rchild);
    // 删除当前结点T
    free(T);
}