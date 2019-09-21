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


int n;

struct node{
    string id;
    string in_time;
    string out_time;
};

vector<node> v;

bool cmp1(node &a,node &b){
    return a.in_time < b.in_time;
}


bool cmp2(node &a,node &b){
    return a.out_time > b.out_time;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        node temp;
        cin >> temp.id >> temp.in_time >> temp.out_time;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp1);
    cout << v[0].id << " ";
    sort(v.begin(), v.end(), cmp2);
    cout << v[0].id;
    
}
