//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/26.
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

const int MAXN = 110;
int n,m,s,t,k,son;
int weight[MAXN];
vector<int> child[MAXN];
int root = 0;
vector<int> cur;
vector<vector<int>> ans;

bool cmp(vector<int> &a,vector<int> &b){
    int len = (int)min(a.size(), b.size());
    for(int i=0;i<len;++i){
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return a.size() > b.size();
}

void dfs(int root,int sum){

    if(child[root].size() == 0 && sum-weight[root] == 0){
        cur.push_back(weight[root]);
        ans.push_back(cur);
        cur.pop_back();
    }

    for(auto it:child[root]){
        cur.push_back(weight[root]);
        dfs(it,sum-weight[root]);
        cur.pop_back();
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<n;++i) scanf("%d",&weight[i]);
    for(int i=0;i<m;++i){
        scanf("%d%d",&t,&k);
        for(int j=0;j<k;++j){
            scanf("%d",&son);
            child[t].push_back(son);
        }
    }
//    cur.push_back(weight[root]);
    dfs(root,s);
    sort(ans.begin(), ans.end(), cmp);
    for(auto each:ans){
        for(int i=0;i<each.size();++i){
            printf("%d",each[i]);
            if(i != each.size()-1) printf(" ");
        }
        printf("\n");
    }
}
