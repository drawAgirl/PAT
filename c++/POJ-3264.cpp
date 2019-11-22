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

const int MAXN = 5e4+10;

int N,Q;
int x,y;
struct node{
    int val;
    int MAX,MIN;
    int left,right;
}Node[MAXN<<2];


void push_up(int root){
    Node[root].MAX = max(Node[root<<1].MAX,Node[root<<1|1].MAX);
    Node[root].MIN = min(Node[root<<1].MIN,Node[root<<1|1].MIN);
}

void build(int root,int L,int R){
    Node[root].left = L;
    Node[root].right = R;
    Node[root].MAX = 0;
    Node[root].MIN = 0x3f3f3f3f;
    if(L == R){
        scanf("%d",&Node[root].MAX);
        Node[root].MIN = Node[root].MAX;
        return;
    }
    int mid = (L+R)>>1;
    build(root<<1, L, mid);
    build(root<<1|1, mid+1, R);
    push_up(root);
}

void query(int root,int l,int r){
    if(Node[root].left > r || Node[root].right < l) return;
    if(Node[root].left == l && Node[root].right == r){
        x = max(x,Node[root].MAX);
        y = min(y,Node[root].MIN);
        return;
    }
    int mid = (Node[root].left + Node[root].right) >> 1;
    if(r<=mid) query(root<<1, l, r);
    else if(l>mid) query(root<<1|1, l, r);
    else{
        query(root<<1, l, mid);
        query(root<<1|1, mid+1, r);
    }
}


int main(){
    while (~scanf("%d%d",&N,&Q)) {
        build(1, 1, N);
        int a,b;
        while(Q--){
            x = 0;
            y = 0x3f3f3f3f;
            scanf("%d%d",&a,&b);
            if(a>b) swap(a, b);
            if(a==b) printf("0\n");
            else{
                query(1, a, b);
                printf("%d\n",x-y);
            }
        }
        
    }
}
