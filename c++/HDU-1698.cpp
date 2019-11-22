//
//  main.cpp
//  simple
//
//  Created by 李寻欢 on 2019/10/24.
//  Copyright © 2019 李寻欢. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

const int MAXN = 1e5+10;
int tree[MAXN<<2];
int lazy[MAXN<<2];
int t,N,a,b,c,M;

void push_up(int root){
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

void push_down(int root,int L,int R){
    if(lazy[root]){
        int mid = (L+R)>>1;
        tree[root<<1] = lazy[root]*(mid-L+1);
        tree[root<<1|1] = lazy[root]*(R-mid);
        lazy[root<<1] = lazy[root];
        lazy[root<<1|1] = lazy[root];
        lazy[root] = 0;
    }
}

void build(int root,int L,int R){
    if(L == R){
        tree[root] = 1;
        return;
    }
    int mid = (L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    push_up(root);
}

void update(int root,int L,int R,int l,int r,int v){
    if(l>R || r < L) return;
    if(L>=l && R<=r){
        lazy[root] = v;
        tree[root] = v*(R-L+1);
        return;
    }
    int mid = (L+R)>>1;
    push_down(root, L, R);
    update(root<<1, L, mid, l, r, v);
    update(root<<1|1, mid+1, R, l, r, v);
    push_up(root);
}

int query(int root,int L,int R,int l,int r){
    if(l>R || r < L) return 0;
    if(L>=l && R<=r) return tree[root];
    int mid = (L+R)>>1;
    return query(root<<1, L, mid+1, l, r) + query(root<<1|1, mid+1, R, l, r);
}




int main(){
    scanf("%d",&t);
    for(int i=1;i<=t;++i){
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        scanf("%d%d",&N,&M);
        build(1, 1, N);
        for(int j=0;j<M;++j){
            scanf("%d%d%d",&a,&b,&c);
            update(1, 1, N, a, b, c);
        }
        printf("Case %d: The total value of the hook is %d.\n",i,tree[1]);
    }
}
