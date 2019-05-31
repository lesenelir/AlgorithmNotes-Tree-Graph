#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/*
	拓扑排序基本操作。拓扑排序必须是有向无环图。
	拓扑排序有一个比较重要的应用就是判断是否为有向无环图，用num计数最后判断是否为n来判断是否为有向无环图
*/
const int maxn = 100;

vector<int> Adj[maxn];
int n, m, inDegree[maxn]; //顶点数，入度

bool topologicalSort() {
	int num = 0; //num用来判断是否是有向无环图
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0) {
			q.push(i); //入度为0的结点入度
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < Adj[u].size(); i++) {
			int v = G[u][i]; //v为U的后继结点
			inDegree[v]--;
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
		Adj[u].clear(); //清空u的所有出边
		num++; //加入拓扑序列的顶点数加一
	}
	if (num == n) return true;
	else return false;
}


int main(int argc, char *argv[]) {
	
}