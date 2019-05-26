#include <iostream>
#include <cstdio>
using namespace std;
/*
	经典并查集题，求还需多少条线使得组合都相连，即组数-1.
	关键在于求出并查集，集合的数量问题。
	此处给了另一种求解集合数量的问题，不需要用到isRoot[]数组
*/
const int maxn = 100;

int father[maxn];

void init(int n) {
	for (int i = 0; i < n; i++) {
		father[i] = i;
	}
}

int findFather(int x) {
	if (x == father[x]) return x;
	else {
		int F = findFather(father[x]);
		father[x] = F;
		return F;
	}
}

void Union(int a, int b) {
	int faA = findFather(a);
	int faB = findFather(b);
	if (faA != faB) {
		father[faA] = faB;
	}
}

int main(int argc, char *argv[]) {
	int n, m, a, b;
	while (scanf("%d %d", &n, &m) != EOF) {
		init(n);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			Union(a, b); //合并a和b所在的集合
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (father[i] == i) ans++;
		}
		printf("%d\n", ans-1); //求集合数量直接输出ans
	}
}