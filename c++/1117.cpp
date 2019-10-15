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
const int MAXN = 1e5+10;
int n;
int dis[MAXN];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&dis[i]);
    sort(dis+1, dis+n+1);
    int ans = 0;
    for(int i=1;i<=n;++i){
        if(dis[n-i+1] > i) ans = i;
    }
    printf("%d\n",ans);
}

