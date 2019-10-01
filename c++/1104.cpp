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

int n,m,t,k,son;
int arr[110];
unordered_map<int, vector<int>> tree;
vector<int> level;
int max_depth = 0;
void dfs(int root,int depth){
    max_depth = max(max_depth,depth);
    if(tree.find(root) == tree.end()){
        arr[depth]++;
        return;
    }
    for(auto each:tree[root]) dfs(each, depth+1);
}

int main(){
    memset(arr, 0, sizeof(arr));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&t,&k);
        while (k--) {
            scanf("%d",&son);
            tree[t].push_back(son);
        }
    }
    dfs(1,1);
    printf("%d",arr[1]);
    for(int i=2;i<=max_depth;++i) printf(" %d",arr[i]);
}


// 下面是 bfs版本 Python版本用了bfs

//    queue<vector<int>> q;
//    q.push(g[1]);
//    while(!q.empty()){
//        int size = (int)q.size();
//        while (size--) {
//            vector<int> first = q.front();
//            q.pop();
//            for(int i=0;i<first.size();i++){
//
//            }
//        }
//    }