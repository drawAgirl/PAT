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

const int MAXN = 210;
int n,m,querys,k;
bool g[MAXN][MAXN] = {false};
int main(){
    // freopen("/Users/zhengqiteng/Downloads/code/in.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        g[a][b] = g[b][a] = true;
    }
    scanf("%d",&querys);
    while (querys--) {
        bool vis[MAXN] = {false};
        scanf("%d",&k);
        vector<int> v(k);
        for(int i=0;i<k;++i){
            scanf("%d",&v[i]);
            vis[v[i]] = true;
        }
//        if(k==1){
//            printf("Yes\n");
//            continue;
//        }
        bool flag = true;
        for(int i=0;i<k-1 && flag;++i){
            for(int j=i+1;j<k;++j){
                if(g[v[i]][v[j]] == false){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag) printf("Not a Clique\n");
        else{
            bool flag2 = true;
            for(int i=1;i<=n;++i){
                if(vis[i]) continue;
                bool flag3 = false;
                for(auto &each:v){
                    if(g[each][i] == false) break;
                    if(each == v[v.size()-1]) flag3 = true;
                }
                if(flag3){
                    flag2 = false;
                    break;
                }
            }
            if(!flag2) printf("Not Maximal\n");
            else printf("Yes\n");
        }
    }
}
