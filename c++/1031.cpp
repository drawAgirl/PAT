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


string word;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> word;
    int len = (int)word.size();
    int size = (len+2)/3;
    int bottom = len-size-size;
    for (int i=0; i<size-1; ++i) {
        cout << word[i];
        for (int space=0; space<bottom; space++) cout <<" ";
        cout << word[len-1-i] <<"\n";
    }
    for (int i=size-1; i<size+bottom+1; ++i) {
        cout << word[i];
    }
    cout <<"\n";
    
    
}
