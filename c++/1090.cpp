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

int n,t;
int cnt = 1;
double ans = 0;
double p,r;
unordered_map<int, vector<int>> tree;
void dfs(int root,int depth){
    if(tree.find(root) == tree.end()){
        double cur = p*pow(1+r, depth);
        if(cur == ans) cnt++;
        else if (cur > ans){
            ans = cur;
            cnt = 1;
        }
        return;
    }
    for(auto each:tree[root]) dfs(each, depth+1);
}
int main(){
    int root = -1;
    scanf("%d%lf%lf",&n,&p,&r);
    r /= 100;
    for(int i=0;i<n;++i){
        scanf("%d",&t);
        if(t == -1) root=i;
        else tree[t].push_back(i);
    }
    dfs(root,0);
    printf("%.2f %d",ans,cnt);
}
