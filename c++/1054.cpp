//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/7.
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

int n,m;
unordered_map<string, int> cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    string t;
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin >> t;
            cnt[t]++;
        }
    }
    int ans = 0;
    string num;
    for(auto it=cnt.begin();it!=cnt.end();it++){
        if(it->second > ans){
            ans = it->second;
            num = it->first;
        }
    }
    cout << num;
}
