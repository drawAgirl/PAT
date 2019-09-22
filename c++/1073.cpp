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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int i = 0;
    while (s[i] != 'E') i++;
    string t = s.substr(1, i-1);
    int n = stoi(s.substr(i+1));
    if (s[0] == '-') cout << "-";
    if (n < 0) {
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++) cout << '0';
        for (int j = 0; j < t.length(); j++)
            if (t[j] != '.') cout << t[j];
    } else {
        cout << t[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < t.length() && cnt < n; j++, cnt++) cout << t[j];
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++) cout << '0';
        } else {
            cout << '.';
            for (int k = j; k < t.length(); k++) cout << t[k];
        }
    }
    return 0;
}
