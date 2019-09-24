//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/23.
//  Copyright © 2019 李寻欢. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string.h>
using namespace std;

unordered_map<char, bool> HASH;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    for(auto it:b) HASH[it] = true;
    for(auto it:a){
        if(HASH.find(it) == HASH.end()) cout << it;
    }
    
}
