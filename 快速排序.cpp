#include<iostream>
using namespace std;

// 划分函数，用数组A[]第一个元素将待排序序列A[]划分成左右两个部分
int Partition(int A[], int low, int high){
    // 第一个元素作为枢轴
    int pivot=A[low];
    while(low<high){
        //当前high指针指向的元素>=枢轴，high指针不断左移，直到找到第一个<枢轴的元素跳出循环
        while(low<high&&A[high]>=pivot)
            high--;
        // 第一个<数轴的元素放到low指针所指位置，切换到low指针移动
        A[low]=A[high];
        // 当前low指针指向的元素<=枢轴，low指针不断右移，直到找到第一个>枢轴的元素跳出循环
        while(low<high&&A[low]<=pivot)
            low++;
        // 第一个>枢轴的元素放到high指针所指位置，切换到high指针移动
        A[high]=A[low];
    }
    // 将枢轴元素放到最终位置
    A[low]=pivot;
    // 返回存放枢轴的位置
    return low;
}

// 快速排序，传入待排序数组A[]，待排序序列区间范围[low, high]
void QuickSort(int A[], int low, int high){
    // 递归出口
    if(low<high){
        int pivotpos=Partition(A, low, high);
        // 划分左子表
        QuickSort(A, low, pivotpos-1);
        // 划分右子表
        QuickSort(A, pivotpos+1, high);
    }
}