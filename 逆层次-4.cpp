#include<iostream>
using namespace std;

/*题目：假设二叉树采用二叉链表存储结构，
试写出二叉树自下而上，从右到左的层次遍历算法，
并用文字解释如何求二叉树的深度*/

/*算法思想：利用原有的层次遍历算法，
出队的同时将各结点指针入栈，
在所有结点入栈后再从栈顶开始依次访问即为所求算法。
具体实现如下：
1.把根节点入队
2.把一个元素出队列，遍历这个元素。
3.依次把这个元素的左孩子、右孩子入队列。
4.若队列不空，则跳到2，否则结束
算法实现如下：*/

typedef struct BiTNode{
    int data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void InvertLevel(BiTree bt){
    // 定义辅助队列
    Queue Q;
    // 定义辅助栈
    Stack S;
    // 检查参数合法性
    if(bt!=NULL){
        // 初始化栈，栈中存放二叉树结点的指针
        InitStack(S);
        // 初始化队列，队列中存放二叉树结点的指针
        InitQueue(Q);
        // 根节点入Q队，传入参数为根节点指针bt
        EnQueue(Q,bt);
        // 循环直到辅助队列为空
        while(!IsEmpty(Q)){
            // 出Q队，返回参数为队头结点的指针p
            DeQueue(Q,p);
            // 入S栈，传入参数为队头结点的指针p
            Push(S,p);
            // 若左指针不为空，左孩子入队
            if(p->lchild)
                EnQueue(Q,p->lchild);
            // 若右指针不为空，则右孩子入队
            if(p->rchild)
                EnQueue(Q,p->rchild);
        }
        // 自下尔上，从右到左的层次遍历
        while(!IsEmpty(S)){
            Pop(S,p);
            visit(p->data);
        }
    }
}