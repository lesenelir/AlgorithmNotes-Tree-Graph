#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
/*
	BFS图的广度遍历邻接表表示
*/
const int maxn = 100;
const int INF = 1000000;

vector<int> Adj[maxn];
bool inq[maxn] = {false};

//遍历U所在的连通块
void BFS(int u) {
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < Adj[u].size(); i++) { //枚举从u出发能到达的所有结点
			int v = Adj[u][i];
			if (inq[v] == false) {
				q.push(v);
				inq[v] = true;
			}
		}
	}
}

//遍历图G
void BFTrave() {
	for (int u = 0; u < n; u++) {
		if (inq[u] == false) {
			BFS(q);
		}
	}	
}


int main(int argc, char *argv[]) {
	
}