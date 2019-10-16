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

int n,m,k;
int start,destination,next_station;
unordered_map<int, vector<int>> graph;
int g[10000][10000] = {0};
unordered_map<int, vector<int>> foot;
bool vis[10000] = {false};
vector<int> best_line;

vector<int> path;
vector<int> best_path;
vector<int> trans_node;
vector<int> best_trans;
void dfs(int s,int step,int &min_step,int trans,int &min_trans,int pre_line,vector<int> lines){
    if(vis[s] == true || step > min_step) return;
    if(s == destination){
        if(min_step > step){
            min_step = step;
            best_line = lines;
            min_trans = trans;
            best_path = path;
            best_trans = trans_node;
        }
        else if(min_step == step){
            if(trans < min_trans){
                min_trans = trans;
                best_line = lines;
                best_path = path;
                best_trans = trans_node;
            }
        }
        return;
    }
    vis[s] = true;
    path.emplace_back(s);
    for(auto &each:graph[s]){
        int back_up_line = pre_line;
        int cur_line = g[s][each];
        bool flag = false;
        if(pre_line != cur_line){
            flag = true;
            trans_node.emplace_back(s);
            lines.push_back(cur_line);
            pre_line = cur_line;
            trans++;
        }
        dfs(each, step+1,min_step,trans,min_trans,pre_line,lines);
        if(flag){
            lines.pop_back();
            trans--;
            pre_line = back_up_line;
            trans_node.pop_back();
        }
    }
    vis[s] = false;
    path.pop_back();
    
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&m,&start);
        for(int j=1;j<m;++j){
            scanf("%d",&next_station);
            g[start][next_station] = g[next_station][start] = i;
            graph[start].emplace_back(next_station);
            graph[next_station].emplace_back(start);
            start = next_station;
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        foot.clear();
        best_line.clear();
        fill(vis, vis+10000, false);
        scanf("%d%d",&start,&destination);
        int min_step = 10000;
        int min_trans = 10000;
        vector<int> lines;
        dfs(start, 0, min_step, 0, min_trans, -1, lines);
        printf("%d\n",min_step);
        for(int i=0;i<min_trans;++i){
            printf("Take Line#%d from %04d to ",best_line[i],best_trans[i]);
            if(i != min_trans-1)
                printf("%04d.\n",best_trans[i+1]);
            else
                printf("%04d.\n",destination);
        }
        
    }
}
