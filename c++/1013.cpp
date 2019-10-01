//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/29.
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
const int MAXN = 1e3+10;
int n,m,k;
vector<int> g[MAXN];
bool vis[MAXN] = { false};
int cur;
void dfs(int s){
    if(s == cur) return;
    vis[s] = true;
    for(auto each:g[s]){
        if(vis[each] == false) dfs(each);
    }
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0;i<k;++i){
        int block = 0;
        scanf("%d",&cur);
        fill(vis, vis+MAXN, false);
        for(int j=1;j<=n;++j){
            if (j!= cur && vis[j] == false){
                dfs(j);
                block++;
            }
        }
        printf("%d\n",block-1);
    }
}
