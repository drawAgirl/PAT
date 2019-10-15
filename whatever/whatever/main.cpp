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
const int MAXN = 1e4+10;
int n;
typedef struct node{
    int val;
    node* left;
    node* right;
}Node,*TreeNode;

TreeNode insert(TreeNode root,int val){
    if(!root){
        root = new Node;
        root->val = val;
        root->left = root->right = NULL;
        return root;
    }
    if(val > root->val) root->right = insert(root->right, val);
    else root->left = insert(root->left, val);
    return root;
}

int main(){
    scanf("%d",&n);
    int val;
    TreeNode root = NULL;
    for(int i=0;i<n;++i){
        scanf("%d",&val);
        root = insert(root, val);
    }
    queue<TreeNode> q;
    q.push(root);
    int level[MAXN] = {0};
    int idx=0;
    while (!q.empty()) {
        int size = (int)q.size();
        level[idx++] = size;
        while (size--) {
            TreeNode cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    printf("%d + %d = %d",level[idx-1],level[idx-2],level[idx-1]+level[idx-2]);
}
