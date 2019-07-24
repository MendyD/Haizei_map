/*************************************************************************
	> File Name: map.h
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 五  7/19 16:44:58 2019
 ************************************************************************/

#ifndef _MAP_H
#define _MAP_H
#include <iostream>
#include "bstree.h"
//声明模板
namespace nmap{
    template<
        typename Key,//唯一，用compare排序
        typename Value,
        typename Compare = std::less<Key>,
        class TreeType = BinarySearchTree<Key, Compare, std::pair<Key, Value>>>
    class map {
    public : 
        using ValuePair = std::pair<Key, Value>;
        using Tree = TreeType;
        using iterator = typename Tree::iterator;
        using const_iterator = typename Tree::const_iterator;

        map() : tree() {}

        std::pair<iterator, bool> insert(const ValuePair &value_pair) {
            return tree.insert_unique(value_pair);
        }

        size_t erase(const Key &key) {
            return tree.erase(key);
        }

        iterator find(const Key &key) {
            return tree.find(key);
        }

        const_iterator find(const Key &key) {
            return tree.find(key);
        }

        iterator begin() {
            return tree.begin();
        }

        const_iterator begin() const {
            return tree.begin();
        }

        iterator end() {
            return tree.end();
        }

        const_iterator end() const {
            return tree.end();
        }
    private :
        Tree tree;
    };
}


#endif
