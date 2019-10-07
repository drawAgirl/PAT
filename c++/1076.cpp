//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/4.
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


int n,l,k,m,cur;
unordered_map<int, vector<int>> g;
bool vis[1010] = { false };
int main(){
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;++i){
        scanf("%d",&m);
        for(int j=0;j<m;++j){
            scanf("%d",&cur);
            g[cur].push_back(i);
        }
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        fill(vis, vis+1010, false);
        scanf("%d",&cur);
        queue<int> q;
        q.push(cur);
        int ans = -1; // 自己不算
        int cnt = 0;
        while (q.size() && cnt <=l) {
            cnt++;
            int size = (int)q.size();
            while (size--) {
                cur = q.front();
                q.pop();
                if(vis[cur]) continue;
                vis[cur] = true;
                ans++;
                for(auto &each:g[cur]) q.push(each);
            }
        }
        printf("%d\n",ans);
    }
}
