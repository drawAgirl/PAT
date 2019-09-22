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

string num[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int cnt = 0;
    for (int i=0; i<(int)s.size(); ++i) cnt += s[i]-'0';
    if( cnt == 0){
        printf("zero\n");
        return 0;
    }
    vector<string> v;
    while (cnt != 0) {
        v.push_back(num[cnt%10]);
        cnt /= 10;
    }
    for (int i=v.size()-1; i>=0; --i) {
        cout << v[i];
        if(i != 0) cout <<" ";
        else cout << "\n";
    }
}
