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

const int MAXN = 10010;
vector<int> G[MAXN];


int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(i);
        G[b].push_back(i);
    }
    int times;
    scanf("%d",&times);
    while(times--){
        set<int> s;
        int k;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            int v;
            scanf("%d",&v);
            for(int j=0;j<G[v].size();j++){
                s.insert(G[v][j]);
            }
        }
        if(s.size() == m) printf("Yes\n");
        else printf("No\n");
    }
}
