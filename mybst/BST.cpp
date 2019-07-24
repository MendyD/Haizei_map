/*************************************************************************
	> File Name: BST.cpp
	> Course:类的实现
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 六  7/20 15:22:44 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#include "BST.h"
//构造函数
BST::BST() {
    bstroot = nullptr;
}

BST::BST(int *arr, int length) {
    bstroot = nullptr;
    for(int i = 0; i < length; i++) {
        __insertNode(*arr + i);
    }
}

BST::BST(vector<int>arr) {
    bstroot = nullptr;
    for(int i = 0; i < (int)arr.size(); i++) {
        __insertNode(arr[i]);
    }
}


bool BST::isEmpty() const {
    return bstroot == nullptr;
}

BSTNode* BST::__search(BSTNode *root, const int &key){
    if(root == nullptr) return nullptr;
    if(key == root->value) return root;
    else if(key > root->value) return __search(root->rchild, key);
    else return __search(root->lchild, key);
}

bool BST::search(const int &key) {
    BSTNode *node = __search(bstroot, key);
    return node;
}

bool BST::__insertNode(const int &key) {
    BSTNode *node = new BSTNode(key);
    BSTNode *parent = nullptr;
    if(isEmpty()) {
        bstroot = node;
        return true;
    } else {
        BSTNode *current = bstroot;
        while(current) {
            parent = current;
            if(node->value > current->value) {
                current = current->rchild;
            } else {
                current = current->lchild;
            }
        }
        if(node->value > parent->value) {
            parent->rchild = node;
            return true;
        } else {
            parent->lchild = node;
            return true;
        }
    }
    return false;
}

bool BST::insertNode(const int &key) {
    return __insertNode(key);
}

bool BST::__isLeaf(BSTNode * const &root) {
    if(root->lchild == nullptr && root->rchild == nullptr) {
        return true;
    } else {
        return false;
    }
}

bool BST::__isNodeWithTwoChild(BSTNode * const &root) {
    if(root->lchild != nullptr && root->rchild != nullptr) {
        return true;
    } else {
        return false;
    }
}

bool __deleteNode(const int &key) {
    
}



bool BST::deleteNode(const int &key) {
    return __deleteNode(key);
}

BSTNode *__search(BSTNode *root, const int &key) {

}

bool search(const int &key) {

}
