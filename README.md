# AlgorithmNotes-Tree-Graph

## 一、树

### 1.1 树与二叉树：

* 二叉树的链式存储结构，完全二叉树的静态存储结构
* 二叉树的创建、插入、查找、修改、删除

### 1.2 二叉树的遍历：

* 前序遍历、中序遍历、后序遍历递归代码的编写
* 层次遍历的队列代码的编写
* 主要掌握已知序列创建二叉树函数的编写。包括中序遍历和前序、后序的结合，生成一个新二叉树，然后再求任何一个其他的序列

### 1.3 树的遍历：
* 树的静态写法
* 树的先根遍历 = 二叉树的先序遍历；树的层次遍历 = 二叉树的层次遍历
* DFS 和 BFS 运用于树的遍历操作

### 1.4 二叉查找树：
* 二叉查找树的建立、插入、查找、删除操作
* 二叉查找树的镜像树，即左右子树互换，并与原先的二叉查找树序列进行比较
* 比较两个二叉树序列是否一致时，建议用动态数组直接比较前后序列
> void preOrder(BTNode* root, vector<int> &vi) //先序遍历结果保存在动态数组vi中，vi的变化用引用类型  
  
### 1.5 平衡二叉树：
* 平衡二叉树的建树、查找、插入操作。
* 插入操作有四种类型
> LL 对root进行右旋

> LR 先对root->lchild进行左旋，再对root进行右旋

> RR 对root进行左旋

> RL 先对root->rchild进行右旋，再对root进行左旋

### 1.6 并查集
* 以一位数组来定义并查集,father[i]表示i的父结点
* 并查集需要牢记三个模块函数：初始化、合并、查询（路径压缩查询）
* 并查集的题目最后的输出有两个方向：求集合的数量问题、求集合内元素个数问题

### 1.7 堆
* 堆是一棵完全二叉树，一般用于优先队列实现。通常有两种堆，大顶堆和小顶堆
* 堆无法比较隶属于同一个父亲结点的孩子结点之间的大小值，故对堆进行层次遍历不是一个有序的序列
* 堆的操作有两个主要步骤：向下调整和向上调整；调整某个结点是从上往下进行调整，寻找结点是从下往上进行寻找

### 1.8 哈夫曼树
* 哈夫曼树通常都是用优先队列最小值来完成，优先队列默认是从大到小
* 哈夫曼树的题目主要是进行带权路径长度的求解问题
* 带权路径长度 = （叶子结点*路径长度）总和 = 非叶子结点总和

## 二、图








