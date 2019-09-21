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
#include <unordered_map>
#include <string.h>
using namespace std;


map<int, double> dic;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,a;
    double b;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a >>b;
        dic[a] = b;
    }
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a >>b;
        if(dic.find(a) == dic.end()) dic[a] = b;
        else{
            dic[a] += b;
            if (dic[a] == 0) dic.erase(a);
        }
    }
    printf("%d",(int)dic.size());
    int size = (int)dic.size();
    for (auto it=dic.end(); size>0; size--) {
        it--;
        if (it == dic.end()) continue;
        printf(" %d %.1f",(*it).first,(*it).second);
    }
    
}
