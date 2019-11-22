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
//#include <unordered_map>
//#include <unordered_set>
#include <cmath>
using namespace std;

const long long MAXN = 1e5+10;
long long tree[MAXN<<2];
long long lazy[MAXN<<2];
long long N,M;

void push_up(long long root){
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

void push_down(long long root,long long L,long long R){
    if(lazy[root]){
        long long mid = (L+R)>>1;
        tree[root<<1] += lazy[root]*(mid-L+1);
        tree[root<<1|1] += lazy[root]*(R-mid);
        lazy[root<<1] += lazy[root];
        lazy[root<<1|1] += lazy[root];
        lazy[root] = 0;
    }
}

void build(long long root,long long L,long long R){
    if(L == R){
        scanf("%lld",&tree[root]);
        return;
    }
    long long mid = (L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    push_up(root);
}


long long query(long long root,long long L,long long R,long long l,long long r){
    if(r < L || l > R) return 0;
    if(L>=l && R<=r) return tree[root];
    push_down(root, L,R);
    long long mid = (L+R)>>1;
    return query(root<<1, L, mid, l, r) + query(root<<1|1, mid+1, R, l, r);
}


void update(long long root,long long L,long long R,long long l,long long r,long long v){
    if(r<L || l > R) return;
    if(L>=l && R<=r){
        lazy[root] += v;
        tree[root] += v*(R-L+1);
        return;
    }
    push_down(root, L, R);
    long long mid = (L+R)>>1;
    update(root<<1, L, mid, l, r, v);
    update(root<<1|1, mid+1, R, l, r, v);
    push_up(root);
}

int main(){
    while (~scanf("%lld%lld",&N,&M)) {
        build(1, 1, N);
        char word[2];
        long long a,b,c;
        for(long long i=0;i<M;++i){
            scanf("%s",word);
            if(word[0] == 'Q'){
                scanf("%lld%lld",&a,&b);
                printf("%lld\n",query(1, 1, N, a, b));
            }else{
                scanf("%lld%lld%lld",&a,&b,&c);
                update(1, 1, N, a, b, c);
            }
        }
    }
}
