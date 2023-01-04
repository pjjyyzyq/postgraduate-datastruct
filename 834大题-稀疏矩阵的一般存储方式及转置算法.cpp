#include<iostream>
using namespace std;

// 矩阵最大行列数
#define MaxSize 100

// 稀疏矩阵结构体定义
typedef struct{
    // 采用二维数组存储一般矩阵，从数组下标1开始存
    int data[MaxSize+1][MaxSize+1];
    // 行数m，列数n
    int m,n;
}sparseMatrix;

// 普通转置算法(二维数组)，时间复杂度O(m*n)
void transposeMatrix(sparseMatrix M,sparseMatrix T){
    for(int col=1;col<=n;col++){
        for(int row=1;row<=m;row++){
            T.data[col][row]=M.data[row][col];
        }
    }
}