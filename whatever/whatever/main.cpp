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
unordered_map<int, vector<int>> g;
bool vis[MAXN] = {false};
int max_depth = 0;
vector<int> deep_root;

void dfs(int root,int &cnt){
    if(vis[root]) return;
    vis[root] = true;
    cnt++;
    for(auto &each:g[root]) dfs(each,cnt);
}

int main(){
    scanf("%d",&n);
    if(n == 1){
        printf("1");
        return 0;
    }
    int a,b;
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int components = 0;
    int cnt = 0;
    bool flag = false;
    for(int i=1;i<=n;++i){
        fill(vis, vis+MAXN, false);
        queue<int> q;
        q.push(i);
        int depth = 0;
        while (!q.empty()) {
            depth++;
            int size = (int)q.size();
            while (size--) {
                int temp = q.front();
                q.pop();
                if(vis[temp] == false) cnt++;
                vis[temp] = true;
                for(auto &each:g[temp]){
                    if(vis[each] == false) q.push(each);
                }
            }
        }
        if(depth > max_depth){
            max_depth = depth;
            deep_root.clear();
            deep_root.emplace_back(i);
        }else if (depth == max_depth) deep_root.emplace_back(i);
        if(flag) continue;
        if(cnt == n){
            flag = true;
            continue;
        }else components++;
        
    }
    if(components > 0) printf("Error: %d components\n",components+1);
    else{
        for(int i=0;i<(int)deep_root.size();++i) printf("%d\n",deep_root[i]);
        
    }
}
