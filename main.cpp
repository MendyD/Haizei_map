/*************************************************************************
	> File Name: main.cpp
	> Course: 
	> Author: Mendy 
	> Mail: dolai_c@163.com
	> Created Time: 六  7/20 10:08:50 2019
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include "map.h"
using namespace std;
int main(){
    nmap::map<int, int> m;

    m.insert(make_pair(2, 2));
    m.insert(make_pair(1, 2));
    m.insert(make_pair(3, 2));

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    auto it = m.find(2);
    cout << it->first << " " << it->second << endl;

    m.erase(2);
    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    
    return 0;
}
