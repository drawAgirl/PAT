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
#include <cmath>
//#include <unordered_map>
//#include <unordered_set>
#include <cmath>
using namespace std;
// 注意b<c的情况 还有每次结束的时候要多输出一个\n 
const long long MAXN = 2e5+10;
long long tree[MAXN<<2];
long long lazy[MAXN<<2];
long long N,M;

inline void push_up(long long root){
    tree[root] = tree[root<<1] + tree[root<<1|1];
}

inline void build(long long root,long long L,long long R){
    if(L==R){
        scanf("%lld",&tree[root]);
        return;
    }
    long long mid = (L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    push_up(root);
}

inline void update(long long root,long long L,long long R,long long l,long long r){
    if(tree[root] == R-L+1) return; // 因为到后面该区域内数字都是1了 所以就不操作直接返回
//    if(L>r || R <l) return;
    if(L==R){
        tree[root] = (long long)(sqrt(tree[root]));
        return;
    }
    long long mid = (L+R)>>1;
    if(l<=mid)update(root<<1, L, mid, l, r);
    if(r>mid)update(root<<1|1, mid+1, R, l, r);
    push_up(root);
}

inline long long query(long long root,long long L,long long R,long long l,long long r){
    if(L>r || R<l) return 0;
    if(L>=l && R<=r) return tree[root];
    long long mid = (L+R)>>1;
    return query(root<<1, L, mid, l, r) + query(root<<1|1, mid+1, R, l, r);
}


int main(){
    long long cases = 1;
    while (~scanf("%lld",&N)) {
        printf("Case #%lld:\n",cases++);
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        build(1, 1, N);
        scanf("%lld",&M);
        long long a,b,c;
        while (M--) {
            scanf("%lld%lld%lld",&a,&b,&c);
            if(b>c) swap(b, c);
            if(a==0){
                update(1, 1, N, b, c);
            }else{
                printf("%lld\n",query(1, 1, N, b, c));
            }
        }
    }
    printf("\n");
}
