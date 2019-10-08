//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/7.
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
#include <set>
using namespace std;

#define lowbit(i) ((i)&(-i))
const int MAXN = 1e5+10;
int c[MAXN];
int getsum(int x){
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans += c[i];
    }
    return ans;
}
void update(int x,int v){
    for(int i=x;i<MAXN;i+=lowbit(i)) c[i] += v;
}

int main(){
    
}



