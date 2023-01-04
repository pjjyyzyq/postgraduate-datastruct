#include<iostream>
using namespace std;

// swap函数实现交换a，b的值
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

// 冒泡排序,对于A[n],每一趟冒泡把最小的冒到前面,总共n-1趟
void BubbleSort(int A[], int n){
    // 外部循环的一次循环表示执行一趟冒泡，总共执行n-1趟冒泡
    for(int i=0;i<n-1;i++){
        //flag标记是否发生交换
        bool flag=false;
        //内部循环一次循环表示执行一次前后项元素比较，一趟冒泡总共执行n-1-i次比较，
        for(int j=n-1;j>i;j--){
            //逆序则交换
            if(A[j-1]>A[j]){
                swap(A[j-1],A[j]);
                flag=true;
            }
        }
        if(flag==false)
            return;//第一趟遍历没有发现逆序，说明表元素已经有序，直接返回
    }
}

// 每趟冒泡把最大元素冒到最后面
void BubbleSort_1(int A[],int n){
    for(int i=n-1;i>0;i--){
        bool flag=false;
        for(int j=0;j<i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
                flag=true;
            }
        }
        if(flag=false)
            return;
    }
}