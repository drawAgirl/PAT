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


int n;
stack<int> s;
vector<int> in;
vector<int> pre;
int to_int(string s){
    int ans= 0;
    for (int i=5; i<(int)s.size(); ++i) {
        ans = ans*10 + s[i]-'0';
    }
    return ans;
}

typedef struct node{
    int data;
    node* left;
    node* right;
}Node,*TreeNode;


TreeNode build(int inL,int inR,int preL,int preR){
    if(inL > inR) return NULL;
    int k = 0;
    for(int i=preL;i<=preR;++i){
        if(in[inL] == pre[i]){
            k = i;
            break;
        }
    }
    int numleft = k-preL;
    TreeNode root = new Node;
    root->data = in[inL];
    root->left = build(inL+1, inL+numleft, preL, preL+numleft-1);
    root->right = build(inL+numleft+1, inR, preL+numleft+1, preR);
    return root;
}


void Post(TreeNode root){
    if(!root) return;
    Post(root->left);
    Post(root->right);
    printf("%d",root->data);
    if(--n) printf(" ");
}

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    scanf("%d",&n);
    scanf("%*c");
    for (int i=0; i<2*n; ++i) {
        string t;
        getline(cin,t);
        if(t[1] == 'u'){
            int num = to_int(t);
            s.push(num);
            
            in.push_back(num);
        }else{
            pre.push_back(s.top());
            s.pop();
        }
    }
    TreeNode root = build(0, n-1, 0, n-1);
    Post(root);
}
