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

int a,b,c;
char radix[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};

void to_mar(int n){
    string ans = "";
    while (n != 0) {
        ans = radix[n % 13]+ans;
        n /= 13;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b >> c;
    cout <<"#";
    to_mar(a);
    to_mar(b);
    to_mar(c);
}
