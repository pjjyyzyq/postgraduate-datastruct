#include<iostream>
using namespace std;

// 不带哨兵直接插入排序，待排序表从下标0开始存
// 函数功能为实现递增排序，函数参数为待排序表A[]，表长n
void InsertSort_1(int A[], int n){
    // i用来遍历待排序表A[]的元素
    //j用来遍历下标为i的元素前面的表元素
    //temp作为中间变量存储逆序元素
    int i,j,temp;
    for(i=1;i<n;i++){
        //先找逆序元素
        if(A[i]<A[i-1]){
            //找到逆序元素后用temp保存，防止移动元素时将A[i]原来值覆盖
            temp=A[i];
            //用循环把>temp的元素后移
            for(j=i-1;j>=0&&A[j]>temp;j--)
                A[j+1]=A[j];
            //上面循环结束A[j]是<=temp的第一个元素，其中=是为了保证算法的稳定性
            A[j+1]=temp;
        }
    }
}

// 带哨兵的直接插入排序，待排序表从下标1开始存
void InsertSort_2(int A[], int n){
    int i,j;
    for(i=2;i<n;i++){
        if(A[i]<A[i-1]){
            //用A[0]来代替temp
            A[0]=A[i];
            //下面循环不用j>=0，因为j=0时A[j]>A[0]条件不满足会直接跳出循环
            for(j=i-1;A[j]>A[0];j--)
                A[j+1]=A[j];
            A[j+1]=A[0];
        }
    }
}
    
// 带哨兵的折半插入排序
void InsertSort_3(int A[],int n){
    int i,j,low,high,mid;
    for(i=2;i<n;i++){
        A[0]=A[i];
        // 无需判断逆序
        low=1,high=i-1;
        while(low<=high){
            mid=(low+high)/2;
            // A[mid]==A[0]时,为保持算法的稳定性,应继续在mid右边寻找插入位置
            if(A[mid]>A[0])
                high=mid-1;
            else
                low=mid+1;
        }
        // 此时low=high+1
        // 将[low, i-1]即[high+1, i-1]内的元素全部右移
        for(j=i-1;j>=high+1;i--){
            A[j+1]=A[j];
        }
        // A[0]复制到low所指位置即high+1
        A[high+1]=A[0];
    }
}
