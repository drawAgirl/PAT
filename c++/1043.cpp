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


typedef struct node{
    int data;
    node* left;
    node* right;
}Node,*TreeNode;

int n,data;
vector<int> v;
vector<int> pre;
vector<int> pre_m;
vector<int> post;
TreeNode insert(TreeNode root,int data){
    if (!root) {
        root = new Node;
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
vector<int> v1;
void Preorder(TreeNode root){
    if(!root) return;
    pre.push_back(root->data);
    Preorder(root->left);
    Preorder(root->right);
}
int space = 0;
void Post(TreeNode root){
    if(!root) return;
    Post(root->left);
    Post(root->right);
    space++;
    printf("%d",root->data);
    if(space != n) printf(" ");
}

void Post_mirror(TreeNode root){
    if(!root) return;
    Post_mirror(root->right);
    Post_mirror(root->left);
    space++;
    printf("%d",root->data);
    if(space != n) printf(" ");
}

void Pre_mirror(TreeNode root){
    if(!root) return;
    pre_m.push_back(root->data);
    Pre_mirror(root->right);
    Pre_mirror(root->left);
}

int main(){
    scanf("%d",&n);
    TreeNode root = NULL;
    for(int i=0;i<n;++i){
        scanf("%d",&data);
        v.push_back(data);
        root = insert(root, data);
    }
    bool flag1 = true;
    Preorder(root);
    for(int i=0;i<n;++i){
        if(pre[i] != v[i]){
            flag1 = false;
            break;
        }
    }
    if(flag1){
        printf("YES\n");
        Post(root);
        return 0;
    }else{
        bool flag2 = true;
        Pre_mirror(root);
        for(int i=0;i<n;++i){
            if(pre_m[i] != v[i]){
                flag2 = false;
                break;
            }
        }
        if(flag2){
            printf("YES\n");
            Post_mirror(root);
        }else{
            printf("NO\n");
        }
    }
    
}
