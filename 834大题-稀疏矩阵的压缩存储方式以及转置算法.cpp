#include<iostream>
#include<string.h>
using namespace std;

// 三元组数组的最大长度=三元组最大个数=稀疏矩阵非零元素的最大数目
#define MaxSize 100
#define ColMaxSize 20
// 三元组(<行，列，值>)结构体定义
typedef struct{
    // 行号i，列号j，且均从1开始
    int i,j;
    // 值value
    int value;
}Triple;

// 稀疏矩阵结构体定义
typedef struct{
    // 采用三元组数组存储一般矩阵，从数组下标1开始存
    Triple data[MaxSize+1];
    // 稀疏矩阵行数m，列数n，非零元素个数count
    int m,n,count
}SparseMatrix;

// 将矩阵M转置后得到矩阵T，对应的三元组数组保证行优先(行号i小的排在前面)

// 稀疏矩阵普通转置算法(三元组)，时间复杂度O(n*count)=O(m*n^2)
void TrannsposeMatrix(SparseMatrix M,SparseMatrix T){
    // 转置后行列互换
    T.m=M.n;
    T.n=M.m;
    // 非零元素个数不变
    T.count=M.count;
    // K指向在转置矩阵T对应的三元组数组中下一次插入三元组元素结点的数组下标位置,初始值设为1
    int k=1;
    // 遍历矩阵M对应的三元组数组
    // 因为要保证转置矩阵行号小三元组元素结点的排在三元组数组的前面，所以外层循环对应原矩阵进行列遍历
    for(int col=1;col<=M.n;M.n++){
        // 内层循环对原矩阵对应的三元组数组进行逐个遍历
        for(int p=1,p<=M.count;p++){
            // 当前遍历的三元组元素结点的列号满足要求
            if(M.data[p].j==col){
                // 将当前的三元组元素结点复制到转置矩阵T对应的三元组数组
                T.data[k].i=M.data[p].j;
                T.data[k].j=M.data[p].i;
                T.data[k].value=M.data[p].value;
                // k指向下一个插入位置
                k++;
            }
        }
    }
    
}


// 稀疏矩阵快速转置算法(三元组)，是对上面普通转置算法的优化，采用空间换时间的算法思想，时间复杂度仅为O(m*n)
void FastTransposeMatrix(SparseMatrix M,SparseMatrix T){
    // 转置后行列互换
    T.m=M.n;
    T.n=M.m;
    // 非零元素个数不变
    T.count=M.count;
    // 设置cNum数组，记录矩阵M每一列中非零元素个数
    int cNum[ColMaxSize+1];
    // 初始化数组
    memset(cNum,0,M.n+1);
    // 构造cNum数组
    for(int p=1;p<=M.count;p++){
        int j=M.data[p].j;
        cNum[j]++;
    }
    // 设置cPot数组，纪录矩阵M每列第一个非零元素在新三元组表中存放的位置
    int cPot[ColMaxSize+1];
    // 初始化cPot数组
    memset(cPot,0,M.n+1);
    // 构造cPot数组
    cPot[1]=1;
    for(int col=2;col<=M.n;col++){
        cPot[col]=cPot[col-1]+cNum[col-1]
    }
    // 计算三元组的最终位置
    for(int p=1;p<=M.count;p++){
        // 提取当前三元组的列数col
        int col=M.data[p].j;
        // 根据列数和cPot数组找到当前三元组要存放新的位置q
        int q=cPot[col];
        T.data[q].i=M.data[p].j;
        T.data[q].j=M.data[p].i;
        T.data[q].value=M.data[p].value;
        // 存储该列第一个非零元素后，该列对应的cPot数组的值加一，以便存储该列下一个非零元素
        cPot[col]++;
    }
}



