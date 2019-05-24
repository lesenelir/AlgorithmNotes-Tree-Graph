#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
/*
	PAT A1043 It is a Binary Search Tree
	二叉查找树，及其镜像树
	知识点：此题多用来比较两个二叉树序列是否是相一致的，则用动态数组可以直接比较大小，比较前后序列关系。
*/
typedef struct BTNode {
	int data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

void insert(BTNode* &root, int x) {
	if (root == NULL) { //空结点就是需要插入的位置
		root = new BTNode;
		root->data = x;
		root->lchild = root->rchild = NULL;
		return;
	} else if (x < root->data) {
		insert(root->lchild, x);
	} else {
		insert(root->rchild, x);
	}
}

//先序遍历结果保存在动态数组vi中，vi的值需要变化，所以要用引用类型
void preOrder(BTNode* root, vector<int> &vi) {
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild, vi);
	preOrder(root->rchild, vi);
}

//镜像先序遍历结果保存在动态数组vi中
void preOrderMirror(BTNode* root, vector<int> &vi) {
	if (root == NULL) return;
	vi.push_back(root->data);
	preOrder(root->rchild, vi); //镜像的先序只需要把原先的左右顺序调换即可
	preOrder(root->lchild, vi);
}

//后序遍历结果保存在动态数组vi中
void postOrder(BTNode* root, vector<int> &vi) {
	if (root == NULL) return;
	postOrder(root->lchild, vi);
	postOrder(root->rchild, vi);
	vi.push_back(root->data);
}

//镜像后续遍历结果保存在动态数字vi中
void postOrderMirror(BTNode* root, vector<int> &vi) {
	if (root == NULL) return;
	postOrderMirror(root->rchild, vi);
	postOrderMirror(root->lchild, vi);
	vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM; //origin保存初始序列

int main(int argc, char *argv[]) {
	int n, data;
	while (scanf("%d", &n) != EOF) {
		BTNode* root = NULL;
		for (int i = 0; i < n; i++) {
			scanf("%d", &data);
			origin.push_back(data);
			insert(root, data);
		}	
		preOrder(root, pre);
		preOrderMirror(root, preM);
		postOrder(root, post);
		postOrderMirror(root, postM);
		if (origin == pre) {
			printf("YES\n");
			for (int i = 0; i < post.size(); i++) {
				printf("%d", post[i]);
				if (i < post.size() - 1) printf(" ");
			}
			printf("\n");
		} else if (origin == preM) {
			printf("YES\n");
			for (int i = 0; i < postM.size(); i++) {
				printf("%d", postM[i]);
				if (i < postM.size() - 1) printf(" ");
			}
			printf("\n");
		} else {
			printf("NO\n");
		}
	}
	
}