//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/17.
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

int n;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    string num;
    for(int i=0;i<n;++i){
        cin >> num;
        int mid = (int)num.size() >> 1;
        int a = stoi(num.substr(0,mid));
        int b = stoi(num.substr(mid));
        if(a*b != 0 && stoi(num.c_str())%(a*b) == 0) cout <<"Yes\n";
        else cout << "No\n";
    }
}
