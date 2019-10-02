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

const int INF = 0x3f3f3f3f;
const int MAXN = 510;
int c,n,s,m;
int station[MAXN];
typedef pair<int, int> pp;
vector<pp> g[MAXN];
bool vis[MAXN] = {false};
int d[MAXN];
vector<int> pre[MAXN];
vector<int> path,temppath;
int minneed = INF;
int minremain = INF;

void dfs(int v){
    if(v == 0){
        temppath.push_back(v);
        int need = 0;
        int remain = 0;
        for(int i=temppath.size()-1;i>=0;i--){
            int id = temppath[i];
            if(station[id] > 0){
                remain += station[id];
            }else{
                if(remain > abs(station[id]))
                    remain -= abs(station[id]);
                else{
                    need += abs(station[id])-remain;
                    remain = 0;
                }
            }
        }
        if(need < minneed){
            minneed = need;
            minremain = remain;
            path = temppath;
        }else if(need == minneed && remain < minremain){
            minremain = remain;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    temppath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
   temppath.pop_back();
}
void Dijkstra(){
    fill(d, d+MAXN, INF);
    d[0] = 0;
    priority_queue<pp,vector<pp>,greater<pp>> q;
    q.push({0,0});
    while (q.size()) {
        pp cur = q.top();
        q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = true;
        for(int i=0;i<g[cur.second].size();++i){
            int dis = g[cur.second][i].first;
            int to = g[cur.second][i].second;
            if(vis[to]==false && dis+cur.first < d[to]){
                d[to] = dis+cur.first;
                pre[to].clear();
                pre[to].push_back(cur.second);
                q.push({d[to],to});
            }else if (vis[to]== false && dis+cur.first == d[to]){
                pre[to].push_back(cur.second);
                q.push({d[to],to});
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d",&c,&n,&s,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&station[i]);
        station[i] -= c/2;
    }
    for(int i=0;i<m;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x].push_back({z,y});
        g[y].push_back({z,x});
    }
    Dijkstra();
    path.push_back(s);
    dfs(s);
    printf("%d ",minneed);
    for(int i=(int)path.size()-1;i>=0;--i){
        printf("%d",path[i]);
        if(i>0)printf("->");
    }
    printf(" %d",minremain);

}
