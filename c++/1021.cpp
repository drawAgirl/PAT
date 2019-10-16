//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/15.
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

int n,a,b,m,t;
unordered_map<int, int> couple;
unordered_map<int, bool> inparty;
vector<int> v;
vector<int> ans;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&t);
        inparty[t] = true;
        v.emplace_back(t);
    }
    for(auto &dog:v){
        if(couple.find(dog) == couple.end()) ans.emplace_back(dog);
        else{
            if(inparty.find(couple[dog]) == inparty.end()) ans.emplace_back(dog);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();++i){
        printf("%05d",ans[i]);
        if(i!=ans.size()-1) printf(" ");
    }
}
