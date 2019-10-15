//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/15.
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

const int MAXN = 210;
int n,m,k;
bool g[MAXN][MAXN];

int main(){
    fill(g[0], g[0]+MAXN*MAXN, false);
    scanf("%d%d",&n,&m);
    int a,b;
    for (int i=0; i<m; ++i) {
        scanf("%d%d",&a,&b);
        g[a][b] = g[b][a] = true;
    }
    int querys;
    scanf("%d",&querys);
    for(int i=0;i<querys;++i){
        scanf("%d",&k);
        vector<int> v(k);
        set<int> s;
        for(int j=0;j<k;++j){
            scanf("%d",&v[j]);
            s.insert(v[j]);
        }
        if(s.size() != n || k-1 != n || v[0]!=v[k-1]) printf("NO\n");
        else{
            bool flag = true;
            for(int j=0;j<n;++j){
                if(g[v[j]][v[j+1]] == false){
                    printf("NO\n");
                    flag = false;
                    break;
                }
            }
            if(flag)
                printf("YES\n");
        }
        
    }
    
}
