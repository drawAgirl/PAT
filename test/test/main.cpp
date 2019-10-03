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

const int MAXN = 210;
const int INF = 0x3f3f3f3f;
int n,m,happy;
int ind = 0;
string start;
unordered_map<string, int> string_to_int;
unordered_map<int, string> back_to_string;
int dic[MAXN];
typedef pair<int, int> pp;
vector<pp> g[MAXN];
bool vis[MAXN] = { false};
int d[MAXN];
vector<int> pre[MAXN];
vector<int> path,tempPath;
int max_happy = 0;
double average_happy = 0.0;
int cnt = 0;
void dijkstra(int s){
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
            if(vis[to]== false && dis+cur.first < d[to]){
                d[to] = dis+cur.first;
                pre[to].clear();
                pre[to].push_back(cur.second);
                q.push({d[to],to});
            }else if (vis[to] == false && dis+cur.first == d[to]){
                pre[to].push_back(cur.second);
                q.push({d[to],to});
            }
        }
    }
}


void dfs(int s){
    if(s == 0){
        cnt++;
        int cur = 0;
        for(auto each:tempPath) cur+=dic[each];
        if(cur > max_happy){
            max_happy = cur;
            average_happy = 1.0*max_happy/(int)tempPath.size();
            path = tempPath;
        }else if(cur == max_happy){
            if(average_happy < 1.0*cur/(int)tempPath.size()){
                average_happy = 1.0*cur/(int)tempPath.size();
                path = tempPath;
            }
        }
        return;
    }
    tempPath.push_back(s);
    for(auto each:pre[s]) dfs(each);
    tempPath.pop_back();
}

int main(){
//    ios::sync_with_stdio(false); 这题真的佛了，bug找了半个小时 把同步关了就通过。
//    cin.tie(0);
    cin >> n >> m >> start;
    string_to_int[start] = ind;
    back_to_string[ind++] = start;
    string cur;
    for(int i=1;i<n;++i){
        cin >> cur >> happy;
        string_to_int[cur] = ind;
        dic[ind] = happy;
        back_to_string[ind++] = cur;
    }
    string a,b;
    int dis;
    for(int i=0;i<m;++i){
        cin >> a >>b >> dis;
        g[string_to_int[a]].push_back({dis,string_to_int[b]});
        g[string_to_int[b]].push_back({dis,string_to_int[a]});
    }
    int destination = string_to_int["ROM"];
    dijkstra(0);
    dfs(destination);
    path.push_back(0);
    printf("%d %d %d %d\n",cnt,d[destination],max_happy,(int)average_happy);
    for(int i=(int)path.size()-1;i>=0;--i){
        cout << back_to_string[path[i]];
        if(i) cout <<"->";
    }
}

