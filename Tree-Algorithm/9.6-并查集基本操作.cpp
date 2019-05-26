#include <iostream>
#include <cstdio>
using namespace std;
/*
	并查集的合并查找操作。用一位数组来表示并查集，father[]，father[x] == x 表示x是根结点
*/
const int maxn = 100;

int father[maxn];

//路径压缩并查集的查找操作
int findFather(int x) {
	if (x == father[x]) return x; //要找元素就是根结点直接返回
	else {
		int F = findFather(father[x]); //要找元素不是根结点递归寻找这个结点的父结点，F为集合的根结点
		father[x] = F; //路径上的所有结点的父结点都指为根结点
		return F;
	}
}

//合并a元素所在的集合和b元素所在的集合
void Union(int a, int b) {
	int faA = findFather(a); //找根结点
	int faB = findFather(b);
	if (faA != faB) { //不属于同一个集合
		father[faA] = faB; //合并，a元素所在集合并入b元素所在集合根结点的直链下
	}
}

//初始化并查集，即每一个元素都是根结点，有n个集合
void init(int n) {
	for (int i = 0; i < n; i++) {
		father[i] = i;
	}
}


int main(int argc, char *argv[]) {
	
}