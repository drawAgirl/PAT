//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/13.
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
#include <deque>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 510;
int n,m;
typedef pair<int, int> pp;
vector<pp> g[MAXN];
vector<pp> gg[MAXN];
int NEED_TIME[MAXN][MAXN];
bool vis[MAXN] = {false};
int d[MAXN];
int t[MAXN];
int cost[MAXN];
//vector<int> pre[MAXN];
int pre[MAXN];
vector<int> time_path[MAXN];
int start,destination;


void Dijkstra(int s){
    fill(cost, cost+MAXN, INF);
    fill(d, d+MAXN, INF);
    for(int i=0;i<=n;++i) pre[i] = i;
    d[s] = 0;
    cost[s] = 0;
    priority_queue<pp,vector<pp>,greater<pp>>q;
    q.push({0,s});
    while (q.size()) {
        pp cur = q.top();
        q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = true;
        for(int i=0;i<g[cur.second].size();++i){
            int to = g[cur.second][i].second;
            int dis = g[cur.second][i].first;
            if(vis[to] == false && cur.first + dis < d[to]){
                d[to] = cur.first + dis;
                cost[to] = cost[cur.second] + NEED_TIME[cur.second][to];
                pre[to] = cur.second;
                q.push({d[to],to});
            }else if (vis[to] == false && cur.first+dis == d[to]){
                if(cost[to] > cost[cur.second] + NEED_TIME[cur.second][to]){
                    cost[to] = cost[cur.second] + NEED_TIME[cur.second][to];
                    pre[to] = cur.second;
                    q.push({d[to],to});
                }
            }
        }
    }
}


void dijkstra_time(int s){
    fill(vis, vis+MAXN, false);
    fill(t, t+MAXN, INF);
    t[s] = 0;
    priority_queue<pp,vector<pp>,greater<>>q;
    q.push({0,s});
    while (q.size()) {
        pp cur = q.top();
        q.pop();
        if(vis[cur.second]) continue;
        vis[cur.second] = true;
        for(int i=0;i<gg[cur.second].size();++i){
            int to = gg[cur.second][i].second;
            int time = gg[cur.second][i].first;
            if(vis[to] == false && cur.first + time < t[to]){
                t[to] = cur.first + time;
                time_path[to].clear();
                time_path[to].push_back(cur.second);
                q.push({t[to],to});
            }else if (vis[to] == false && cur.first+time == t[to]){
                time_path[to].push_back(cur.second);
                q.push({t[to],to});
            }
        }
    }

}




vector<int> path;
vector<int> path_two;
vector<int> best_path;

void dfs(int s){
    if(s != start){
        path.push_back(s);
        dfs(pre[s]);
    }
}
void dfs_two(int s){
    if(s==start){
        if(path_two.size() < best_path.size() || best_path.size() == 0){
            best_path = path_two;
        }
        return;
    }
    path_two.push_back(s);
    if(s != start){
        for(auto &each:time_path[s]) dfs_two(each);
    }
    path_two.pop_back();
}

int main(){
    fill(NEED_TIME[0], NEED_TIME[0]+MAXN*MAXN, INF);
    scanf("%d%d",&n,&m);
    int v1,v2,one_way,dis,tt;
    for(int i=0;i<m;++i){
        scanf("%d%d%d%d%d",&v1,&v2,&one_way,&dis,&tt);
        g[v1].push_back({dis,v2});
        gg[v1].push_back({tt,v2});
        NEED_TIME[v1][v2] = tt;
        if(!one_way){
            g[v2].push_back({dis,v1});
            gg[v2].push_back({tt,v1});
            NEED_TIME[v2][v1] = tt;
        }
    }
    scanf("%d%d",&start,&destination);
    Dijkstra(start);
    dfs(destination);
    path.push_back(start);
    dijkstra_time(start);
    dfs_two(destination);
    best_path.push_back(start);
    bool flag = true;
    if(path != best_path) flag = false;
    if(flag){
        printf("Distance = %d; Time = %d: ",d[destination],t[destination]);
        for(int i=(int)path.size()-1;i>=0;--i){
            printf("%d",path[i]);
            if(i!=0)printf(" -> ");
            else printf("\n");
        }
    }else{
        printf("Distance = %d: ",d[destination]);
        for(int i=(int)path.size()-1;i>=0;--i){
            printf("%d",path[i]);
            if(i!=0) printf(" -> ");
            else printf("\n");
        }
        printf("Time = %d: ",t[destination]);
        for(int i=(int)best_path.size()-1;i>=0;--i){
            printf("%d",best_path[i]);
            if(i!=0)printf(" -> ");
            else printf("\n");
        }
        
    }
}
