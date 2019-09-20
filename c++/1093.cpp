//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/20.
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
int a[MAXN];

int main(){
    memset(a, 0, sizeof(a));
    ios::sync_with_stdio(false);
    cin.tie(0);
    string data;
    cin >> data;
    int sum = 0;
    int len = (int)data.size();
    for (int i=0; i<len; ++i) {
        if(data[i] == 'P') ++sum;
        a[i] = sum;
    }
    int ans = 0;
    int countT = 0;
    for (int i=len-1; i>0; i--) {
        if(data[i] == 'T') countT++;
        else if(data[i] == 'A') ans += countT*a[i];
        if(ans >=1000000007) ans %= 1000000007;
    }
    cout << ans;
}
