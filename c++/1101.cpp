//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/12.
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
#include <set>
using namespace std;
const int MAXN = 100010;
int n;
int arr[MAXN];
int max_num[MAXN];
int min_num[MAXN];
int ans[MAXN];
int main(){
    scanf("%d",&n);
    scanf("%d",&arr[0]);
    max_num[0] = -1;
    min_num[n-1] = 0x7fffffff;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d",&arr[i]);
        max_num[i] = max(max_num[i-1],arr[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        min_num[i] = min(min_num[i+1],arr[i+1]);
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] >= max_num[i] && arr[i] <= min_num[i])
            ans[cnt++] = arr[i];
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++){
        printf("%d",ans[i]);
        if(i != cnt-1) printf(" ");
    }
    printf("\n");
    
}