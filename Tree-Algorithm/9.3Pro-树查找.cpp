#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
/*
	完全二叉树的静态表示法，已知深度求解查找一个深度内的全部结点
*/
const int maxn = 50;

int tree[maxn];

int main(int argc, char *argv[]) {
	int n, d;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tree[i]);
		}	
		scanf("%d", &d); //深度
		if (d > n) {
			printf("EMPTY\n");
		} else{
			int numNode = pow(2.0, d-1); //该深度层数有多少个结点，同时也是该层数第一个结点的下标
			int x = numNode;
			for (int i = 0; i < numNode; i++) {
				if (i == numNode - 1) { //当最后一个结点的时候，最后字符没有空格
					printf("%d", x);
				} else {
					printf("%d ", x);
					x = x + 1;
				}
			}
			printf("\n");
		}
		
	}
}