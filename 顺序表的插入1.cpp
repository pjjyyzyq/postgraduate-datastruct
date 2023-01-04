#include <iostream>
using namespace std;

#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int len;
} SqList;

void InitList(SqList &L) {
	for (int i = 0; i < MaxSize; i++) {
		L.data[i] = 0;
	}
	L.len = 0;
}

bool ListInsert(SqList &L, int i, int e) {
	if (i < 1 || i > L.len + 1) {
		return false;
	}
	if (L.len >= MaxSize) {
		return false;
	}
	for (int j = L.len; j >= i; j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.len++;
	return true;
}

int main() {
	SqList L;
	InitList(L);
	for (int i = 0; i < 5; i++) {
		L.data[i] = i + 1;
		L.len++;
		cout << L.data[i];
	}
	cout << endl;
	ListInsert(L, 3, 0);
	for (int i = 0; i < L.len; i++) {
		cout << L.data[i];
	}
	return 0;
}