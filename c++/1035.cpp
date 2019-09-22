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

typedef pair<string, string> pp;
vector<pp> v;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        pp temp;
        cin >> temp.first >> temp.second;
        bool flag = true;
        for(auto &it:temp.second){
            if (it == '1'){
                it = '@';
                flag = false;
            }else if(it == '0'){
                it = '%';
                flag = false;
            }else if(it == 'l'){
                it = 'L';
                flag = false;
            }else if(it == 'O'){
                it = 'o';
                flag = false;
            }
        }
        if(!flag) v.push_back(temp);
    }
    if(v.size() == 0){
        if( n == 1){
            cout <<"There is 1 account and no account is modified";
        }else{
            cout <<"There are "<<n<<" accounts and no account is modified";
        }
    }else{
        cout << v.size()<<endl;
        for(auto it:v){
            cout << it.first << " " << it.second << "\n";
        }
    }
}
