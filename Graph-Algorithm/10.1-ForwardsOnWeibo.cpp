#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
/*
	PAT A1076 图的广度遍历一道题
*/
const int maxn = 100;

struct Node{
	int id;
	int layer;
};

vector<Node> Adj[maxn];
bool inq[maxn] = {false};

int BFS(int s, int L) { //起始结点，层数上限
	int numForward = 0; //转发数
	queue<Node> q;
	Node start;
	start.id = s;
	start.layer = 0;
	q.push(start);
	inq[start.id] = true;
	while (!q.empty()) {
		Node topNode = q.front();
		q.pop();
		int u = topNode.id; //对首结点编号
		for (int i = 0; i < Adj[u].size(); i++) {
			Node next = Adj[u][i]; //从u出发能到达的结点next
			next.layer = topNode.layer + 1;
			//next结点编号没有加入到inq，并且next的层次不超过上限L
			if (inq[next.id] == false && next.layer <= L) {
				q.push(next);
				inq[next.id] = true;
				numForward++;
			}
			
		}
	}
	return numForward;
}

int main(int argc, char *argv[]) {
	Node user;
	int n, L;
	while (scanf("%d %d", &n, &L) != EOF) {
		int numFollow, idFollow;
		for (int i = 1; i <= n; i++) {
			user.id = i; //用户编号i
			scanf("%d", &numFollow); //i号用户关注人数
			for (int j = 0; j < numFollow; j++) {
				scanf("%d", &idFollow);
				Adj[idFollow].push_back(user); //边idFollor->i
			}
		}
		int numQuery, s;
		scanf("%d", &numQuery);
		for (int i = 0; i < numQuery; i++) {
			memset(inq, false, sizeof(inq));
			scanf("%d", &s); //起始结点编号
			int numForward = BFS(s, L); //BFS,返回转发数量
			printf("%d\n", numForward);
		}
	}
}