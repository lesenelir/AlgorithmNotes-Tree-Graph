#include <iostream>
#include <cstdio>
using namespace std;
/*
	已知先序序列字符串，"#"表示空树，创建二叉树，并完成中序遍历。
*/
const int maxn = 100;

typedef struct BTNode{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

int cnt;
char pre[maxn]; //保存先序序列

BTNode* create() {
	BTNode* root = NULL;
	if (pre[cnt] == '#') {
		root = NULL;
		cnt++;
	} else {
		root = new BTNode;
		root->data = pre[cnt];
		cnt++; //下一个结点
		//返回左子树根结点的地址，root左结点赋值
		root->lchild = create();
		//返回右子树根结点的地址，root右结点赋值
		root->rchild = create();
	}
	return root;
}

//中序遍历
void inorder(BTNode* root) {
	if (root == NULL) return;
	inorder(root->lchild);
	printf("%c ", root->data);
	inorder(root->rchild);
}

int main(int argc, char *argv[]) {
	while (scanf("%s", pre) != EOF) {
		cnt = 0; //从数组的第一个位置开始
		BTNode* root = create();
		inorder(root);
		printf("\n");
	}
}