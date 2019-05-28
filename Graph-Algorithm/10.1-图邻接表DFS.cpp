#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/*
	DFS图的深度遍历邻接表表示
*/
const int maxn = 1000;

vector<int> Adj[maxn]; //图的邻接表
int n; //n为顶点数
bool Visit[maxn] = {false};

//访问顶点
void DFS(int u, int depth) {
	Visit[u] = true;
	for (int i 0; i < Adj[u].size(); i++) {
		int v = Adj[u][i];
		if (Visit[v] == false) {
			DFS(v, depth + 1);
		}
	}
}

//遍历图
void DFSTrave() {
	for (int i = 0; i < n; i++) {
		if (Visit[i] == false) {
			DFS(i, 1);
		}
	}
}


int main(int argc, char *argv[]) {
	
}