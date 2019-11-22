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

const int MAXN = 5e4+10;
int lazy[MAXN<<2];
int tree[MAXN<<2];
int t,N,j;

void push_up(int root){
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

void build(int root,int l,int r){
    if(l == r) scanf("%d",&tree[root]);
    else{
        int mid = ((r-l)>>1) + l;
        build(root<<1, l, mid);
        build(root<<1|1, mid+1, r);
        push_up(root);
    }
}


void push_down(int root,int l,int r){
    if(lazy[root]){
        int mid = (l+r)>>1;
        tree[root<<1] += lazy[root]*(mid-l+1);
        tree[root<<1|1] += lazy[root]*(r-mid);
        lazy[root<<1] += lazy[root];
        lazy[root<<1|1] += lazy[root];
        lazy[root] = 0;
    }
}

void update(int root,int l,int r,int p, int v){
    if(l == r){
        tree[root] += v;
        return;
    }
    int mid = (l+r)>>1;
    if(p <= mid) update(root<<1, l, mid, p, v);
    else update(root<<1|1, mid+1, r, p, v);
    push_up(root);
}

int query(int root,int L,int R,int l,int r){
    if(R < l || r < L) return 0;
    if(L>=l && R <= r) return tree[root];
    push_down(root, L, R);
    int mid = (L+R) >> 1;
    return query(root<<1, L, mid, l, r) + query(root<<1|1, mid+1, R, l, r);
}



int main(){
    scanf("%d",&t);
    char word[6];
    int a,b;
    for(int i=1;i<=t;++i){
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        scanf("%d",&N);
        build(1, 1, N);
        printf("Case %d:\n",i);
        while (scanf("%s",word)) {
            if(word[0] == 'E') break;
            scanf("%d%d",&a,&b);
            if(word[0] == 'Q'){
                printf("%d\n",query(1, 1, N, a, b));
            }else if(word[0] == 'A')
                update(1, 1, N, a, b);
            else
                update(1, 1, N, a, -b);
        }
    }
}
