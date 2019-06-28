#include <iostream>
#include <vector>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char * argv[]) {
    bool isHigher;
    vector<int> data;
    cout<<"请输入二叉树十个节点的值：";
    for (int i = 0; i < 10; ++i) {
        int inputData;
        cin>>inputData;
        data.push_back(inputData);
    }
    BinaryTreeNode *MyTree = nullptr;
    for (int j = 0; j < data.size(); ++j) {
        insertTreeNode(&MyTree, &isHigher, data[j]);
    }
    cout<<"中序遍历结果为："<<endl;
    traversingBinaryTree(MyTree);
    return 0;
}