//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/27.
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

typedef struct node{
    int data;
    int hegiht;
    node* left;
    node* right;
    node(int num){
        data = num;
        hegiht = 1;
        left = right = NULL;
    }
}Node,*TreeNode;
int getHeight(TreeNode root){
    if (!root) return 0;
    return root->hegiht;
}
int getBalanceFactor(TreeNode root){
    return getHeight(root->left) -getHeight(root->right);
}
void updateHeight(TreeNode root){
    root->hegiht = max(getHeight(root->left), getHeight(root->right))+1;
}

void L(TreeNode &root){
    TreeNode temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
void R(TreeNode &root){
    TreeNode temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(TreeNode &root,int data){
    if(!root){
        root = new Node(data);
        return;
    }
    if(data < root->data){
        insert(root->left, data);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if (getBalanceFactor(root->left) == 1) {
                R(root);
            }else if(getBalanceFactor(root->left) == -1){
                L(root->left);
                R(root);
            }
        }
    }else{
        insert(root->right, data);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if (getBalanceFactor(root->right) == -1) {
                L(root);
            }else if(getBalanceFactor(root->right) == 1){
                R(root->right);
                L(root);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    TreeNode root = NULL;
    for(int i=0;i<n;++i){
        int t;
        scanf("%d",&t);
        insert(root, t);
//        printf("%d ",root->data);
    }
    printf("%d\n",root->data);
}
