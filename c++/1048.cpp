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

unordered_map<int, int> HASH;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i=0;i<n;++i){
        int a;
        cin >> a;
        HASH[a]++;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); ++i) {
        if(HASH[m-v[i]]){
            if (m-v[i] == v[i]){
                if(HASH[v[i]] < 2) break;
            }
            int x,y;
            x = m-v[i];
            y = v[i];
            if(x > y) swap(x, y);
            printf("%d %d",x,y);
            return 0;
        }
    }
    printf("No Solution");
    
}
