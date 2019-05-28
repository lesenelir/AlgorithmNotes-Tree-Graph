#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
	哈夫曼树，运用优先队列来完成，优先队列小顶堆，求出带权路径长度
	优先队列最大堆 priority_queue<int, vector<int>, less<int>> q;
	优先队列最小堆 priority_queue<int, vector<int>, greater<int>> q;
	计算带权路径长度只需要计算新生成的非叶子结点的所有结点之和
*/

//优先队列最小堆
priority_queue<int, vector<int>, greater<int>> q;

int main(int argc, char *argv[]) {
	int n;
	while (scanf("%d", &n) != EOF) {
		int temp; //存放权重值
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			q.push(temp);
		}
		int x, y, ans = 0;
		while (q.size() > 1) { //优先队列至少有两个元素
			x = q.top();
			q.pop();
			y = q.top();
			q.pop();
			q.push(x+y); //取出堆顶元素合成一个新的结点
			ans += x + y;
		}
		printf("%d\n",ans);
	}
}