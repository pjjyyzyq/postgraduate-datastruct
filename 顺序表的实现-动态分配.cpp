#include <iostream>
using namespace std;

//动态分配
#define InitSize 10

typedef struct {
	int *data;//指向一块动态分配内存的首地址
	int MaxSize;
	int len;
} SeqList;

// 初始化函数
void InitList(SeqList &L) {
	L.data = (int *)malloc(InitSize * sizeof(int)); //这里不是sizeof(L)
	L.len = 0;
	L.MaxSize = InitSize;
}

// 增加动态数组长度函数
void IncreaseSize(SeqList &L, int n) {
	int *p = L.data;
	L.data = (int *)malloc((L.MaxSize + n) * sizeof(int));
	for (int i = 0; i < L.len; i++) {
		L.data[i] = p[i];//将数据复制到新的内存区域
	}
	L.MaxSize = L.MaxSize + n;
	free(p);//释放原来数组所占的内存空间
}

// 主函数
int main() {
	SeqList L;//申明一个顺序表
	InitList(L);//初始化顺序表
	cout << L.MaxSize << endl;
	cout << sizeof(L) / sizeof(int) << endl;
	IncreaseSize(L, 5);
	cout << L.MaxSize << endl;
	cout << sizeof(L) / sizeof(int) << endl;
	return 0;
}