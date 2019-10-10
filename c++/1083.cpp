//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/9.
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

int n,low,high;

struct node{
    string name;
    string id;
    int score;
};
vector<node> v;
bool cmp(node &a,node &b){
    return a.score > b.score;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    node cur;
    for(int i=0;i<n;++i){
        cin >> cur.name >> cur.id >> cur.score;
        v.push_back(cur);
    }
    cin >> low >> high;
    sort(v.begin(), v.end(), cmp);
    if(v[0].score < low) cout <<"NONE\n";
    else{
        for(int i=0;i<(int)v.size();++i){
            if(v[i].score <=high && v[i].score >= low)
                cout << v[i].name  << " "<<v[i].id <<"\n";
            else if (v[i].score < low) break;
        }
    }
}
