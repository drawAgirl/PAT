//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/4.
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


unordered_map<int, vector<string>> course; // 这里用set会超时所以用数组最后一次排序
int n,k,m,cur;
bool cmp(string &a,string &b){
    return a < b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    string name;
    for (int i=0; i<n; i++) {
        cin >> name >> m;
        for(int j=0;j<m;++j){
            cin >> cur;
            course[cur].push_back(name);
        }
    }
    for(int i=1;i<=k;++i){
        cout << i << " " << course[i].size() <<"\n";
        sort(course[i].begin(), course[i].end(), cmp);
        for(auto &each:course[i]) cout << each <<"\n";
    }
}
