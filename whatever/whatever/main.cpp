//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/17.
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
const int MAXN = 1000;
int k,n;
int tree[MAXN];
bool used[MAXN] = {false};
void insert(int root,int val){
    if(root > MAXN) return;
    if(used[root] == false){
        used[root] = true;
        tree[root] = val;
        return;
    }
    if(abs(tree[root]) < abs(val)) insert(2*root+1, val);
    else insert(2*root, val);
}


void dfs(int root,int &black,vector<int> cur,bool &flag){
    if(!used[root]){ //叶子结点
        if(black == -1) black = (int)cur.size();
        if(black != cur.size()){
            flag = false;
            return;
        }
        return;
    }
    if(tree[root] > 0) cur.emplace_back(root);
    else{
        if(used[2*root] && tree[2*root] < 0) flag = false;
        if(used[2*root+1] && tree[2*root+1] < 0 ) flag = false;
        if(!flag) return;
    }
    dfs(2*root, black, cur, flag);
    dfs(2*root+1, black, cur, flag);
}

int main(){
    scanf("%d",&k);
    while (k--) {
        fill(used, used+MAXN, false);
        scanf("%d",&n);
        int cur;
        bool flag = true;
        for(int i=0;i<n;++i){
            scanf("%d",&cur);
            if(i==0 && cur < 0) flag = false;
            if(cur == 0) flag = false;
            insert(1, cur);
        }
        if(!flag) printf("No\n");
        else{
            vector<int> v;
            int black = -1;
            dfs(1, black, v, flag);
            if(!flag) printf("No\n");
            else printf("Yes\n");
        }
    }
}
