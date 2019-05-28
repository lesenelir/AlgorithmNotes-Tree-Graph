#include <iostream>
#include <cstdio>
using namespace std;
/*
	DFS图的深度遍历邻接矩阵表示
*/
const int maxn = 1000;
const int INF = 100000000;

int n, G[maxn][maxn]; //n为顶点数
bool Visit[maxn] = {false}; //初始化未访问

//访问结点
void DFS(int u, int depth) {
	Visit[u] = true;
	for (int v = 0; v < n; v++) {
		if (Visit[v] == false && G[u][v] != INF) { //v未被访问，且u和v之间可到达
			DFS(v, depth + 1);
		}
	}
}

//遍历图G
void DFSTrave() {
	for (int i = 0; i < n; i++) { //对图的所有顶点
		if (Visit[i] == false) {
			DFS(i, 1); //遍历i和i所在的连通块
		}
	}
}

int main(int argc, char *argv[]) {
	
}