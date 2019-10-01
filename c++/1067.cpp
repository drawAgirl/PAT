//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/24.
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


const int MAXN = 1e5+10;
vector<int> v1(MAXN); // 存储数字
vector<int> v2(MAXN); // 存储位置

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int zero = 0;
    for (int i=0; i<n; ++i) {
        cin >> v1[i];
        v2[v1[i]] = i;
    }
    int cnt = 0;
    int base = 1;
    while (1) {
        zero = v2[0];
        while (zero != 0) {
            swap(v1[v2[zero]], v1[zero]);
            swap(v2[0], v2[zero]);
            zero = v2[0];
            cnt++;
        }
        bool flag = true;
        int var = 0;
        for (int i=base; i<n; ++i) {
            if(v2[i] != i){
                flag = false;
                var=  i;
                break;
            }
        }
        if(flag){
            printf("%d\n",cnt);
            return 0;
        }
        cnt++;
        base = var+1;
        swap(v1[v2[var]], v1[var]);
        swap(v2[0], v2[var]);
    }
    s