//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/26.
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

const int MAXN = 110;
unordered_map<int, vector<int>> tree;
int n,lchild,rchild;
int data[MAXN];
int ind = 0;


void Inorder(int root){
    if(tree[root][0] != -1) Inorder(tree[root][0]);
    tree[root].push_back(data[ind++]);
    if(tree[root][1] != -1) Inorder(tree[root][1]);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&lchild,&rchild);
        tree[i].push_back(lchild);
        tree[i].push_back(rchild);
    }
    for(int i=0;i<n;++i) scanf("%d",&data[i]);
    sort(data, data+n);
    Inorder(0);
    queue<int> q;
    q.push(0);
    int space = 0;
    while (q.size()) {
        int size = (int)q.size();
        while (size--) {
            int t = q.front();
            q.pop();
            space++;
            printf("%d",tree[t][2]);
            if(space != n) printf(" ");
            if(tree[t][0] != -1) q.push(tree[t][0]);
            if(tree[t][1] != -1) q.push(tree[t][1]);
        }
    }
}
