//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/16.
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

const int MAXN = 50;
int n;
char tree[MAXN];
bool isRoot[MAXN]={false};
int ROOT = -1;
struct node{
    char c[11];
    int left,right;
};

vector<node> v;


void dfs(int root){
    if(root == -1) return;
    bool flag = false;
    if(root != ROOT &&(v[root].left!=-1 || v[root].right!=-1)){
        flag = true;
        printf("(");
    }
    dfs(v[root].left);
    printf("%s",v[root].c);
    dfs(v[root].right);
    if(flag) printf(")");
}


int main(){
    scanf("%d",&n);
    v.resize(n+1);
    for (int i=1; i<=n; ++i) {
        scanf("%s%d%d",v[i].c,&v[i].left,&v[i].right);
        if(v[i].left != -1) isRoot[v[i].left] = true;
        if(v[i].right != -1) isRoot[v[i].right] = true;
    }
    for(int i=1;i<=n;++i){
        if(isRoot[i] == false){
            ROOT = i;
            break;
        }
    }
    dfs(ROOT);
}
