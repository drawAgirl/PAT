//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/19.
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

const int MAXN = 10010;
int n,m;
int pre[MAXN];
int in[MAXN];
unordered_map<int, bool> mp;
typedef struct node{
    int data;
    node *left,*right;
}Node,*TreeNode;

TreeNode Construct(int inL,int inR,int preL,int preR){
    if(preL > preR)
        return NULL;
    int k = -1;
    TreeNode root = new Node;
    root->data = pre[preL];
    for(int i=inL;i<=inR;i++){
        if(pre[preL] == in[i]){
            k = i;
            break;
        }
    }
    int numLeft = k - inL;
    root->left = Construct(inL, k-1, preL+1, preL+numLeft);
    root->right = Construct(k+1, inR, preL+numLeft+1, preR);
    return root;
}


TreeNode insert(TreeNode root,int data){
    if(!root){
        TreeNode temp = new Node;
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(root->data < data)
        root->right = insert(root->right, data);
    if(root->data > data)
        root->left = insert(root->left, data);
    return root;
}

TreeNode lca(TreeNode root,int a,int b){
    if(!root)
        return NULL;
    if(root->data ==a || root->data == b)
        return root;
    TreeNode left = lca(root->left,a,b);
    TreeNode right = lca(root->right,a,b);
    if(left && right)
        return root;
    return left != NULL ?left : right;
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
        mp[in[i]] = true;
    }
    for(int i=0;i<n;i++)
        scanf("%d",&pre[i]);
    TreeNode root = NULL;
    root = Construct(0, n-1, 0, n-1);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(mp[a] == false && mp[b] == false){
            printf("ERROR: %d and %d are not found.\n",a,b);
        }else if(mp[a] == false && mp[b] == true)
            printf("ERROR: %d is not found.\n",a);
        else if(mp[a] == true && mp[b] == false)
            printf("ERROR: %d is not found.\n",b);
        else{
            TreeNode ans = lca(root,a,b);
            if(ans->data == a){
                printf("%d is an ancestor of %d.\n",a,b);
            }else if(ans->data == b)
                printf("%d is an ancestor of %d.\n",b,a);
            else
                printf("LCA of %d and %d is %d.\n",a,b,ans->data);
        }
        
    }
}

