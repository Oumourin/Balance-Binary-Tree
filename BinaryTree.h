//
// Created by toumakazusa on 19-6-29.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H


struct BinaryTreeNode{
    int data;
    int isBalance;
    BinaryTreeNode *leftChild, *rightChild;
};

// 移动左节点方法
void movingLeftTreeNode(BinaryTreeNode **Tree);

// 移动右节点方法
void movingRightTreeNode(BinaryTreeNode **Tree);

// 平衡左子树
void balanceLeftTree(BinaryTreeNode **Tree);

// 平衡右子树
void balanceRightTree(BinaryTreeNode **Tree);

// 创建一颗新树
BinaryTreeNode *  createNewTree(int insertData);

// 树增长方法
bool insertTreeNode(BinaryTreeNode **Tree, bool *isHigher, int insertData);

// 递归遍历方法
void traversingBinaryTree(BinaryTreeNode *Tree);

#endif //BINARYTREE_BINARYTREE_H
