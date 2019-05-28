#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
/*
	PAT A1034 图的深度遍历的一道题
*/
const int maxn = 2019;
const int INF = 100000;

map<int, string> intToString; //编号->姓名
map<string, int> stringToInt; //姓名->编号
map<string, int> Gang;        //head->人数

int G[maxn][maxn] = {0}, weight[maxn] = {0};
int n, k, numPerson = 0; //边数，下限， 总人数
bool Visit[maxn] = {false};

//DFS访问单个连通块，nowVisit为当前访问结点, head为头目，numMember是成员编号，totalValue为连通块总边权
void DFS(int nowVisit, int &head, int &numMember, int &totalValue) {
	numMember++;
	Visit[nowVisit] = true;
	if (weight[nowVisit] > weight[head]) {
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++) {
		if (G[nowVisit][i] > 0) {
			totalValue += G[nowVisit][i];
			G[nowVisit][i] = G[i][nowVisit] = 0; //删除这条边，防止回头
			if (Visit[i] == false) {
				DFS(i, head, numMember, totalValue);
			}
		}
	}
	
}

//遍历整个图
void DFSTrave() {
	for (int i = 0; i < numPerson; i++) {
		if (Visit[i] == false) {
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue); //遍历连通块
			if (numMember > 2 && totalValue > k) { //犯罪条件，成员数>2，总边权>K
				Gang[intToString[head]] = numMember;
			}
		}
	}
}

//返回姓名str对应的编号
int change(string str) {
	if (stringToInt.find(str) != stringToInt.end()) { //str出现过返回编号
		return stringToInt[str];
	} else {
		stringToInt[str] = numPerson; //str编号为numPerson
		intToString[numPerson] = str; //numPerson对应str
		return numPerson++;
	}
}

int main(int argc, char *argv[]) {
	int w;
	string str1, str2;
	while (scanf("%d %d", &n, &k) != EOF) {
		for (int i = 0; i < n; i++) {
			cin >> str1 >> str2 >> w;
			int id1 = change(str1);
			int id2 = change(str2);
			weight[id1] += w;
			weight[id2] += w;
			G[id1][id2] += w;
			G[id2][id1] += w;
		}
		DFSTrave();
		cout << Gang.size() << endl;
		map<string, int>::iterator it;
		for (it = Gang.begin(); it != Gang.end(); it++) {
			cout << it->first << " " << it->second << endl;
		}
	}	
}