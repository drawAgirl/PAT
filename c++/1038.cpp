//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/24.
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


vector<string> v;

bool cmp(string &a,string &b){
    return a+b < b+a;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for (int i=0; i<n; ++i) {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    string ans;
    for(auto it:v) ans+=it;
    while (ans.size() != 0 && ans[0] =='0') ans.erase(ans.begin());
    if(ans.size() == 0) cout << 0;
    else cout << ans;
    
    
}

