//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/21.
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
#include <unordered_map>
#include <string.h>
using namespace std;


int n,a;
double b;

unordered_map<int, double> dic;
map<int, double> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a >> b;
        dic[a] = b;
    }
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a >> b;
        for (auto it=dic.begin(); it!=dic.end(); it++) {
            if(ans.find(it->first+a) == ans.end())
                ans[it->first + a] = it->second*b;
            else
                ans[it->first + a] += it->second*b;
        }
    }
    for (auto it=ans.begin(); it!=ans.end();) {
        if(it->second == 0)
            it = ans.erase(it);
        else
            it++;
    }
    printf("%d",(int)ans.size());
    int size = (int)ans.size();
    for (auto it=ans.end(); size>0; size--) {
        it--;
        if (it == ans.end()) continue;
        printf(" %d %.1f",(*it).first,(*it).second);
    }
    
}
