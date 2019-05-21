#include <iostream>
#include <cstdio>
using namespace std;
/*
	第二种方法用char数组来完成求解
*/
const int maxn = 100;

typedef struct BTNode{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

char pre[maxn], in[maxn], post[maxn];
int n;

BTNode* create(int preL,int preR,int inL,int inR){
	if (preL > preR)	return 	NULL;
	BTNode *root = new BTNode;
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++){
		if(in[k] == pre[preL]){ //后序序列的最后一个结点将中序序列分成两部分
			break;
		}
	}
	int numleft = k - inL; //左子树结点个数
	root->lchild = create(preL + 1, preL + numleft, inL, k - 1);
	root->rchild = create(preL + numleft + 1, preR, k + 1, inR);
	return root;
}

//后序遍历
void postorder(BTNode *root){
	if(root == NULL) return ;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%c",root->data);
}

int main(int argc, char *argv[]) {
	while (scanf("%s %s", pre, in) != EOF) {
		BTNode* root;
		root = create(0, strlen(pre) - 1, 0, strlen(in) - 1);
		postorder(root);
		printf("\n");
	}
}