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


const int MAXN = 10010;

vector<int> v;
int arr[1010];
int N;
int ind = 0;
void inorder(int root){
    if (root > N) return;
    inorder(root*2);
    arr[root] = v[ind++];
    inorder(root*2+1);
}

int main(){
    scanf("%d",&N);
    for (int i=0; i<N; i++) {
        int a;
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    inorder(1);
    for (int i=1; i<=N; i++) {
        printf("%d",arr[i]);
        if(i != N)
            printf(" ");
    }
    
}
