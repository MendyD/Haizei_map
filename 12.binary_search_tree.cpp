/*************************************************************************
	> File Name: 12.binary_search_tree.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 六  7/20 18:36:08 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;


class TreeNode {
public :
    TreeNode(int value) :
        value(value), 
        lchild(nullptr), 
        rchild(nullptr) {}//构造函数

private :
    TreeNode *lchild;
    TreeNode *rchild;
    int value;
};
