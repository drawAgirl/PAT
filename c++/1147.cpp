//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/18.
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

const int MAXN = 1010;
int tree[MAXN];
int M,n;
int ans[MAXN];
bool isMax(){
    for(int i=1;i<=n/2;i++){
        if(tree[i] < tree[2*i])
            return false;
        if(2*i+1 <= n){
            if(tree[i] < tree[2*i+1])
                return false;
        }
    }
    return true;
}

bool isMin(){
    for(int i=1;i<=n/2;i++){
        if(tree[i] > tree[2*i])
            return false;
        if(2*i+1 <= n){
            if(tree[i] > tree[2*i+1])
                return false;
        }
    }
    return true;
}

int cnt = 0;
void inorder(int root){
    if(root > n)
        return;
    inorder(2*root);
    inorder(2*root+1);
    ans[cnt++] = tree[root];
}
void show(){
    for(int i=0;i<cnt;i++){
        printf("%d",ans[i]);
        if(i<cnt-1)
            printf(" ");
    }
    printf("\n");
}
int main(){
    scanf("%d%d",&M,&n);
    while(M--){
        cnt = 0;
        for(int i=1;i<=n;i++)
            scanf("%d",&tree[i]);
        bool flag1 = isMax();
        if(flag1){
            printf("Max Heap\n");
        }else{
            if(isMin()){
                printf("Min Heap\n");
            }else
                printf("Not Heap\n");
        }
        inorder(1);
        show();
    }
    
}

