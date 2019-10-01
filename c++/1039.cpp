//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/1.
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
#include <set>
using namespace std;

int n,k;

unordered_map<string,set<int>> database;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string name;
    cin >> n >> k;
    for(int i=0;i<k;++i){
        int a,b;
        cin >> a>>b;
        for(int j=0;j<b;++j){
            cin >> name;
            database[name].insert(a);
        }
    }
    for(int i=0;i<n;++i){
        cin >> name;
        cout << name << " "<<database[name].size();
        for(auto each:database[name]) cout << " " << each;
        cout <<"\n";
    }
}
