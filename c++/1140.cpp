//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/18.
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
string d;
int main(){
    cin >> d >> n;
    for(int i=1;i<n;++i){
        string ans = "";
        int len = (int)d.size();
        int j=0;
        while (j<len) {
            int k = j;
            while(k<len && d[k] == d[j]) k++;
            ans += d[j]+to_string(k-j);
            if(k==len) break;
            j = k;
        }
        d = ans;
    }
    cout << d;
}
