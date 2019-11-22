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
const int MAXN = 2e5+10;
int lazy[MAXN<<2];
int tree[MAXN<<2];
int t,N,j,M;

void push_up(int root){
    tree[root] = max(tree[root<<1],tree[root<<1|1]);
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

void update(int root,int l,int r,int p, int v){
    if(l == r){
        tree[root] = v;
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
    int mid = (L+R) >> 1;
    return max(query(root<<1, L, mid, l, r),query(root<<1|1, mid+1, R, l, r));
}



int main(){
    while (~scanf("%d%d",&N,&M)) {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        build(1, 1, N);
        char word[2];
        int a,b;
        for(int i=0;i<M;++i){
            scanf("%s%d%d",word,&a,&b);
            if(word[0] == 'Q') printf("%d\n",query(1, 1, N, a, b));
            else update(1, 1, N, a, b);
        }
    }
}
