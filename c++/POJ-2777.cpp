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

const int MAXN = 1e5+100;
int L,T,O;
int ans;
int tree[MAXN<<2];
int lazy[MAXN<<2];
int color[40];

inline void push_down(int root,int L,int R){
    if(lazy[root]){
        lazy[root<<1] = lazy[root];
        lazy[root<<1|1] = lazy[root];
        tree[root<<1]  = lazy[root];
        tree[root<<1|1] = lazy[root];
        lazy[root] = 0;
    }
}

inline void update_range(int root,int L,int R,int l,int r,int c){
    if(L>r || R<l) return;
    if(L>=l && R<=r){
        tree[root] = c;
        lazy[root] = c;
        return;
    }
    push_down(root, L, R);
    int mid = L+R>>1;
    if(mid>=l)update_range(root<<1, L, mid, l, r, c);
    if(mid<r)update_range(root<<1|1, mid+1, R, l, r, c);
    if(tree[root<<1] == tree[root<<1|1]) tree[root] = tree[root<<1];
    else tree[root] = -1;
}

inline void query(int root,int L,int R,int l,int r){
    if(L>r || R<l) return;
    if(L>=l && R<=r){
        if(tree[root] == 0) return;
        if(tree[root] == -1){
            push_down(root, L, R);
            int mid = L+R>>1;
            if(mid>=l)query(root<<1, L, mid, l, r);
            if(mid<r)query(root<<1|1, mid+1, R, l, r);
        }else{
            if(color[tree[root]]==0){
                color[tree[root]] = 1;
                ans++;
            }
        }
        return;
    }
    push_down(root, L, R);
    int mid = L+R>>1;
    if(mid>=l)query(root<<1, L, mid, l, r);
    if(mid<r)query(root<<1|1, mid+1, R, l, r);
}





int main(){
    while (~scanf("%d%d%d",&L,&T,&O)) {
        fill(tree, tree+MAXN, 1);
        fill(lazy, lazy+MAXN, 1); // 这里先设为0就wa了
        char word[2];
        int a,b,c;
        for(int i=0;i<O;++i){
            scanf("%s",word);
            if(word[0] == 'C'){
                scanf("%d%d%d",&a,&b,&c);
                if(a>b) swap(a, b);
                update_range(1, 1, L, a, b, c);
            }else{
                fill(color, color+40, 0);
                ans = 0;
                scanf("%d%d",&a,&b);
                if(a>b) swap(a, b);
                query(1, 1, L, a, b);
                printf("%d\n",ans);
            }
        }
    }
}
