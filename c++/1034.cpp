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
const int MAXN = 2010;
unordered_map<string, int> string_to_int;
unordered_map<int, string> int_to_string;
int idx = 0;
int n,k;
bool vis[MAXN] = { false };
int Time[MAXN];
int head[MAXN];
typedef pair<int, int> pp;
unordered_map<int, vector<pp>> g;
int cur = 0;
vector<int> gang[MAXN];
vector<int> ans;
set<pair<string, int>> name;
void dfs(int s,int &i){
    if(vis[s]) return;
    gang[i].push_back(s);
    vis[s] = true;
    for(auto each:g[s]){
        int to = each.first;
        int t = each.second;
        cur += t;
        Time[s] += t;
        Time[to] += t;
        dfs(to,i);
    }
}


int main(){
    fill(head, head+MAXN, -1);
    fill(Time, Time+MAXN, 0);
    scanf("%d%d",&n,&k);
    for (int i=0; i<n; ++i) {
        string a,b;
        int t;
        cin >> a >> b >> t;
        if(string_to_int.find(a) == string_to_int.end()){
            int_to_string[idx] = a;
            string_to_int[a] = idx++;
        }
        if(string_to_int.find(b) == string_to_int.end()){
            int_to_string[idx] = b;
            string_to_int[b] = idx++;
        }
        g[string_to_int[a]].push_back({string_to_int[b],t});
    }
    for(int i=0;i<idx;++i){
        if(vis[i] == false){
            cur = 0;
            dfs(i,i);
            if(cur > k && gang[i].size() > 2){
                ans.push_back(i);
            }
        }
    }
    printf("%d\n",(int)ans.size());
    for(auto &each:ans){
        cur = 0;
        int who = -1;
        for(auto &every:gang[each]){
            if(Time[every] > cur){
                cur = Time[every];
                who =  every;
            }
        }
        name.insert({int_to_string[who],(int)gang[each].size()});
    }
    for(auto &each:name){
        cout << each.first << " " << each.second << "\n";
    }
    
}
