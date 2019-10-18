//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/18.
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
const int MAXN = 1010;
int n,m,k,num;
int indegree[MAXN]={0};
vector<int> g[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        indegree[b]++;
    }
    scanf("%d",&k);
    vector<int> ans;
    for(int i=0;i<k;++i){
        bool flag = true;
        int temp[MAXN];
        copy(indegree, indegree+n+1, temp);
        for(int j=0;j<n;++j){
            scanf("%d",&num);
            if(temp[num] != 0) flag = false;
            for(auto &to:g[num]){
                temp[to]--;
            }
        }
        if(!flag) ans.emplace_back(i);
    }
    printf("%d",ans[0]);
    for(int i=1;i<(int)ans.size();++i) printf(" %d",ans[i]);
}
