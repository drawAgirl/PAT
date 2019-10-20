//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/20.
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
const int MAXN = 1010;
int n;
int heap[MAXN];

void dfs(int root,vector<int> &cur){
    if(root > n) return;
    cur.emplace_back(heap[root]);
    if(2*root > n){
        for(int i=0;i<(int)cur.size();++i){
            printf("%d",cur[i]);
            if(i != cur.size()-1) printf(" ");
            else printf("\n");
        }
        cur.pop_back();
        return;
    }
    dfs(2*root+1,cur);
    dfs(2*root,cur);
    cur.pop_back();
    
}

bool isMax(){
    for(int i=1;i<=n/2;++i){
        if(heap[i] < heap[2*i]) return false;
        if(2*i+1 <=n && heap[i] < heap[2*i+1]) return false;
    }
    return true;
}

bool isMin(){
    for(int i=1;i<=n/2;++i){
        if(heap[i] > heap[2*i]) return false;
        if(2*i+1 <=n && heap[i] > heap[2*i+1]) return false;
    }
    return true;
}


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&heap[i]);
    vector<int> cur;
    dfs(1, cur);
    if(isMax()) printf("Max Heap\n");
    else if (isMin()) printf("Min Heap\n");
    else printf("Not Heap\n");
    
}

