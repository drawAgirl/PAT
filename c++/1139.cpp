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
const int MAXN =1e5+10;

typedef pair<int, int> pp;
vector<int> v[MAXN];
struct cmp{
    bool operator()(const pp &a,const pp &b)const{
        if(a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    }
};

set<pp> s;
set<pp,cmp> ss;

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n,m,k;
    scanf("%d%d",&n,&m);
    char a[10];
    char b[10];
    for(int i=0;i<m;++i){
        scanf("%s %s",a,b);
        int aa = abs(stoi(a));
        int bb = abs(stoi(b));
        if(strlen(a) == strlen(b)){ //同性
            v[aa].emplace_back(bb);
            v[bb].emplace_back(aa);
        }
        s.insert(pp(aa,bb));
        s.insert(pp(bb,aa));
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        ss.clear();
        int aa,bb;
        scanf("%d%d",&aa,&bb);
        aa = abs(aa);
        bb = abs(bb);
        for(int j=0;j<(int)v[aa].size();++j){
            if(bb == v[aa][j]) continue;
            for(int l=0;l<(int)v[bb].size();++l){
                if(v[bb][l] == aa) continue;
                if(s.find({v[aa][j],v[bb][l]}) != s.end()){
                    ss.insert(pp(v[aa][j],v[bb][l]));
                }
            }
        }
        printf("%d\n",(int)ss.size());
        for(auto &each:ss){
            printf("%04d %04d\n",each.first,each.second);
        }
    }
    
    
}
