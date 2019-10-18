//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/17.
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

const int MAXN = 5e4+10;
int N;
int pre[MAXN];
int in[MAXN];
vector<int> post;
int search(int *arr, int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x) 
            return i;
    return -1;
}
// 这里抄的是geeks的 时间复杂度n 就拿来用了
// Prints postorder traversal from given inorder and preorder traversals
void printPostOrder(int *in, int *pre, int n)
{
    if(post.size()) return;
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    int root = search(in, pre[0], n);
    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPostOrder(in, pre + 1, root);
    // If right subtree is not empty, print right subtree
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
    // Print root
//    cout << pre[0] << " ";
    post.emplace_back(pre[0]);
}


int main(){
    scanf("%d",&N);
    for(int i=0;i<N;++i) scanf("%d",&pre[i]);
    for(int i=0;i<N;++i) scanf("%d",&in[i]);
    printPostOrder(in, pre, N);
    printf("%d\n",post[0]);
}
