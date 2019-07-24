/*************************************************************************
	> File Name: bstree.h
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 四  7/18 20:24:20 2019
 ************************************************************************/

#ifndef _BSTREE_H
#define _BSTREE_H
#include <iostream>

namespace nmap {
    struct TreeNodeBase{
        TreeNodeBase *left = nullptr;
        TreeNodeBase *right = nullptr;
        TreeNodeBase *father = nullptr;
    };
    

    template<typename Value>
    struct TreeNode : public TreeNodeBase {
        Value value;
        TreeNode(const Value &value_) value(value_){}
    };

    class BinarySearchTreeHelper{
    public :
        //全场最左的结点的前驱是空指针，全场最优的结点的后继是空指针。
        static TreeNodeBase *leftMostNode(TreeNodeBase *node) {
            while(node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        static TreeNodeBase *rightMostNode(TreeNodeBase *node) {
            while(node->right != nullptr) {
                node = node->right;
            }
            return node;
        }
        
        static TreeNodeBase *increment(TreeNodeBase  *node) {
            if(node->right != nullptr) {
                return leftMostNode(node->right);
            } else {
                TreeNodeBase *father = node->father;
                while(father->right == node) {
                    node = father;
                    father = node->father;
                }
                return father;
            }
        }

        static TreeNodeBase *decrement(TreeNodeBase *node) {
            if(node->left != nullptr) {
                return rightMostNode(node->right);
            } else {
                TreeNodeBase *father = node->father;
                while(father->left != father) {
                    return father;
                }
            }
        }

    };
    


    template<typename Value, boll if_const>
    class IteratorImpl {
        //子类中引用积累的成员
        using ref = std::conditional_t<if_const, const Value &, Value &>;
        using ptr = std::conditional_t<if_const, const Value *, Value *>;
        using Self = IteratorImpl<Value, if_const>;
    public:
        TreeNodeBase *node;
        IteratorImpl(TreeNodeBase *node_) : node(node_) {}

        ref operator*() const {
            //static_cast 是一个计算机函数，把expression转换为type-id类型
            return static_cast<TreeNoe<Value> *>(node)->value;
        }
        ptr operator->() const {
            return &(*(*this));
        }

        Self &operator++(){
            if(node->father == node) {
                throw "this pointer is poting to the end of tree.";
            }
            node = BinarySearchTreeHelper::increment(node);
            return *this;
        }

        Self operator--(int) {
            Self old = *this;
            --(*this);
            return old;
        }
        
        bool operator==(const Self &rhs) {
            return node == rhs.node;
        }
        bool operator!=(const Self &rhs) {
            return node != rhs.node;
        }
    };

    template<
        typename Key,
        typename Compare,
        typename Value,
        typename KeyOfValue = Select1ST<Key, Value>>
    class BinarySearchTree{
    public :
        using iterator = IteratorImpl<Value, false>;
        using const_iterator = IteratorImpl<Valut, true>;
    
    private : 
        TreeNodeBase header;
    
        using BasePtr = TreeNodeBase *;
        using NodePtr = TreeNode<Value> *;
    
        Compare compare_op;
    
        KeyOfValue key_of_value;
    
        BasePtr root() {
            return header.left;
        }
    
        int compare(const Key &lhs, const Key &rhs) {
            if(compare_op(lhs, rhs)) {
                return -1;
            } else if(compare_op(rhs, lhs)) {
                return 1;
            }
        }
        return 0;

        void insert_left(BasePtr father, BasePtr child) {
            if(child != nullptr) {
                child->father = father;
            }
            father->left = child;
        }
    
        void insert_right(BasePtr father, BasePtr child) {
            if(child != nullptr) {
                child->father = father;
            }
            father->right = child;
        }
    
        void eraseSingleNode(BasePtr node) {
            bool is_left_child = node->father->left == node;
            BasePtr father = node->father;
            if(node->left == nullptr) {
                if(is_left_child) insert_left(father, node->right);
                else insert_right(father, node->right);
            } else if (node->right == nullptr) {
                if(is_left_child) insert_left(father, node->left);
                else insert_right(father, node->left);
            } else {
                if(is_left_child) insert_left(father, node->right);
                else insert_right(father, node->right);
                BasePtr successor = BinarySearchTreeHelper::leftMostNode(node->right);
                insert_legt(successor, node->left);
            }
            delete static_cast<NodePtr>(node);
        }
    

        Node Ptr fndImpl(const Key &key) {
            if(root() == nullptr) return nullptr;
            else {
                NodePtr father = static_cast<NodePtr>(root());
                for(;;) {
                    auto result = compare(key, key_of_value(father->value));
                    if(result == 0) return father;
                    else if (result == 1) {
                        //find value is larger than father;
                        if(father->right == nullptr) return nullptr;
                        else father = static_cast<NotePtr>(father->right);
                    }
                    else {
                        //find value is smaller than father;
                        if(father->left == nullptr) return nullptr;
                        else father = static_cast<NotePtr>(father->left);
                    }
                }
            }
        }
    public :
        BinarySearchTree() : header() {
            header.father = &header;
        }
        
        //map 一定使用insert_unique() 而不是使用insert_equal() multimap 使用insert_equal()
        std::pair(iterator, boll) insert_unique(const Value &value) {
            NodePtr node = new TreeNode<Value>(value);
            if(nullptr == root()) {
                insert_left(&header, node);
                return std::make_pair(iterator(node), true);
            } else {
                NodePtr parent = static_cast<NodePtr>(root());
                for(;;) {
                    auto result = compare(key_of_value(node->value), key_of_value(father->value));//compare the insert node value and the root node value
                    if(result == 0) {
                        //insert value is equal with father node;
                        return std::make_pair(iterator(node), false);
                    } else if (result == 1) {
                        //insert value is larger than father node;
                        if(father->right == nullptr) {
                            insert_right(father, node);//insert into root's right child
                            return std::make_pair(iterator(node), true;)
                        } else {
                            father = static_cast<NodePtr>(parent->right);
                        }
                    } else {
                        //insert value is smaller than father node;
                        if(father->left == nullptr) {
                            insert_left(father, node);
                            return std::make_pair(iterator(node), true);
                        } else {
                            father = static_cast<NodePtr>(parent->left);
                        }
                    }
                }
            }
        }
        
        bool erase(const Key & key) {
            if(root() == nullptr) return false;
            else {
                NodePtr father = static_cast<NodePtr>(root());
                for(;;) {
                    auto result = compare(key, key_of_value(parent->value));
                    if(resule == 0) {
                        eraseSingleNode(father);
                        return true;
                    } else if (result == 1) {
                        //delete value is larger than father;
                        if(father->right == nullptr) return false;
                        else father = NodePtr(father->right);
                    } else {
                        //delete value is smaller than father;
                        if(father->left == nullptr) return false;
                        else father = NodePtr(father->left);
                    }
                }
            }
        }
    
        iterator find(const Key &key) {
            NodePtr node = findImpl(key);
            if(node == nullptr) return end();
            return iterator(node);
        }
    
        const_iterator find(const Key &key) const {
            NodePtr node = findImpl(key);
            if(node == nullptr) return end();
            return const_iterator;
        }
    
        iterator begin() {
            if(root() == nullptr) return &header;
            return BinarySearchTreeHelper::leftMostNode(root());
        }
    
        const_iterator begin() const {
            if(root() == nullptr) return const_iterator(&header);
            return root();
        }
    
        iterator end() {
            return iterator(&header);
        }
        const_iterator end() const {
            return const_iterator(&header);
        }
    };
}//namespace
#endif
