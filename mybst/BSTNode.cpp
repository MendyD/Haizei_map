/*************************************************************************
	> File Name: BSTNode.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 六  7/20 14:50:47 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
#include "BSTNode.h"

BSTNode::BSTNode() {
    value = 0;
    lchild = nullptr;
    rchild = nullptr;
}

BSTNode::BSTNode(int val) {
    value = val;
    lchild = nullptr;
    rchild = nullptr;
}
