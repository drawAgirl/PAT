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


vector<int> v;
unordered_map<int, int> HASH;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
        HASH[a]++;
    }
    int first = 0;
    for (int i=0; i<v.size(); ++i) {
        if(HASH[v[i]] == 1){
            first = v[i];
            break;
        }
    }
    if (first) printf("%d\n",first);
    else printf("None\n");
    
}
