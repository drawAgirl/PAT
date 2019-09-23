//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/23.
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
#include <string.h>
using namespace std;


unordered_map<char, bool> dic;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin >> a >> b;
    for(auto it:b){
        if(it >='a' && it <='z') dic['A'+(it-'a')] = true;
        else if (it >='A' && it<='Z') dic['a'+(it-'Z')] = true;
        dic[it] = true;
    }
    
    for(auto it:a){
        char p = it;
        if(dic.find(it) != dic.end()) continue;
        if(it >='a' && it <='z') {
            dic['A'+(it-'a')] = true;
            p ='A'+(it-'a');
        }
        else if (it >='A' && it<='Z') dic['a'+(it-'A')] = true;
        cout << p;
        dic[it] = true;
    }
}
