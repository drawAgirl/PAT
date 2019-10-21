//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/20.
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

const int MAXN = 1e4+10;
int n;
vector<vector<int>> v;
vector<int> ans;
bool vis[MAXN] = {false};
int max_height = 0;
void dfs(int root,int height){
    if(height > max_height){
        max_height = height;
        ans.clear();
        ans.emplace_back(root);
    }else if (height == max_height) ans.emplace_back(root);
    vis[root] = true;
    for(auto &each:v[root]){
        if(vis[each]) continue;
        dfs(each, height+1);
    }
}


int main(){
    scanf("%d",&n);
    v.resize(n+1);
    int a,b;
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int s1 = 0;
    int cnt = 0;
    set<int> s;
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        dfs(i, 1);
        if(i==1){
            if(ans.size() != 0) s1 = ans[0];
            for(auto &each:ans) s.insert(each);
        }
        cnt ++;
        
    }
    if(cnt > 1 ) printf("Error: %d components\n",cnt);
    else{
        ans.clear();
        max_height = 0;
        fill(vis, vis+MAXN, false);
        dfs(s1, 1);
        for(auto &each:ans) s.insert(each);
        for(auto &each:s) printf("%d\n",each);
    }
}
