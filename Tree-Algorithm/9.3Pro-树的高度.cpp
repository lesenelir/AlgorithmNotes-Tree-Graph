#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/*
	查找树的层数问题，BFS查找树的layer
*/
const int maxn = 50;

struct node{
	int data;
	int layer;
	vector<int> child;
}Node[maxn];

//BFS搜索树的层次遍历
int high; //求解值
void BFS_LayerOrder(int root) {
	high = 0;
	queue<int> Q;
	Q.push(root);
	Node[root].layer = 1; //根结点的层数算作为1
	while (!Q.empty()) {
		int front = Q.front();
		if (Node[front].layer > high) high = Node[front].layer; //关键步骤
		Q.pop();
		for (int i = 0; i < Node[front].child.size(); i++) {
			int child = Node[front].child[i]; //当前结点的第i个子结点编号
			Node[child].layer = Node[front].layer + 1; //子结点层号是当前结点层号加一
			Q.push(child);
		}
	}
}

int main(int argc, char *argv[]) {
	int n, a, b;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n-1; i++) {
			scanf("%d %d", &a, &b);
			Node[a].child.push_back(b); //b当作a的子结点
		}
		BFS_LayerOrder(1);
		printf("%d\n", high);
	}
}