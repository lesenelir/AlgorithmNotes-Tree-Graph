#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
/*
	树的静态写法，树的先序遍历和层次遍历
*/
const int maxn = 50;

struct BTNode{
	int data;
	int layer; //层次遍历记录层号
	//int child[maxn];	
	vector<int> child;
}Node[maxn];

//树的先序遍历
void PreOrder(int root) {
	printf("%d ", Node[root].data);
	for (int i = 0; i < Node[root].child.size(); i++) {
		PreOrder(Node[root].child[i]);
	}
}

//树的层次遍历
void LayerOrder(int root) {
	queue<int> Q;
	Q.push(root);
	Node[root].layer = 0;
	while (!Q.empty()) {
		int front = Q.front();
		printf("%d ", Node[front].data);
		Q.pop();
		for (int i = 0; i < Node[front].child.size(); i++) {
			int child = Node[front].child[i]; //当前结点第i个子结点的编号
			Node[child].layer = Node[front].layer + 1; //子结点层号是当前结点层号加1
			Q.push(child);
		}
		
	}
}


int main(int argc, char *argv[]) {
	
}