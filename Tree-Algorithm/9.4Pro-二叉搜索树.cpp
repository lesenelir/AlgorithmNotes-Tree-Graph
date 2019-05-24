#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
/*
	比较二叉树的序列问题类似于PAT A1043
*/
typedef struct BTNode{
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

void insert(BTNode* &root, int x) {
	if (root == NULL) {
		root = new BTNode;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (x < root->data) insert(root->lchild, x);
	else insert(root->rchild, x);
}

BTNode* create(char data[], int n) {
	BTNode* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i] - '0');
	}
	return root;
}

void preOrder(BTNode* root, vector<int> &vi) {
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}

void inOrder(BTNode* root, vector<int> &vi) {
	if (root == NULL) return;
	inOrder(root->lchild, vi);
	vi.push_back(root->data);
	inOrder(root->rchild, vi);
}

void postOrder(BTNode* root, vector<int> &vi) {
	if (root == NULL) return;
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}

vector<int> originpre, originin, originpost, nowpre, nowin, nowpost;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		char tree_old[100];
		scanf("%s", tree_old);
		int len = strlen(tree_old);
		BTNode* root = create(tree_old, len);
		preOrder(root, originpre);
		inOrder(root, originin);
		postOrder(root, originpost);
		//以上是对特定序列的求前中后序列操作，以下是进行对重组序列操作
		for (int i = 0; i < n; i++) {
			char tree_new[100];
			scanf("%s", tree_new);
			int len2 = strlen(tree_new);
			BTNode* root2 = create(tree_new, len2);
			preOrder(root2, nowpre);
			inOrder(root2, nowin);
			postOrder(root2, nowpost);
			if (originpre == nowpre && originin == nowin && originpost == nowpost) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
			nowpre.clear(); //clear()清空动态数组内所有的元素值
			nowin.clear();  //不清空下一次进行比较时动态数组永远存储的是上一次的记录，
			nowpost.clear();//即使到正确的序列的时候，也会报错。
		}
		originpre.clear();
		originin.clear();
		originpost.clear();
	}
}