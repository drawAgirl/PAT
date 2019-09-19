//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/17.
//  Copyright © 2019 李寻欢. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;


int main() {
//    cout<< " please input:\n";
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    string c;
    c = to_string(abs(a+b));
    if(a+b < 0) cout << "-";
    for (int i=0; i<(int)c.size(); i++) {
        cout << c[i];
        if ((i + 1) % 3 == c.size() % 3 && i != c.size() - 1) cout << ",";
    }
 
    
}
