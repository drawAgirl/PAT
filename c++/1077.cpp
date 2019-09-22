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

int main(){
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d",&n);
    scanf("%*c");
    string ans;
    for (int i=0; i<n; i++) {
        string a;
        getline(cin,a);
        reverse(a.begin(), a.end());
        int lens = a.length();
        if(i==0){
            ans = a;
            continue;
        }
        else{
            int lenans = ans.length();
            int minlen = min(lens,lenans);
            for(int j=0;j<minlen;j++){
                if(ans[j] != a[j]){
                    ans = ans.substr(0,j);
                    break;
                }
                
            }
        }
    }
    reverse(ans.begin(),ans.end());
    if(ans.size() == 0)
        printf("nai\n");
    else{
        cout << ans;
    }
}
