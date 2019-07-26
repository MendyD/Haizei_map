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


struct BaseNode {
    BaseNode(BaseNode *parents = nullptr) :
        lchild(nullptr),
        rchild(nullptr),
        parents(parents) {}//初始化列表
    BaseNode *&plchild() {return this->parents->lchild;}
    BaseNode *&prchild() {return this->parents->rchild;}
    BaseNode *lchild, *rchild, *parents;
    virtual ~BaseNode(){}
};

template <typename VALUE_T>
struct TreeNode : BaseNode{
    TreeNode(VALUE_T value, TreeNode *parents = nullptr) :
        BaseNode(parentes),
        value(value){}//初始化列表
    VALUE_T value;
};

template <typename VALUE_T>
class BinarySearchTreeIteratorImpl {
public :
    using pTreeNode = TreeNode<VALUE_T> *;
    using Self = BinarySearchTreeIteratorImpl;
    BinarySearchTreeIteratorImpl(BaseNode * obj) : obj(obj) {}//初始化列表
    VALUE_T &operator *();
    Self &operator++();
    Self operator++(int);
    Self &operator--();
    Self operator--(int);
    VALUE_T *operator->() {
        return &(*(*this));
    }
    bool operator!=(const BinarySearchTreeIteratorImpl &iter) {
        return this->obj != iter.obj;
    }
    pTreeNode getObj() {return this->obj;}

private :
    BaseNode *obj;
};

class BinarySearchTreeHelper {
public:
    using pTreeNode = BaseNode *;
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
    using Node = TreeNode<VALUE_T>;
    using pNode = TreeNode<VALUE_T> *;//重命名
    using pBaseNode = BaseNode *;
    using iterator = BinarySearchTreeIteratorImpl;

    BinarySearchTree() : header(nullptr) {
        header = (Node *)malloc(sizeof(Node);
        header->lchild = header->rchild = nullptr;
        header->parents = header;
    }//默认构造函数

    bool insert(VALUE_T value) {
        if (root() == nullptr) {
            header.lchild = new Node(value, &header);
            return true;
        }
        pNode p = root();//指针指向根节点
        for(;;) {
            if(value < p->value) {
                if(p->lchild) p = dynamic_cast<pNode *>(p->lchild);
                else break;
            } else if(p->value < value) {
                if(p->rchild) p = dynamic_cast<pNode>(p->rchild);
                else break;
            } else {
                return false;
            }
        }
        (value < p->value ? p->lchild : p->rchild) = new Node(value, p);
        return true;
    }
    
    iterator find(const VALUE_T &value) {
        pNode p = root();
        while(p) {
            //p = (value < p->value ? p->lchild : value > p->value ? p->rchild : nullptr);
            if(value < p->value) p = dynamic_cast<pNode>(p->lchild);
            else if(value > p->value) p = dynamic_cast<pNode>(p->rchild);
            else return iterator(p);
        }
        return end();
    }

    bool erase(const VALUE_T &value){
        pNode p = find(value).getObj();//指针指向根节点
        if(p == end().getObj()) return false;
        if(p->lchild == nullptr || p->rchild == nullptr) {
            pNode temp = dynamic_cast<>pNode(p->lchild ? p->lchild : p->rchild);
            (p->plchild() == p ? p->plchild() : p->prchild()) = temp;
            delete p;
            return true;
        }
        pNode temp = dynamic_cast<>pNode(BinarySearchTreeHelper::descrement(p));
        swap(p->value, temp->value);
        p = temp;
        temp = dynamic_cast<pNode>(p->lchild ? p->lchild : p->rchild);
        (p->plchild() == p ? p->plchild() : p->prchild()) = temp;
        delete p;
        return true;
    }

    iterator begin() { return iterator(BinarySearchTreeHelper::leftMost(header)); }
    iterator end() { return iterator(header); }
    ~BinarySearchTree(){
        free(header);
    }
private :
    pNode header;
    pNode root() {
        return header->lchild;
    }
};

template<typename T>
T &BinarySearchTreeIteratorImpl<T>::operator *() {
    return dynamic_cast<TreeNode<T> *>(obj)->value;
}
template<typename T>
BinarySearchTreeIteratorImpl<T> &BinarySearchTreeIteratorImpl<T>::operator++() {
    //前++
    obj = BinarySearchTreeHelper::increment(obj);
    return *this;
}
template<typename T>
BinarySearchTreeIteratorImpl<T> BinarySearchTreeIteratorImpl<T>::operator++(int) {
    //后++
    Self old = *this;
    obj = BinarySearchTreeHelper::increment(obj);
    return old;
}
template<typename T>
BinarySearchTreeIteratorImpl<T> &BinarySearchTreeIteratorImpl<T>::operator--(){
    //前--
    obj = BinarySearchTreeHelper::descrement(obj);
    return *this;
}
template<typename T>
BinarySearchTreeIteratorImpl<T> BinarySearchTreeIteratorImpl<T>::operator--(int) {
    //后--
    Self old = *this;
    obj = BinarySearchTreeHelper::descrement(obj);
    return old;
}
}
