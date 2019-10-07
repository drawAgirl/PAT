//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/1.
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

const int MAXN = 2e5+10;
int n,m;
long long arr1[MAXN];
long long arr2[MAXN];

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%lld",&arr1[i]);
    scanf("%d",&m);
    for(int i=0;i<m;++i) scanf("%lld",&arr2[i]);
    arr1[n]=arr2[m] = 0x7fffffff;
    int mid = (n+m-1)>>1;
    int index = 0;
    int i=0,j=0;
    while (index <mid) {
        if(arr1[i]<arr2[j]) i++;
        else j++;
        index++;
    }
    if(arr1[i] <arr2[j]) printf("%lld",arr1[i]);
    else printf("%lld",arr2[j]);
}

