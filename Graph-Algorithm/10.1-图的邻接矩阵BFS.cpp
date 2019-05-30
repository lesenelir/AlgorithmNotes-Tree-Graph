#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
	BFS图的广度遍历邻接矩阵表示法
*/
const int maxn = 100;
const int INF = 1000000;

int n, G[maxn][maxn];
bool inq[maxn] = {false};

//遍历U所在的连通块
void BFS(int u) {
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < n; i++) { //遍历关于u的所有连通块
			if (inq[i] == false && G[u][i] != INF) {
				q.push(i); 
				inq[i] = true; 
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