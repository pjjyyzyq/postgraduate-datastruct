#include<iostream>
using namespace std;

/*已知二叉树以二叉链表存储，编写算法完成：
对于树中每个元素值为x的结点，
删去以它为根的子树，
并释放相应的空间*/

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;   
}BiTNode,*BiTree;

// 删除以T为根节点的子树
// 后序遍历实现
void DeleteTree(BiTree &T){
    if(T){
        DeleteTree(T->lchild);
        DeleteTree(T->rchild);
        free(T);
    }
}

// 在二叉树上查找所有以x为元素值的结点，并删除以其为根的子树
// 层序遍历实现
void Search_x_delete_tree(BiTree &T){
    // Q是存放二叉树结点指针的辅助队列
    BiTree Q[];
    if(T){
        // 若根节点元素值为x时
        if(T->data==x){
            DeleteTree(T);
            return;
        }
        // 若根结点元素值不为x
        // 初始化队列Q
        InitQueue(Q);
        // 根结点入队
        EnQueue(Q,T);
        while(!IsEmpty(Q)){
            BiTree p;
            DeQueue(Q,p);
            // 若当前出队结点p左孩子不为空
            if(p->lchild){
                // 若当前左孩子元素值为x
                if(p->lchild->data==x){
                    DeleteTree(p->lchild);
                    p->lchild=NULL;
                }
                // 若当前左孩子元素值不为x
                else{
                    EnQueue(Q,p->lchild);
                }
            }
            // 若当前出队结点p右孩子不为空
            if(p->rchild){
                // 若当前右孩子元素值为x
                if(p->rchild->data==x){
                    DeleteTree(p->rchild);
                    p->rchild=NULL;
                }
                // 若当前右孩子元素值不为x
                else{
                    EnQueue(Q,p->rchild);
                }
            }
        }
    }
}