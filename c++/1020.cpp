//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/25.
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

const int MAXN = 50;
int n;
int in[MAXN];
int post[MAXN];

typedef struct node{
    int data;
    node* left;
    node* right;
}Node,*TreeNode;




TreeNode build(int inL,int inR,int postL,int postR){
    if(inL > inR) return NULL;
    int k = 0;
    for (int i=inL; i<=inR; i++) {
        if(in[i] == post[postR]){
            k = i;
            break;
        }
    }
    int numleft = k-inL;
    TreeNode root = new Node;
    root->data = post[postR];
    root->left = build(inL, k-1, postL, postL+numleft-1);
    root->right = build(k+1, inR, postL+numleft, postR-1);
    return root;
}

void LevelOrder(TreeNode root){
    queue<TreeNode> q;
    q.push(root);
    while (q.size()) {
        int size = (int)q.size();
        while (size--) {
            n--;
            TreeNode temp = q.front();
            printf("%d",temp->data);
            if(n!=0) printf(" ");
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}






int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&post[i]);
    for(int i=0;i<n;++i) scanf("%d",&in[i]);
    TreeNode root = build(0, n-1, 0, n-1);
    LevelOrder(root);
}

