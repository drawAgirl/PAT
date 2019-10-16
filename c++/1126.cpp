//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/16.
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
const int MAXN = 510;
int n,m;
int indegree[MAXN] = {0};
vector<int> g[MAXN];
bool vis[MAXN] = {false};
int cnt= 0;
void dfs(int idx){
    if(vis[idx]) return;
    vis[idx] = true;
    cnt++;
    for(auto &next:g[idx]) dfs(next);
}


int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        indegree[a]++;
        indegree[b]++;
    }
    dfs(1);
    int even_cnt = 0;
    int odd_cnt=0;
    for(int i=1;i<=n;++i){
        printf("%d",indegree[i]);
        if(i!=n) printf(" ");
        else printf("\n");
        if(indegree[i] & 1) odd_cnt++;
        else even_cnt++;
    }
    if(cnt != n) printf("Non-Eulerian\n");
    else if(odd_cnt == 0 && even_cnt==n) printf("Eulerian\n");
    else if (even_cnt==n-2 && odd_cnt==2) printf("Semi-Eulerian\n");
    else printf("Non-Eulerian\n");
    
}
