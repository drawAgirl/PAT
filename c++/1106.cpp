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

int n,k,t;
double p,r; //root = 0
unordered_map<int, vector<int>> tree;
int min_depth = 0x7f7f7f7f;
int cnt = 1;
void dfs(int root,int depth){
    if(tree.find(root) == tree.end()){
        if(min_depth > depth){
            min_depth = depth;
            cnt = 1;
        }
        else if(min_depth == depth) cnt++;
        return;
    }
    for(auto each:tree[root]) dfs(each, depth+1);
}

int main(){
    scanf("%d%lf%lf",&n,&p,&r);
    r /= 100;
    for(int i=0;i<n;++i){
        scanf("%d",&k);
        while (k--) {
            scanf("%d",&t);
            tree[i].push_back(t);
        }
    }
    dfs(0, 0);
    printf("%.4f %d",p*pow(1+r, min_depth),cnt);
}
