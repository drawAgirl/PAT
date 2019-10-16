//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/15.
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
const int MAXN = 40;
int n;
int Inorder[MAXN];
int Postorder[MAXN];

typedef struct node{
    int val;
    node* left;
    node* right;
    node(int x){
        val = x;
        left = right = NULL;
    }
}Node,*TreeNode;

TreeNode construct(int inL,int inR,int postL,int postR){
    if(inL > inR) return NULL;
    int k = -1;
    for(int i=inL;i<=inR;++i){
        if(Inorder[i] == Postorder[postR]){
            k = i;
            break;
        }
    }
    TreeNode root = new node(Postorder[postR]);
    int numleft = k-inL;
    root->left = construct(inL, inL+numleft-1, postL, postL+numleft-1);
    root->right = construct(k+1, inR, postL+numleft, postR-1);
    return root;
}

void level(TreeNode root){
    queue<TreeNode> q;
    q.push(root);
    int flag = -1;
    int space = 0;
    while (q.size()) {
        int size = (int)q.size();
        flag *= -1;
        vector<int> v;
        while (size--) {
            TreeNode cur = q.front();
            q.pop();
            v.emplace_back(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        if(flag == -1){
            for(int i=0;i<v.size();++i){
                printf("%d",v[i]);
                space++;
                if(space != n) printf(" ");
            }
        }else{
            for(int i=(int)v.size()-1;i>=0;--i){
                printf("%d",v[i]);
                space++;
                if(space != n) printf(" ");
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&Inorder[i]);
    for(int i=0;i<n;++i) scanf("%d",&Postorder[i]);
    TreeNode root = construct(0, n-1, 0, n-1);
    level(root);
}
