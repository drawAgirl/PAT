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
int n,k,son,w;
double p,r;
double ans = 0;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> weight;
void dfs(int root,int depth){
    if (graph.find(root) == graph.end()) { //找到叶子结点就算钱
        ans += p*pow(1+r, depth)*weight[root];
        return;
    }
    for(auto it:graph[root]) dfs(it, depth+1);
}
int main(){
    scanf("%d%lf%lf",&n,&p,&r);
    r /= 100;
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        if(k){
            for(int j=0;j<k;++j){
                scanf("%d",&son);
                graph[i].push_back(son);
            }
        }else{
            scanf("%d",&w);
            weight[i] = w;
        }
    }
    dfs(0, 0);
    printf("%.1f",ans);
}
