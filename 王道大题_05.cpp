#include<iostream>
using namespace std;

/*已知一颗二叉树按顺序存储结构进行存储，
设计一个算法，
求编号分别为i和j的两个结点的最近公共祖先结点的值*/

#define MaxSize 100
typedef int ElemType;

// 顺序存储二叉树结构体定义
typedef ElemType SqBiTree[MaxSize];

// 下标分别为i和j的两个结点的公共祖先结点的值
ElemType Comm_Ancestor(SqBiTree T,int i,int j){
    // 先判断两结点是否存在
    if(T[i]!='#'&&T[j]!='#'){
        // i==j时找到公共祖先结点，结束循环
        while(i!=j){
            if(i>j){
                // 向上找T[i]的祖先结点
                i=i/2;
            }
            // i<j时
            else{
                // 向上找T[j]的祖先结点
                j=j/2;
            }
        }
        return T[i];
    }
}