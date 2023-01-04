#include<iostream>
using namespace std;

// swap函数实现交换a，b的值
void swap(int &a, int &b){
    // 每调用1次swap函数，移动3次元素
    int temp=a;
    a=b;
    b=temp;
}

// 简单选择排序，将传入的A[]重新排列为升序序列
void SelectSort(int A[], int n){
    int i,j;
    // 长度为n的序列选择排序进行n-1趟
    for(i=0;i<n-1;i++){
        // min记录最小元素的位置
        int min=i;
        // 在A[i,n-1]中找到最小元素，用min记录最小元素的位置
        for(j=i+1;j<n;j++){
            if(A[j]<A[min])
                min=j;
        }
        // 若当前i的位置的元素不是A[i, n-1]中最小的，即min!=i则交换A[i]和A[min]
        if(min!=i)
            swap(A[i], A[min]);
    }
}
