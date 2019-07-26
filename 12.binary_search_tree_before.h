/*************************************************************************
	> File Name: 12.binary_search_tree.h
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 六  7/20 18:38:53 2019
 ************************************************************************/

using namespace std;
#pragma once
namespace haizei{

class BinarySearchTree;
class BinarySearchTreeIteratorImpl;
class TreeNode;

using pTreeNode = TreeNode *;

struct TreeNode {
    TreeNode(int value = 0, TreeNode *parents = nullptr) :
    value(value),
    lchild(nullptr),
    rchild(nullptr),
    parents(parents) {}//构造函数//初始化列表
    TreeNode * &plchild() { return this->parents->lchild; }
    TreeNode * &prchild() { return this->parents->rchild; }
    TreeNode *lchild, *rchild, *parents;
    int value;
};

class BinarySearchTreeIteratorImpl {
public :
    using Self = BinarySearchTreeIteratorImpl;
    BinarySearchTreeIteratorImpl(pTreeNode obj) : obj(obj) {}
    int operator *();
    Self &operator++();
    Self operator++(int);
    Self &operator--();
    Self operator--(int);
    bool operator!=(const BinarySearchTreeIteratorImpl &iter) {
        return this->obj != iter.obj;
    }
    pTreeNode getObj() {return this->obj;}

private :
    pTreeNode obj;
};

class BinarySearchTreeHelper {
public:
    static pTreeNode descrement(pTreeNode node) {
        if(node->lchild) return BinarySearchTreeHelper::rightMost(node->lchild);
        while(node->parents !=  node && node->plchild() == node) node = node->parents;
        return node->parents;
    }
    static pTreeNode increment(pTreeNode node) {
        if(node->rchild) return BinarySearchTreeHelper::leftMost(node->rchild);
        while(node->parents != node  && node->prchild() == node) node = node->parents;
        return node->parents;
    }
    static pTreeNode rightMost(pTreeNode node) {
        while(node->rchild) node = node->rchild;
        return node;
    }
    static pTreeNode leftMost(pTreeNode node) {
        while(node->lchild) node = node->lchild;
        return node;
    }
};

class BinarySearchTree{
public :
    using pTreeNode = TreeNode *;//重命名
    using iterator = BinarySearchTreeIteratorImpl;

    BinarySearchTree() : header() {
        header.parents = &header;
    }//默认构造函数

    bool insert(int value) {
        if (root() == nullptr) {
            header.lchild = new TreeNode(value, &header);
            return true;
        }
        pTreeNode p = root();//指针指向根节点
        for(;;) {
            if(value < p->value) {
                if(p->lchild) p = p->lchild;
                else break;
            }
            if(value > p->value) {
                if(p->rchild) p = p->rchild;
                else break;
            }
            if(value == p->value) return false;
        }
        (value < p->value ? p->lchild : p->rchild) = new TreeNode(value, p);
        return true;
    }
    
    iterator find(int value) {
        pTreeNode p = root();
        while(p) {
            //p = (value < p->value ? p->lchild : value > p->value ? p->rchild : nullptr);
            if(value < p->value) p = p->lchild;
            else if(value > p->value) p = p->rchild;
            else return iterator(p);
        }
        return end();
    }

    bool erase(int value){
        pTreeNode p = find(value).getObj();//指针指向根节点
        if(p == end().getObj()) return false;
        if(p->lchild == nullptr || p->rchild == nullptr) {
            pTreeNode temp = (p->lchild ? p->lchild : p->rchild);
            (p->plchild() == p ? p->plchild() : p->prchild()) = temp;
            delete p;
            return true;
        }
        pTreeNode temp = BinarySearchTreeHelper::descrement(p);
        swap(p->value, temp->value);
        p = temp;
        temp = (p->lchild ? p->lchild : p->rchild);
        (p->plchild() == p ? p->plchild() : p->prchild()) = temp;
        delete p;
        return true;
    }

    iterator begin() { return iterator(BinarySearchTreeHelper::leftMost(&header)); }
    iterator end() { return iterator(&header); }
private :
    TreeNode header;
    pTreeNode root() {
        return header.lchild;
    }
};

int BinarySearchTreeIteratorImpl::operator *() {return obj->value;}
BinarySearchTreeIteratorImpl &BinarySearchTreeIteratorImpl::operator++() {
    //前++
    obj = BinarySearchTreeHelper::increment(obj);
    return *this;
}
BinarySearchTreeIteratorImpl BinarySearchTreeIteratorImpl::operator++(int) {
    //后++
    Self old = *this;
    obj = BinarySearchTreeHelper::increment(obj);
    return old;
}
BinarySearchTreeIteratorImpl &BinarySearchTreeIteratorImpl::operator--(){
    //前--
    obj = BinarySearchTreeHelper::descrement(obj);
    return *this;
}
BinarySearchTreeIteratorImpl BinarySearchTreeIteratorImpl::operator--(int) {
    //后--
    Self old = *this;
    obj = BinarySearchTreeHelper::descrement(obj);
    return old;
}
}
