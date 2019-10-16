//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/15.
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
#include <unordered_set>
#include <string.h>
#include <set>
#include <deque>
using namespace std;


int n,m,s;
unordered_map<string, bool> vis;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> s;
    string name;
    int cnt = 0;
    bool flag = false;
    for(int i=1;i<=m;++i){
        cnt++;
        cin >> name;
        if(i==s){
            flag = true;
            vis[name] = true;
            cout << name << "\n";
            cnt = 0;
            continue;
        }
        if(flag && cnt == n){
            if(vis.find(name) == vis.end()){
                vis[name] = true;
                cout << name <<"\n";
                cnt = 0;
                
            }else cnt--;
        }
        
    }
    if(vis.size() == 0) printf("Keep going...\n");
    
}
