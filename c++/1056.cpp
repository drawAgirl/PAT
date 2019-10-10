//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/7.
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
const int MAXN = 1e3+10;
int n,g;
int weight[MAXN];
int ans[MAXN] = {0};
int main(){
    scanf("%d%d",&n,&g);
    queue<int> q;
    queue<int> other;
    for(int i=0;i<n;++i) scanf("%d",&weight[i]);
    for(int i=0;i<n;++i){
        int t;
        scanf("%d",&t);
        q.push(t);
    }
    while (q.size() != 1) {
        int cur;
        int now_max=-1,now_idx = -1;
        int times = (int)q.size() / g;
        int rest = (int)q.size() % g;
        int rank = times+1;
        if(rest) rank++;
        while (times--) {
            for(int i=0;i<g;++i){
                cur = q.front();
                q.pop();
                other.push(cur);
                if(weight[cur] > now_max){
                    now_max = weight[cur];
                    now_idx = cur;
                }
            }
            q.push(now_idx);
            while (other.size()) {
                cur = other.front();
                other.pop();
                if(cur == now_idx) continue;
                ans[cur] = rank;
            }
            now_max = now_idx = -1;
        }
        if(rest != 0){ // 这里去掉就超时了
            while (rest--) {
                cur = q.front();
                q.pop();
                other.push(cur);
                if(weight[cur] > now_max){
                    now_max = weight[cur];
                    now_idx = cur;
                }
            }
            q.push(now_idx);
            while (other.size()) {
                cur = other.front();
                other.pop();
                if(cur == now_idx) continue;
                ans[cur] = rank;
            }
        }
    }
    ans[q.front()] = 1;
    for(int i=0;i<n;++i){
        printf("%d",ans[i]);
        if(i != n-1) printf(" ");
    }
}
