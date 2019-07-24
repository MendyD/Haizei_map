/*************************************************************************
	> File Name: bst.h
	> Course:二叉排序树类的封装 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 六  7/20 14:36:59 2019
 ************************************************************************/

#ifndef _BST_H
#define _BST_H

#include "BSTNode.h"
#include <vector>
#include <iostream>
using namespace std;

class BSTNode;
class BST {
public : 
    //构造函数
    BST();
    BST(vector<int>arr);
    BST(int *arr, int length);

    //析构函数
    ~BST();
    
    bool isEmpty() const;
    bool search(const int &key);
    bool insertNode(const int &key);
    bool deleteNode(const int &key);
    bool inorder(vector<int>&);
private :
    BSTNode *bstroot;//根节点
    BSTNode *__search(BSTNode *root, const int &key);
    bool __insertNode(const int &key);
    bool __deleteNode(const int &key);
    bool __isLeaf(BSTNode * const &);
    bool __isNodeWithTwoChild(BSTNode * const &);
    void __inorder(BSTNode *root, vector<int>&result);
    void __deleteAllNodes(BSTNode *root);
};

#endif
