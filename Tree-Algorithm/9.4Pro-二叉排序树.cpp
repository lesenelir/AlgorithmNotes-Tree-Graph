#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
	建立二叉排序树，并对二叉排序树进行前序、中序、后序排序
*/
typedef struct BTNode{
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

//二叉排序树插入
void insert(BTNode* &root, int x) {
	if (root == NULL) { //空结点就是要插入的结点
		root = new BTNode;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	}
	if (x < root->data) insert(root->lchild, x);
	else insert(root->rchild, x);
}

//二叉排序树的创建，n个结点
BTNode* create(int data[], int n) { 
	BTNode* root = NULL; //根结点
	for (int i = 0; i < n; i++) { 
		insert(root, data[i]); //将data[0]~data[n-1]插入二叉查找树中
	}
	return root;
}

//前序
void preOrder(BTNode* root) {
	if (root == NULL) return; //递归边界
	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

//中序
void inOrder(BTNode* root) {
	if (root == NULL) return;
	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);
}

//后序
void postOrder(BTNode* root) {
	if (root == NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ", root->data);
}

int main(int argc, char *argv[]) {
	int n, tree[100];
	memset(tree, 0, sizeof(tree));
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &tree[i]);
		}
		BTNode* root = create(tree, n);
		preOrder(root);
		printf("\n");
		inOrder(root);
		printf("\n");
		postOrder(root);
		printf("\n");
	}
}