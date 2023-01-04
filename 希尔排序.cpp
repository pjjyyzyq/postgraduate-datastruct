#include<iostream>
using namespace std;

// 希尔排序，从1开始存
void ShellSort(int A[], int n){
    // 每趟的增量为d
    int d,i,j;
    for(d=n/2;d>=1;d=d/2){
        for(i=d+1;i<=n;i++){
            if(A[i]<A[i-d]){
                //A[0]暂存逆序元素
                A[0]=A[i];
                //把>A[0]的元素后移
                for(j=i-d;j>0&&A[j]>A[0];j-=d){
                    A[j+d]=A[j];
                }
                A[j+d]=A[0];
            }
        }
    }
}