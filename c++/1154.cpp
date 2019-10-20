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


const int MAXN = 10010;
vector<int> G[MAXN];

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int times;
    scanf("%d",&times);
    while(times--){
        set<int> s;
        int color[n+1];
        for(int i=0;i<n;i++){
            scanf("%d",&color[i]);
            s.insert(color[i]);
        }
        bool flag = true;
        for(int i=0;i<n;i++){
            for(int j=0;j<G[i].size();j++){
                if(color[i] == color[G[i][j]]){
                    printf("No\n");
                    flag = false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(!flag)   continue;
        printf("%d-coloring\n",(int)s.size() );
    }
}
