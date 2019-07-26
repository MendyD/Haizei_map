/*************************************************************************
	> File Name: 12.hashtable.h
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 四  7/25 13:32:42 2019
 ************************************************************************/
using namespace std;

#pragma once

//结构定义
template <typename T>
struct HashNode {
    T **elem;
    T value;
};
using pHashNode = HashNode *;

class iterator_hash{
public:
    iterator(){};
    iterator_hash(pHashNode b1) : b1(b1){};
    bool operator==(iterator_hash &ht) {return value == ht.value;}
    bool operator!=(iterator_hash &ht) {return value != ht.value;}
    
private:
    T *value;
};


//结构操作
