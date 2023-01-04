#include<iostream>
using namespace std;

/*假设二叉树采用二叉链表存储结构，
设计一个算法，
求非空二叉树b的宽度*/

typedef struct BiTNode{
    int data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;

