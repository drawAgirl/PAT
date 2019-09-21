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


int n;
int order[60];
int card[60];
int ans[60];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n; 
    for (int i=1; i<55; ++i){
        cin >> order[i];
        card[i] = i;
    }
    while (n--) {
        for (int i=1; i<55; ++i) {
            ans[order[i]] = card[i];
        }
        for (int i=1; i<55; ++i) {
            card[i] = ans[i];
        }
    }
    for (int i=1; i<55; ++i) {
//        cout << ans[i] << " ";
        if(ans[i] <= 13) cout <<"S"<<ans[i];
        else if(ans[i]<=26) cout <<"H"<<ans[i]-13;
        else if(ans[i]<=39) cout <<"C"<<ans[i]-26;
        else if(ans[i]<=52) cout <<"D"<<ans[i]-39;
        else cout <<"J"<<ans[i]%-52;
        if(i != 54) cout << " ";
    }
    
}
