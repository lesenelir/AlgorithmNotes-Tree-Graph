#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
/*
	由二叉树的后序和中序序列求出二叉树的层次序列
	9.2重点、知识点：由已知的两个序列或者包括完整的一个序列创建一棵二叉树
*/
const int maxn = 50;

typedef struct BTNode{
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

int pre[maxn], in[maxn], post[maxn];
int n; //结点数

BTNode* Create(int postL, int postR, int inL, int inR) { //建立二叉树
	if (postL > postR) { //后序长度小于等于0则直接返回
		return NULL;
	}
	BTNode* root = new BTNode; //新建一个结点用来存放根结点
	root->data = post[postR];
	int k;
	for (k = inL; k <= inR; k++) {
		if (in[k] == post[postR]) {//后序序列的最后一个结点将中序序列分成两部分
			break;
		}
	}
	int numLeft = k - inL; //左子树结点个数
	//返回左子树的根结点地址，赋值给root的左指针
	root->lchild = Create(postL, postL + numLeft - 1, inL, k - 1);
	//返回右子树的根结点地址，赋值给root的右指针
	root->rchild = Create(postL + numLeft, postR - 1, k + 1, inR);
	return root;
}

//层次遍历
int num = 0;
void BFS(BTNode* root) {
	queue<BTNode*> q;
	q.push(root);
	while (!q.empty()) {
		BTNode* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n) printf(" ");
		if (now->lchild != NULL) q.push(now->lchild);
		if (now->rchild != NULL) q.push(now->rchild);
	}
}

int main(int argc, char *argv[]) {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &post[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &in[i]);
		}
		BTNode* root = Create(0, n-1, 0, n-1);
		BFS(root);
		printf("\n");
	}
}