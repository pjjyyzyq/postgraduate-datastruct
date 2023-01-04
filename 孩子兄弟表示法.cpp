#include<iostream>a
using namespace std;

/*编程求以孩子兄弟表示法存储的森林的叶子结点数*/

typedef struct Node{
    int data;
    struct Node *firstchild;
    struct Node *nextsibling;
}*Tree;

int LeafCount(Tree T){
    // 树空返回0
    if(T==NULL){
        return 0;
    }
    // 如果当前结点无孩子，则当前结点是叶子结点
    if(T->firstchild==NULL){
        return 1+LeafCount(T->nextsibling);
    }
    // 如果当前结点有孩子
    else{
        return LeafCount(T->firstchild)+LeafCount(T->nextsibling);
    }
}
