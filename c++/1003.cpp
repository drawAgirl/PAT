//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/28.
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

const int INF = 1e6;
const int MAXN = 510;
int n,m,c1,c2;
typedef pair<int, int> pp;
int people[MAXN];
int d[MAXN];
int w[MAXN];
bool vis[MAXN] = { false };
int path[MAXN];
vector<pp> graph[MAXN];

void Dijkstra(int s){
    fill(path, path+MAXN, 1);
    fill(w, w+MAXN, 0);
    fill(d, d+MAXN, INF);
    priority_queue<pp,vector<pp>,greater<pp>> q;
    d[s] = 0;
    w[s] = people[s];
    q.push({0,s});
    while (!q.empty()) {
        pp cur = q.top();
        q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = true;
        for(int i=0;i<graph[cur.second].size();++i){
            int dis = graph[cur.second][i].first;
            int to = graph[cur.second][i].second;
            if(vis[to] == false && dis + cur.first < d[to]){
                d[to] = dis + cur.first;
                w[to] = w[cur.second]+people[to];
                path[to] = path[cur.second];
                q.push({d[to],to});
            }else if (vis[to] == false && dis+cur.first == d[to]){
                if(w[to] < w[cur.second] + people[to]){
                    w[to] = w[cur.second] + people[to];
                    q.push({d[to],to});
                }
                path[to] += path[cur.second];
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0;i<n;++i) scanf("%d",&people[i]);
    for(int i=0;i<m;++i){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        graph[a].push_back(pp(c,b));
        graph[b].push_back(pp(c,a));
    }
    Dijkstra(c1);
    printf("%d %d",path[c2],w[c2]);
    
}
