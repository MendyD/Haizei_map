/*************************************************************************
	> File Name: 12.main.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 三  7/24 14:47:56 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include "12.binary_search_tree.h"
using namespace std;
using ArrayInt = haizei::BinarySearchTree<int>;
int main(){
    srand(time(0));
    ArrayInt arr;
    for(int i = 0; i < 20; i++) arr.insert(rand() % 100);
    for(Array::iterator iter = arr.begin(); iter != arr.end(); iter++) {
        cout << *iter <<  endl;
    }
    return 0;
}
