#include <iostream>
using namespace std;

//静态分配
#define maxSize 10

typedef struct {
	int data[maxSize];//这里是int，也可以是char，struct等等数据类型
	int len;
} SqList;

// 初始化函数
void InitList(SqList &L) {
	for (int i = 0; i < maxSize; i++) {
		L.data[i] = 0;//将所有元素设置为默认初始值,不初始化会有内存中遗留的脏数据
	}
	L.len = 0;//顺序表初始长度为0
}

// 主函数
int main() {
	SqList L;//申明一个顺序表
	InitList(L);//初始化顺序表
	/*main函数的L需要传入InitList函数初始化，
	再回到main函数，
	所以这里应传入地址,
	即InitList括号里的参数为&L*/
	return 0;
}
