/*************************************************************************
	> File Name: BSTNode.h
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 六  7/20 14:48:39 2019
 ************************************************************************/

#ifndef _BSTNODE_H
#define _BSTNODE_H

#include <iostream>
class BSTNode {
public :
    BSTNode();
    BSTNode(int val);
    int value;
    BSTNode *lchild;
    BSTNode *rchild;
    BSTNode *father;
}
#endif
