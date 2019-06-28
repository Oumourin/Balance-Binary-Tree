//
// Created by toumakazusa on 19-6-29.
//

#include "BinaryTree.h"

BinaryTreeNode *  createNewTree(int insertData)
{
    BinaryTreeNode *Tree;
    Tree = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    Tree->data = insertData;
    Tree->leftChild= nullptr;
    Tree->rightChild= nullptr;
    Tree->isBalance=0;
    return Tree;
}

void movingLeftTreeNode(BinaryTreeNode **Tree)
{
    BinaryTreeNode * rightTree;
    rightTree=(*Tree)->rightChild;
    (*Tree)->rightChild=rightTree->leftChild;
    rightTree->leftChild=(*Tree);
    (*Tree)=rightTree;
}

void movingRightTreeNode(BinaryTreeNode **Tree)
{
    BinaryTreeNode * leftTree;
    leftTree=(*Tree)->leftChild;
    (*Tree)->leftChild=leftTree->rightChild;
    leftTree->rightChild=(*Tree);
    (*Tree)=leftTree;
}

void balanceLeftTree(BinaryTreeNode **Tree)
{
    BinaryTreeNode *leftTree, *leftTreeRight;
    leftTree=(*Tree)->leftChild;
    switch(leftTree->isBalance){
        case -1:
            (*Tree)->isBalance=0;
            leftTree->isBalance=0;
            movingRightTreeNode(Tree);
            break;
        case 1:
            leftTreeRight=leftTree->rightChild;
            switch(leftTreeRight->isBalance)
            {
                case -1:
                    (*Tree)->isBalance=1;
                    leftTree->isBalance=0;
                    break;
                case 0:
                    (*Tree)->isBalance=0;
                    leftTree->isBalance=0;
                    break;
                case 1:
                    (*Tree)->isBalance=0;
                    leftTree->isBalance=-1;
                    break;
            }
            leftTreeRight->isBalance=0;
            movingLeftTreeNode(&(*Tree)->leftChild);
            movingRightTreeNode(Tree);
            break;
    }
}

void balanceRightTree(BinaryTreeNode **Tree)
{
    BinaryTreeNode *rightTree, *rightTreeLeft;
    rightTree=(*Tree)->rightChild;
    switch(rightTree->isBalance){
        case -1:
            rightTreeLeft=rightTree->leftChild;
            switch(rightTreeLeft->isBalance)
            {
                case -1:
                    (*Tree)->isBalance=0;
                    rightTree->isBalance=1;
                    break;
                case 0:
                    (*Tree)->isBalance=0;
                    rightTree->isBalance=0;
                    break;
                case 1:
                    (*Tree)->isBalance=-1;
                    rightTree->isBalance=0;
                    break;
            }
            rightTreeLeft->isBalance=0;
            movingRightTreeNode(&(*Tree)->rightChild);
            movingLeftTreeNode(Tree);
            break;
        case 1:
            (*Tree)->isBalance=0;
            rightTree->isBalance=0;
            movingLeftTreeNode(Tree);
            break;
    }
}

void traversingBinaryTree(BinaryTreeNode *Tree)
{
    if (!Tree)
    {
        return;
    }
    traversingBinaryTree(Tree->leftChild);
    printf("%d ", Tree->data);
    traversingBinaryTree(Tree->rightChild);
}

bool insertTreeNode(BinaryTreeNode **Tree, bool *isHigher, int insertData)
{
    if(!(*Tree)){
        (*Tree)=(BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
        (*Tree)->data=insertData;
        (*Tree)->leftChild=(*Tree)->rightChild=nullptr;
        (*Tree)->isBalance=0;
        (*isHigher)= true;
        return true;
    }
    else{
        if(insertData == (*Tree)->data)
        {
            (*isHigher) = false;
            return false;
        }
        else if(insertData < (*Tree)->data)
        {
            if (!insertTreeNode(&(*Tree)->leftChild, isHigher, insertData))
            {
                return false;
            }
            if(*isHigher)
                switch((*Tree)->isBalance)
                {
                    case -1:
                        balanceLeftTree(Tree);
                        (*isHigher)= false;
                        break;
                    case 0:
                        (*Tree)->isBalance=-1;
                        (*isHigher)= true;
                        break;
                    case 1:
                        (*Tree)->isBalance=0;
                        (*isHigher)= false;
                        break;
                }
        }
        else{
            if(!insertTreeNode(&(*Tree)->rightChild, isHigher, insertData))
                return false;
            if(*isHigher) {
                switch ((*Tree)->isBalance) {
                    case -1:
                        (*Tree)->isBalance = 0;
                        (*isHigher) = false;
                        break;
                    case 0:
                        (*Tree)->isBalance = 1;
                        (*isHigher) = true;
                        break;
                    case 1:
                        balanceRightTree(Tree);
                        (*isHigher) = false;
                        break;
                }
            }
        }
    }
    return true;
}