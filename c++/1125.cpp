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

const int MAXN = 1e4+10;
int arr[MAXN];
int n;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&arr[i]);
    sort(arr, arr+n);
    double ans = arr[0];
    for(int i=1;i<n;++i) ans = (ans+arr[i])/2;
    printf("%d",(int)ans);
}
