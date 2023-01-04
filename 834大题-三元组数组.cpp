#include<iostream>
using namespace std;

/*给出两个三元组顺序存储的A,B数组，
要求给定一个值x，
把数组B中比x值大的元素存放到A对应的位置，
请设计对应的算法。
*/

// 三元组<行，列，值>结构体定义
typedef struct{
    // 行号i，列号j，且均从1开始
    int i,j;
    // 值value
    int value;
}triple;

// 函数实现把B中value值大于x的三元组元素结点存放到A对应的位置
// 传入参数为数组A[]，数组B[]，数组B的长度n，给定值x
void solution(triple &A[],triple B[],int n,int x){
    for(int k=0;k<n,k++){
        if(B[k].value>x){
            A[k].i=B[k].i
            A[k].j=B[k].j
            A[k].value=B[k].value
        }
    }
}

