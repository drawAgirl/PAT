//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/23.
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


vector<int> v1,v2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int t;
    int ans =0;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> t;
        v1.push_back(t);
    }
    cin >> m;
    for (int i=0; i<m; ++i) {
        cin >> t;
        v2.push_back(t);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i=0;
    while (i<n && i <m && v1[i]<0 && v2[i]<0) {
        ans += v1[i]*v2[i];
        i++;
    }
    i = n-1;
    int j = m-1;
    while (i>=0&& j>=0 &&v1[i]>0 && v2[j]>0) {
        ans += v1[i]*v2[j];
        i--;
        j--;
    }
    printf("%d\n",ans);
    
}

