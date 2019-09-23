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


vector<double> v;
typedef pair<double, int> pp;
vector<pp> price;

bool cmp(pp &a,pp &b){
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double n,m;
    cin >> n >> m;
    for (int i=0; i<n; ++i){
        double t;
        cin >> t;
        v.push_back(t);
    }
    for (int i=0;i<n;++i){
        pp temp;
        cin >> temp.first;
        temp.first /= v[i];
        temp.second = i;
        price.push_back(temp);
    }
    sort(price.begin(), price.end(), cmp);
    double ans = 0;
    for (int i=0; i<n && m>0; ++i) {
        if(v[price[i].second] >= m){
            ans += m*price[i].first;
            m -= v[price[i].second];
        }else{
            m -= v[price[i].second];
            ans += v[price[i].second]*price[i].first;
        }
    }
    printf("%.2f",ans);
    
    
    
}
