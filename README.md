# Balance-Binary-Tree
实现生成一颗平衡二叉树并实现其中序遍历

----------

##  需求分析

从一颗空树开始创建，在创建过程中，保证树的有序性，同时还要对树平衡性进行调整，最终要创建一颗二叉平衡排序树

##  代码分析

###  二叉树结点结构题

结构体声明：

```c++
struct BinaryTreeNode{
    int data;
    int isBalance;
    BinaryTreeNode *leftChild, *rightChild;
};
```

结构体成员：

data:叶子结点值

isBalance：平衡标志位

*leftChild, *rightChild：左右子树指针

###  生成新的叶子节点方法

函数定义:

```c++
bool insertTreeNode(BinaryTreeNode **Tree, bool *isHigher, int insertData);
```

函数功能：

传递树的根节点指针，要生成的新节点权重，以及树增长标志位，函数会判断是否已经建立树，未创建则新建一个根节点，并返回其指针，已创建的树将会判断是否存在相同叶子节点，若存在则不创建，并返回标志位为false，否则新建立节点，并且和目前根节点进行比较，判断其位于左子树还是右子树，完成创建后，函数将会对新的二叉树平衡性进行检查，若左右子树高度差超过一，此时将会根据叶子结构体中isHigher标志位进行检查，并调用相关调整函数进行树的调整

###  树遍历方法

函数定义：

```c++
void traversingBinaryTree(BinaryTreeNode *Tree);
```

函数功能：

实现对于树的递归遍历，通过控制输出和遍历调用的位置可以实现前序 中序 后序遍历

###  树调整方法

函数定义:

```c++
void balanceLeftTree(BinaryTreeNode **Tree);
void movingRightTreeNode(BinaryTreeNode **Tree);
```

函数功能：

实现检查节点标志位，实现对于不平衡树的调整

###  结点移动方法

函数定义：

```c++
void movingLeftTreeNode(BinaryTreeNode **Tree);
void movingRightTreeNode(BinaryTreeNode **Tree);
```

函数功能：

实现对于节点的交换移动