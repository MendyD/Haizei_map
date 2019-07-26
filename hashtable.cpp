/*************************************************************************
	> File Name: hashtable.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 三  7/24 21:06:08 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
template <typename Key, typename Value>
class HashTableCell{
    using value_type = std::pair<Key, Value>;
    value_type value;
    static Key getKey(const value_type & value) {return value.first;};
    bool isZero(){return getKey(value) == 0;};
};

typename <typename Key, typename Value>
class 
using namespace std;
int main(){
    
    return 0;
}
