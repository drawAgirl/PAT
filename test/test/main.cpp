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
#include <string.h>
using namespace std;



int t;

long long a,b,c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int i=1; i<=t; ++i) {
        cin >> a >> b >> c;
        long long ans = a+b;
        
        cout <<"Case #"<<i<<": ";
        if(a>0 && b >0 && ans<0) cout << "true";
        else if(a<0 && b <0 && ans>=0) cout << "false";
        else if(ans > c) cout<<"true";
        else cout <<"false";
        cout <<"\n";
    }
}
