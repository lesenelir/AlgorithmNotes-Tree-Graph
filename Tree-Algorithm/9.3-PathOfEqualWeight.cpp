#include <iostream>
#include <vector>
using namespace std;
/*
	PAT A1053 Path of Equal Weight
	DFS树的遍历
*/
const int maxn = 100;

struct BTNode{
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a, int b) {
	return Node[a].weight > Node[b].weight;
}

int n, m, S;
int path[maxn];

void DFS(int index, int numNode, int sum) { //下标，path路径结点数，path路径权重值
	if (sum > S) return ;
	if (sum == S) {
		if (Node[index].child.size() != 0) return; //非叶子结点返回
		for (int i = 0; i < numNode; i++) {
			printf("%d", Node[path[i]].weight); //输出当前路径上每一个结点的权重
			if (i < numNode - 1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for (int i = 0; i < Node[index].child.size(); i++) { //递归边界枚举所有子结点
		int child = Node[index].child[i];
		path[numNode] = child;
		DFS(child, numNode + 1, sum + Node[child].weight); //递归调用
	}
}

int main(int argc, char *argv[]) {
	while (scanf("%d %d %d", &n, &m, &S) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &Node[i].weight);
		}
		int id, k, child; 
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &id, &k); //结点编号，孩子个数
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				Node[id].child.push_back(child); //child为k的孩子结点
			}
			sort(Node[i].child.begin(), Node[i].child.end(), cmp);
		}
		path[0] = 0;
		DFS(0, 1, Node[0].weight);
	}	
}