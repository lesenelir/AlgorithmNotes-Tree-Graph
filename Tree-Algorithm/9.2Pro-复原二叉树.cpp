#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
/*
	由二叉树的前序和中序序列求出后序序列
	输入两组字符串，并且每一组的字符串的字母都不唯一
	存储字符串用string类型来存储
*/
typedef struct BTNode{
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

string pre, in, post;
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

int main(){
	while(cin >> pre >> in){ //string类型只能是cin输入
		BTNode* root = create(0, pre.length()-1 , 0, in.length() - 1);
		postorder(root);
		printf("\n");
	}
	return 0;
}