#include<iostream>
using namespace std;

typedef int ElemType;

// 二叉树结点和整个树的结构体定义
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

// 辅助链队列结构体定义
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LiQueue;

// 不带头结点链队列的初始化
bool InitQueue(LiQueue &Q){
    Q.front=Q.rear=NULL;
    return true;
}

// 不带头结点链队列判空
bool IsEmpty(LiQueue Q){
    if(Q.front==NULL)
        return true;
    else
        return false;
}

// 不带头结点链队列入队
bool EnQueue(LiQueue &Q, BiTree x){
    // 链队列入队前无需判满
    // 申请新结点存储x
    LinkNode *p=(LinkNode *)malloc(sizeof(LinkNode));
    if(p==NULL)
        return false;
    p->data=x;
    p->next=NULL;
    // 把新结点连在队列队尾
    if(Q.front==NULL)
        Q.front=p;
    if(Q.rear!=NULL)
        Q.rear->next=p;
    Q.rear=p;
    return true;
}

// 不带头结点链队列出队
bool DeQueue(LiQueue &Q, BiTree &x){
    // 不带头结点链队列出队前要先判空
    if(Q.front==NULL)
        return false;//队空则报错
    LinkNode *p=Q.front;
    x=p->data;
    Q.front=p->next;//队头指针指向下一个结点
    free(p);
    return true;
}

// 访问二叉树的根结点
void visit(BiTree T){
    // 防止空指针错误
    if(T==NULL)
        return;
    cout<<T->data<<" ";
}

// 二叉树的先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        // 先访问根节点
        visit(T);
        // 递归遍历右子树
        PreOrder(T->lchild);
        // 递归遍历左子树
        PreOrder(T->rchild);
    }
}

// 二叉树的中序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

// 二叉树的后续遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

// 二叉树的层序遍历
void LevelOrder(BiTree T){
    // 定义一个链队列作为辅助队列实现二叉树的层次遍历
    LiQueue Q;
    // 初始化链队列
    InitQueue(Q);
    // 扫描二叉树结点指针
    BiTree p;
    // 根节点入队
    EnQueue(Q,T);
    while(!IsEmpty(Q)){//队列非空则一直循环
        // 队头结点出队
        DeQueue(Q,p);
        // 访问出队结点
        visit(p);
        // 出队结点左孩子不为空,左孩子入队
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);
        // 出队结点右孩子不为空,右孩子入队
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);
    }
}

// 树的结点和整棵树的结构体定义，用孩子兄弟表示法
typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild,*nextsibing;//第一个孩子指针，近亲即右边第一个兄弟指针
}CSNode,*CSTree;

// 访问树的根结点
void visit_1(CSTree T){
    // 防止空指针错误
    if(T==NULL)
        return;
    cout<<T->data<<" ";
}

// 树的先根遍历
void PreOrder_1(CSTree T1){
    if(T1!=NULL){
        visit_1(T1);
        // 第一个孩子指针不为空，递归遍历以第一个孩子为根结点的子树
        while(T1->firstchild!=NULL) 
            PreOrder_1(T1->firstchild);
        // 近亲指针不为空，递归遍历以右边第一个兄弟为根节点的子树
        while(T1->nextsibing!=NULL)
            PreOrder_1(T1->nextsibing);
    }
}


// 树的后根遍历，传入根节点指针*R
void PostOrder_1(TreeNode *R){
    if(R!=NULL){
        // 递归的后根遍历下一棵子树
        while(R还有下一棵子树T) 
            PostOrder_1(T);
        // 访问根结点
        visit(R);
    }
}

