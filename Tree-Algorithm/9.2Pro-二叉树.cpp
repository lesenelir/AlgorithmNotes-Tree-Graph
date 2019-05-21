#include <iostream>
#include <cstdio>
using namespace std;
/*
	求某一结点的所有子树的结点可以用广度优先遍历的方法求解
	一般的，需要使用深搜都用广度优先遍历的方法求解
	每一次搜索，就记录一次，即sum++
	sum为全局变量
*/
int n, m, sum;

void BFS(int root) {
	if (root > n) return;
	sum++;
	BFS(2*root); //遍历左子树
	BFS(2*root + 1); //遍历右子树
}

int main(int argc, char *argv[]) {
	while (scanf("%d %d", &m, &n) != EOF) {
		if (n == 0 && m ==0 ) break;
		sum = 0;
		BFS(m);
		printf("%d\n", sum);
	}	
}