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

const int MAXN = 12;
int n,t;

int to_int(string s){
    int ans = 0;
    for(int i=0;i<(int)s.size();++i) ans = ans*10 + s[i]-'0';
    return ans;
}
int lchild[MAXN];
int rchild[MAXN];
bool flag[MAXN] = {false};


void level(int root){
    queue<int> q;
    q.push(root);
    int space = 0;
    while (q.size()) {
        int size = (int)q.size();
        while (size--) {
            space++;
            int temp = q.front();
            printf("%d",temp);
            if(space != n) printf(" ");
            q.pop();
            if(lchild[temp] != -1) q.push(lchild[temp]);
            if(rchild[temp] != -1) q.push(rchild[temp]);
        }
    }
    printf("\n");
}

int space = 0;
void Inorder(int root){
    if(root == -1) return;
    Inorder(lchild[root]);
    printf("%d",root);
    space++;
    if(space != n) printf(" ");
    Inorder(rchild[root]);
}

int main(){
    memset(lchild, -1, sizeof(lchild));
    memset(rchild, -1, sizeof(rchild));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string a,b;
    for(int i=0;i<n;++i){
        cin >> a >> b;
        if (a[0] != '-'){
            t = to_int(a);
            rchild[i] = t; // 注意是翻转二叉树
            flag[t] = true;
        }
        if (b[0] != '-'){
            t = to_int(b);
            lchild[i] = t;
            flag[t] = true;
        }
    }
    int root = -1;
    for(int i=0;i<n;++i){
        if (flag[i] == false){
            root = i;
            break;
        }
    }
    level(root);
    Inorder(root);
    
}
