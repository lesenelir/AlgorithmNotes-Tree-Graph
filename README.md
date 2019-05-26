# AlgorithmNotes-Tree-Graph

## 一、树

### 1.1 树与二叉树：

* 二叉树的链式存储结构，完全二叉树的静态存储结构
* 二叉树的创建、插入、查找、修改、删除

### 1.2 二叉树的遍历：

* 前序遍历、中序遍历、后序遍历递归代码的编写
* 层次遍历的队列代码的编写
* 主要掌握已知序列创建二叉树函数的编写。包括中序遍历和前序、后序的结合，生成一个新二叉树，然后再求任何一个其他的序列。

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
