#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
	平衡二叉树的基本操作：查找、插入、建树
	其中插入操作分为四种：LL LR RR RL
*/
typedef struct BTNode{
	int data;
	int height; //height是当前子树高度，平衡二叉树特有
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

//新建结点，v为结点权值
BTNode* newNode(int v) {
	BTNode* Node = new BTNode; //生成一个BTNode型变量的地址空间
	Node->data = v;
	Node->height = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}

//获取root为根结点的子树的当前height
int getHeight(BTNode* root) {
	if (root == NULL) return; //空结点
	return root->height;
}

//计算结点root的平衡因子
int getBalanceFactor(BTNode* root) {
	return getHeight(root->lchild) - getHeight(root->rchild);
}

//更新结点root的height，结点的高度是左右子树较大值加1
void updateHeight(BTNode* root) {
	root->height = max(getHeight(root->lchild) - getHeight(root->rchild)) + 1;
}

//查找操作
void search(BTNode* root, int x) {
	if (root == NULL) {
		printf("faild\n");
		return;
	}
	if (x == root->data) {
		printf("%d\n", root->data);
	} else if (x < root->data) {
		search(root->lchild, x);
	} else {
		search(root->rchild, x);
	}
}

//左旋
void L(BTNode* &root) {
	BTNode* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}

//右旋
void R(BTNode* &root) {
	BTNode* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updataHeight(temp);
	root = temp;
}

//插入权值为x的结点
void insert(BTNode* &root, int x) {
	if (root == NULL) {
		root = newNode(x);
		return;
	}
	if (x < root->data) {
		insert(root->lchild, x);
		updateHeight(root); //更新树高
		if (getBalanceFactor(root) == 2) {
			if (getBalanceFactor(root->lchild) == 1) { //LL型
				R(root);
			} else if (getBalanceFactor(root->rchild) == -1) { //LR型
				L(root->lchild);
				R(root);
			}
		}
	} else {
		insert(root->rchild, x);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			if (getBalanceFactor(root->lchild) == -1) { //RR型
				L(root);
			} else if (getBalanceFactor(root->rchild) == 1) { //RL型
				R(root->rchild);
				L(root);
			}
		}

	}
}

//平衡二叉树的建立，n个结点
BTNode* create(int data[], int n) {
	BTNode* root = NULL;
	for (int i = 0; i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}

int main(int argc, char *argv[]) {
	
}