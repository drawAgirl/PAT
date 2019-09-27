//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/27.
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
using namespace std;

const int MAXN = 1e3+10;
int n,k,a;
int father[MAXN];
int course[MAXN];
int root[MAXN];

int findfather(int x){
    int a = x;
    while (x != father[x]) {
        x = father[x];
    }
    while (a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a,int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa != fb) father[fa] = fb;
}

void init(int n){
    for(int i=1;i<=n;++i) father[i] = i;
}

bool cmp(int &a,int &b){
    return a>b;
}
int main(){
    scanf("%d",&n);
    memset(course, 0, sizeof(course));
    memset(root, 0, sizeof(root));
    init(n);
    for(int i=1;i<=n;++i){
        scanf("%d:",&k);
        for(int j=0;j<k;++j){
            scanf("%d",&a);
            if(course[a] == 0){
                course[a] = i;
            }
            Union(i, course[a]);
        }
    }
    for(int i=1;i<=n;++i) root[findfather(i)]++;
    sort(root, root+MAXN, cmp);
    int cnt = 0;
    for(int i=0;i<=n;++i){
        if(root[i] == 0) break;
        cnt++;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;++i){
        printf("%d",root[i]);
        if(i != cnt-1) printf(" ");
    }
    
}
