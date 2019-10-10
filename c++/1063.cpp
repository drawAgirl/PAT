//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/8.
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
set<int> s[51];

int main(){
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        int m;
        scanf("%d",&m);
        for (int j=0; j<m; j++) {
            int val;
            scanf("%d",&val);
            s[i].insert(val);
        }
    }
    int k;
    scanf("%d",&k);
    for (int i=0; i<k; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        double common = 0;
        int size = s[b].size();
        for (auto it = s[a].begin(); it != s[a].end(); it++) {
            if (s[b].find(*it) != s[b].end()) {
                common++;
            }else
                size++;
        }
        printf("%.1lf%%\n",common/size*100);
    }
    return 0;
}
