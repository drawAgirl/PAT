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
//抄的liuchuo大佬
//再贴一个O(n)复杂度的

//int preIndex = 0, posIndex = 0;
//TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//    TreeNode* root = new TreeNode(pre[preIndex++]);
//    if (root->val != post[posIndex])
//        root->left = constructFromPrePost(pre, post);
//    if (root->val != post[posIndex])
//        root->right = constructFromPrePost(pre, post);
//    posIndex++;
//    return root;
//}
vector<int> in, pre, post;
bool Unique = true;
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if(preLeft == preRight) {
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight-1]) i++;
        if (i - preLeft > 1)
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - preLeft - 1) - 1);
        else
            Unique = false;
        in.push_back(post[postRight]);
        getIn(i, preRight, postLeft + (i - preLeft - 1), postRight - 1);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    post.resize(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    getIn(0, n-1, 0, n-1);
    printf("%s\n%d", Unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
}
