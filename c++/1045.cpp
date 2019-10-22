//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/22.
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
int want[MAXN];
int color[10010];
int dp[MAXN][10010]={0};
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i) scanf("%d",&want[i]);
    scanf("%d",&k);
    for(int i=1;i<=k;++i) scanf("%d",&color[i]);
    for(int i=1;i<=m;++i){
        for(int j=1;j<=k;++j){
            int MAX = max(dp[i-1][j],dp[i][j-1]);
            if(want[i] == color[j]) dp[i][j] = MAX+1;
            else dp[i][j] = MAX;
        }
    }
    printf("%d\n",dp[m][k]);
    
    
}
