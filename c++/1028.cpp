//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/1.
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


const int MAXN = 1e5+10;
int n,c;

struct person{
    string id;
    string name;
    int score;
}people[MAXN];

bool cmp1(person &a,person &b){
    return a.id < b.id;
}

bool cmp2(person &a,person &b){
    if(a.name != b.name) return a.name < b.name;
    return a.id < b.id;
}

bool cmp3(person &a,person &b){
    if(a.score != b.score) return a.score < b.score;
    return a.id < b.id;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> c;
    for(int i=0;i<n;++i) cin>>people[i].id >> people[i].name >> people[i].score;
    if(c == 1) sort(people, people+n, cmp1);
    else if (c == 2) sort(people, people+n, cmp2);
    else sort(people, people+n, cmp3);
    for(int i=0;i<n;++i) cout << people[i].id <<" " << people[i].name << " " << people[i].score << "\n";
}

