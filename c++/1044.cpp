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
const int MAXN = 1e5+10;
int n,m;
int diamonds[MAXN]={0};

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&diamonds[i]);
        diamonds[i] += diamonds[i-1];
    }
    int ans = MAXN;
    for(int i=1;i<=n;++i){
        int j = upper_bound(diamonds+i, diamonds+n+1, diamonds[i-1]+m) - begin(diamonds);
        if(diamonds[j-1] - diamonds[i-1] == m){
            ans = m;
            break;
        }
        if(j<=n && diamonds[j]-diamonds[i-1] < ans) ans = diamonds[j]-diamonds[i-1];
    }
    for(int i=1;i<=n;++i){
        int j = upper_bound(diamonds+i, diamonds+n+1, diamonds[i-1]+ans) - begin(diamonds);
        if(diamonds[j-1] - diamonds[i-1] == ans)
            printf("%d-%d\n",i,j-1);
    }
}
