#include <iostream>
#include <cstdio>
using namespace std;
/*
	二叉查找树的相关操作，查找、插入、建树、删除
	二叉查找树是满足二叉树的基础上，左子树的权重小于等于根结点，右子树的权重大于等于根结点
	二叉查找树的重点就是删除操作，例如要删除某结点x并保持二叉查找树的稳定性：
		One:找x的左子树中最大的结点覆盖结点x
		Two:找x的右子树中最小的结点覆盖结点x
*/
typedef struct BTNode{
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

//二叉查找树的查找操作
void search(BTNode* root, int x) {
	if (root == NULL) { //空树，查找失败
		printf("search failed\n");
		return;
	}
	if (x == root->data) {
		printf("%d\n", root->data);
	} else if (x < root->data) { 
		search(root->lchild, x); //x小于某结点值在左子树内查找
	} else {
		search(root->rchild, x); //x大于某结点值在右子树内查找
	}
}

//生成新结点，v为结点的权重
BTNode* newNode(int v) {
	BTNode* Node = new BTNode;
	Node->data = v;
	Node->lchild = Node->rchild = NULL; //易漏
	return Node;
}

//二叉查找树的插入操作
void insert(BTNode* &root, int x) {
	if (root == NULL) {
		root = newNode(x);
		return;
	}
	if (x == root->data) { //二叉查找树中已有结点
		return;
	} else if (x < root->data) {
		insert(root->lchild, x); //x小于某结点值在左子树插入
	} else {
		insert(root->rchild, x); //x大于某结点值在右子树插入
	}
}

//建立n个结点的二叉查找树
void create(int data[], int n) {
	BTNode* root = NULL; //新建根结点
	for (int i = 0;i < n; i++) {
		insert(root, data[i]);
	}
	return root;
}


//寻找以root为根结点的树中最大权值结点，前驱结点
BTNOde* finMax(BTNode* root) {
	while (root->lchild != NULL) {
		root = root->rchild;
	}
	return root;
}

//寻找以root为根结点的树中最小权值结点，后继结点
BTNode* findMin(BTNode* root) {
	while (root->lchild != NULL) {
		root = root->lchild;
	}
	return root;
}

//二叉查找树的删除操作
void deleteNode(BTNode* &root, int x) {
	if (root == NULL) return;
	if (root->data == x) { //找到要删除的结点
		if (root->lchild == NULL && root->rchild == NULL) { //要删除的结点是叶子结点直接删除
			root = NULL;
		} else if (root->lchild != NULL) { //左子树不为空时
			BTNode* pre = findMax(root->lchild); //找root左子树中最大结点
			root->data = pre->data; //数据域覆盖
			deleteNode(root->lchild, pre->data); //递归删除结点
		} else {
			BTNode* next = findMin(root->rchild);
			root->data = next->data;
			deleteNode(root->rchild, next->data);
		}
	} else if ( x < root->data) {
		deleteNode(root->lchild, x);
	} else {
		deleteNode(root->rchild, x);
	}
}

int main(int argc, char *argv[]) {
	
}