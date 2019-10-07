//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/3.
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
const int MAXN = 1100;
int n,m,k,dis;
int idx = 0;
typedef pair<int, int> pp;
vector<pp> g[MAXN];
bool vis[MAXN];
int d[MAXN];

int to_int(string a){
    int ans = 0;
    if(a[0] == 'G'){
        for(int i=1;i<(int)a.size();++i) ans=ans*10+ a[i]-'0';
    }else{
        for(int i=0;i<(int)a.size();++i) ans=ans*10+ a[i]-'0';
    }
    if(a[0] == 'G')
        return n+ans;
    return ans;
}


void Dijkstra(int s){
    fill(vis, vis+MAXN, false);
    fill(d, d+MAXN, INF);
    d[s] = 0;
    priority_queue<pp,vector<pp>,greater<pp>> q;
    q.push({0,s});
    while (q.size()) {
        pp cur = q.top();
        q.pop();
        if (vis[cur.second]) continue;
        vis[cur.second] = true;
        for(int i=0;i<(int)g[cur.second].size();++i){
            int to = g[cur.second][i].second;
            int dis = g[cur.second][i].first;
            if(vis[to] == false && dis+cur.first < d[to]){
                d[to] = dis+cur.first;
                q.push({d[to],to});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> dis;
    string a,b;
    int c;
    int x,y;
    for(int i=0;i<k;++i){
        cin >> a >> b >> c;
        x = to_int(a);
        y = to_int(b);
        g[x].push_back({c,y});
        g[y].push_back({c,x});
    }
    int ans_index = -1;
    int min_dis = -INF;
    double min_average = INF;
    for(int i=n+1;i<=n+m;++i){
        Dijkstra(i);
        int total = 0;
        int cur_min = INF;
        int cur_max = -INF;
        for(int j=1;j<=n;++j){
            total += d[j];
            cur_max = max(cur_max,d[j]);
            cur_min = min(cur_min,d[j]); //找到当前加油站离所有村庄最小的距离
        }
        if(cur_max>dis)continue; // 如果大于极限距离就下一个
        if(min_dis < cur_min){ //找到最小距离中最大的距离
            ans_index = i;
            min_dis = cur_min;
            min_average = 1.0*total/n;
        }else if (min_dis == cur_min){
            double now = 1.0*total/n;
            if(now < min_average){
                ans_index = i;
                min_average = now;
            }
        }
    }
    if(ans_index == -1) printf("No Solution\n");
    else{
        printf("G%d\n",ans_index-n);
        printf("%.1f %.1f",1.0*min_dis,min_average+0.005);
    }
}
