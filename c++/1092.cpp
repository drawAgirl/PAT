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


unordered_map<char, int> dic;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int miss = 0;
    int cnt = 0;
    for(auto each:a) dic[each]++;
    for(auto each:b){
        if(dic.find(each) == dic.end()) miss++;
        else{
            dic[each]--;
            cnt++;
            if(dic[each] == 0) dic.erase(each);
        }
    }
    if (miss) printf("No %d",miss);
    else{
        printf("Yes %d",(int)a.size()-cnt);
    }
    
}
