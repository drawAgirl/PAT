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
int n,m,s,d;
typedef pair<int, int> pp;
vector<pp> g[MAXN];
bool vis[MAXN] = { false };
int dis[MAXN];
int pre[MAXN];
int total[MAXN];
int cost[MAXN][MAXN];
vector<int> path;

void dfs(int s,int d){
    if(d != s){
        path.push_back(d);
        dfs(s, pre[d]);
    }
}



void Dijkstra(int s){
    fill(total, total+MAXN, INF);
    fill(dis, dis+MAXN, INF);
    for(int i=0;i<n;++i) pre[i] = i;
    dis[s] = 0;
    total[s] = 0;
    priority_queue<pp,vector<pp>,greater<pp>> q;
    q.push({0,s});
    while (q.size()) {
        pp cur = q.top();
        q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = true;
        for(int i=0;i<g[cur.second].size();++i){
            int distance = g[cur.second][i].first;
            int to = g[cur.second][i].second;
            if(vis[to] == false && cur.first + distance < dis[to]){
                dis[to] = cur.first + distance;
                pre[to] = cur.second;
                total[to] = total[cur.second] + cost[cur.second][to];
                q.push({dis[to],to});
            }else if(vis[to] == false && cur.first + distance == dis[to]){
                if(total[to] > total[cur.second] + cost[cur.second][to]){
                    total[to] = total[cur.second] + cost[cur.second][to];
                    pre[to] = cur.second;
                    q.push({dis[to],to});
                }
            }
        }
    }
}



int main(){
    scanf("%d%d%d%d",&n,&m,&s,&d);
    for(int i=0;i<m;++i){
        int a,b,c,distance;
        scanf("%d%d%d%d",&a,&b,&distance,&c);
        g[a].push_back({distance,b});
        g[b].push_back({distance,a});
        cost[a][b] = cost[b][a] = c;
    }
    Dijkstra(s);
    dfs(s,d);
    printf("%d ",s);
    for(int i=(int)path.size()-1;i>=0;i--){
        printf("%d ",path[i]);
    }
    printf("%d %d",dis[d],total[d]);
}
