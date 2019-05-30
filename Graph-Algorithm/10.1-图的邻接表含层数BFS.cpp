#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
	BFS图的广度遍历邻接表需要计算层数
*/
const int maxn = 100;
const int INF = 1000000;

struct Node{
	int v; //顶点编号
	int layer; //顶点层号
};

vector<Node> Adj[maxn];
bool inq[maxn] = {false};

//广度遍历
void BFS(int s) { //s是起始顶点
	queue<Node> q;
	Node strat; //起始顶点
	start.v = s; 
	start.layer = 0;
	q.push(start);
	inq[start.v] = true;
	while (!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.v;
		for (int i = 0; i < Adj[u].size(); i++) {
			Node next = Adj[u][i]; //从u出发能到达的顶点next
			next.layer = topNode.layer + 1;
			//如果next编号未被加入过队列
			if (inq[next.v] == false) {
				q.push(next);
				inq[next.v] = true;
			}
		}
	}
}




int main(int argc, char *argv[]) {
	
}