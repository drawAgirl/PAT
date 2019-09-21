//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/21.
//  Copyright © 2019 李寻欢. All rights reserved.
//
#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;


const int MAXN = 1e5+10;
int dis[MAXN],A[MAXN];

int main(){
    int sum = 0;
    int query,n,left,right;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) {
        scanf("%d",&A[i]);
        sum+=A[i];
        dis[i] = sum;
    }
    scanf("%d",&query);
    for (int i = 0; i<query;i++) {
        scanf("%d%d",&left,&right);
        if(left > right)
            swap(left, right);
        int temp = dis[right-1]-dis[left-1];
        printf("%d\n",min(temp, sum-temp));
    }
}
