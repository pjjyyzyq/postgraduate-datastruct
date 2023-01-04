#include<iostream>
using namespace std;

// 辅助数组B[]
int *B=(int *)malloc(n*sizeof(int));

// A[low,mid]和A[mid+1,high]有序，将这两个部分归并
void Merge(int A[],int low, int mid, int high){
    int i,j,k;
    for(k=low,k<=high,k++){
        // A所有元素复制到B中
        B[k]=A[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        // =保证算法的稳定性，B[i]更小
        if(B[i]<=B[j])
            A[k]=B[i++];
        // B[i]>B[j]，即B[j]更小
        else
            A[k]=B[j++];
    }
    while(i<=mid) 
        A[k++]=B[i++];
    while(j<=high) 
        A[k++]=B[j++];
}

// 归并排序
void MergeSort(int A[], int low, int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,high);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

