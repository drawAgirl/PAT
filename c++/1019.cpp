//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/22.
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
#include <unordered_map>
#include <string.h>
using namespace std;


int n,base;
vector<int> v;


void to_array(int n,int base){
    int a = n;
    while (a != 0) {
        v.push_back(a%base);
        a /= base;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> base;
    to_array(n, base);
    bool flag = true;
    int len = (int)v.size()/2;
    for (int i=0; i<=len; ++i) {
        if(v[i] != v[v.size()-1-i]){
            flag = false;
            break;
        }
    }
    if(!flag) printf("No\n");
    else printf("Yes\n");
    for (int i=(int)v.size()-1; i>=0; i--) {
        printf("%d",v[i]);
        if(i!=0) printf(" ");
    }
}
