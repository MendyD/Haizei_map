/*************************************************************************
	> File Name: test_map.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 四  7/18 20:25:15 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
int main(){
    map <int, int> mp;
    map <int, int> mp2;
    int n = 10;
    for(int i = 1; i < n; i++) mp[i] = i * 100;
    for(int i = 1; i < n; i++) cout << mp[i] << endl;
    for(int i = 1; i < n; i++) mp.insert(make_pair(i, i * 100));
    for(int i = 1; i < n; i++) cout << mp[i] << endl;
    map<int, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); it++) printf("%d->%d\n", it->first, it->second);
    return 0;
}
