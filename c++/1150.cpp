//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/19.
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
const int INF = 0x3f3f3f3f;
const int MAXN = 210;
int n,m,k,t,city;
int g[MAXN][MAXN];
int path;
int short_distance = INF;
int main(){
    scanf("%d%d",&n,&m);
    int a,b,c;
    fill(g[0], g[0]+MAXN*MAXN,INF);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&a,&b,&c);
        g[a][b] = g[b][a] = c;
    }
    scanf("%d",&k);
    for(int i=1;i<=k;++i){
        scanf("%d%d",&t,&city);
        vector<int> v;
        int pre_city = city;
        int distance = 0;
        bool isValid = true;
        int vis[MAXN] = {0};
        for(int j=1;j<t;++j){
            scanf("%d",&city);
            if(g[pre_city][city] == INF) isValid = false;
            else distance += g[pre_city][city];
            vis[city]++;
            pre_city = city;
        }
        if(isValid) printf("Path %d: %d ",i,distance);
        else printf("Path %d: NA ",i);
        bool isCycle = true;
        bool isSimple = true;
        for(int i=1;i<=n;++i){
            if(vis[i] == 0){
                isCycle = false;
                break;
            }
            if(vis[i] > 1) isSimple = false;
        }
        if(!isCycle || !isValid) printf("(Not a TS cycle)\n");
        else if (!isSimple){
            if(short_distance > distance){
                short_distance = distance;
                path = i;
            }
            printf("(TS cycle)\n");
        }
        else{
            if(short_distance > distance){
                short_distance = distance;
                path = i;
            }
            printf("(TS simple cycle)\n");
        }
    }
    printf("Shortest Dist(%d) = %d\n",path,short_distance);
    
    
}
