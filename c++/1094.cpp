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
int n,m,t,k,son; // root = 1
unordered_map<int, vector<int>> tree;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i){
        scanf("%d%d",&t,&k);
        while (k--) {
            scanf("%d",&son);
            tree[t].push_back(son);
        }
    }
    queue<int> q;
    q.push(1);
    int ans = 0;
    int level = 1;
    int cnt = 0;
    while (q.size()) {
        cnt++;
        int size = (int)q.size();
        if (size > ans){
            ans = size;
            level = cnt;
        }
        while (size--) {
            int temp = q.front();
            q.pop();
            for(auto son:tree[temp]){
                q.push(son);
            }
        }
    }
    printf("%d %d",ans,level);
}
