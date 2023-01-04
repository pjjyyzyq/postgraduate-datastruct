#include<iostream>
using namespace std;

/*以孩子兄弟链表为存储结构，
请设计递归算法求树的深度*/

typedef struct Node{
    int data;
    struct Node *firstchild;
    struct Node *nextsibling;
}*Tree;

int height(Tree T){
    // hc表示孩子子树高度，hs表示兄弟子树高度
    int hc,hs;
    // 树空返回0
    if(T==NULL){
        return 0;
    }
    else{
        // 递归求孩子子树的高度
        hc=height(T->firstchild);
        // 递归求兄弟子树的高度
        hs=height(T->nextsibling);
        // 如果孩子子树高度+1比兄弟子树高度大，返回孩子子树高度+1
        if(hc+1>hs){
            return hc+1;
        }
        // 兄弟子树高度更大，返回兄弟子树高度
        else{
            return hs;
        }
    }
}