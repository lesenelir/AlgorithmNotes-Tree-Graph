#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
/*
	判断图是否为连通图这种题目一般都是用BFS来判断
	从一个结点开始搜索，若未访问到所有结点则不是连通图
	关于图的遍历需要注意的一点：如果顶点编号从1开始编号就要从1开始循环而不是从0开始循环
*/
const int maxn = 100;

vector<int> Adj[maxn];
bool inq[maxn] = {false};

//遍历单个u所在的连接块
void BFS(int u) {
	queue<int> q;
	q.push(u);
	inq[u] = true;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < Adj[u].size(); i++) { //枚举u所能到达的所有顶点
			int v = Adj[u][i];
			if (inq[v] == false) {
				q.push(v);
				inq[v] = true;
			}
		}
	}
}


int main(int argc, char *argv[]) {
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0) break;
		for (int i = 1; i <= n; i++) { //顶点编号从1开始计算
			Adj[i].clear(); //每次都要清空vector容器
			memset(inq, false, sizeof(inq));
		}
		int x, y;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			Adj[x].push_back(y);
			Adj[y].push_back(x);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (inq[i] == false) {
				BFS(i);
				ans++;
			}
		}
		if (ans == 1) printf("YES\n");
		else printf("NO\n");
	}
}