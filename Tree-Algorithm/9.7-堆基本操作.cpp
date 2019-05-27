#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
	堆-完全二叉树
*/
const int maxn = 100;

int heap[maxn];

void downAdjust(int low, int high) {
	int i = low, j = i * 2; //i是要调整结点，j存储某结点孩子结点最大的下表，这里指向左孩子
	while (j <= high) {
		if (j + 1 <= high && heap[j + 1] > heap[j]) {
			j = j + 1; //存储右孩子下标，此时右孩子的结点值大于左孩子
		}
		if (heap[j] > heap[i]) {
			swap(heap[j], heap[i]);
			i = j;
			j = i * 2;
		} else {
			break;
		}
	}
}

void upAdjust(int low, int high) {
	int i = high, j = i / 2;
	while (j >= low) {
		if (heap[j] < heap[i]) {
			swap(heap[j], heap[i]);
			i = j;
			j = i / 2;
		} else {
			break;
		}
	}
}

int main(int argc, char *argv[]) {
	
}