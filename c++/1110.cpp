//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/13.
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
#include <deque>
using namespace std;
const int MAXN = 50;
int n;
struct node{
    int l,r;
    node(){
        l=r=-1;
    }
}tree[MAXN];

bool vis[MAXN] ={false};
int to_int(string s){
    if(s=="-") return -1;
    int ans =0;
    for(int i=0;i<(int)s.size();++i) ans = ans*10 + s[i]-'0';
    return ans;
}
int last = -1;
int max_depth = -1;
int arr[MAXN];
void dfs(int index,int root){
    if(index > n) return;
    arr[index] = root;
    dfs(2*index, tree[root].l);
    dfs(2*index+1,tree[root].r);
}
int main(){
    scanf("%d%*c",&n);
    string a,b;
    int root = -1;
    for(int i=0;i<n;++i){
        cin >> a >> b;
        tree[i].l = to_int(a);
        tree[i].r = to_int(b);
        vis[tree[i].l] = true;
        vis[tree[i].r] = true;
    }
    for(int i=0;i<n;++i){
        if(vis[i] == false){
            root = i;
            break;
        }
    }
    dfs(1, root);
    bool flag = true;
    for(int i=1;i<=n;++i){
        if(arr[i] == -1){
            flag = false;
            break;
        }
        last = arr[i];
    }
    if(flag) printf("YES %d",last);
    else printf("NO %d",root);
}
