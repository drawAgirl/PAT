//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/17.
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
int p,m,n;

struct node{
    string name;
    int online = -1;
    int mid_score = -1;
    int final_score = -1;
    int score = 0;
};

vector<node> v;
unordered_map<string, int> which_idx;

bool cmp(const node &a,const node &b){
    if(a.score != b.score) return a.score > b.score;
    return a.name < b.name;
}

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
    cin >> p >> m >> n;
    string name;
    int score;
    int idx = 0;
    for(int i=0;i<p;++i){
        cin >> name >> score;
        if(score < 200) continue;
        which_idx[name] = idx++;
        node cur;
        cur.name = name;
        cur.online = score;
        v.emplace_back(cur);
    }
    for(int i=0;i<m;++i){
        cin >> name >> score;
        if(which_idx.find(name) == which_idx.end()) continue;
        v[which_idx[name]].mid_score = score;
    }
    for(int i=0;i<n;++i){
        cin >> name >> score;
        if(which_idx.find(name) == which_idx.end()) continue;
        v[which_idx[name]].final_score = score;
        if(v[which_idx[name]].mid_score > score)
            v[which_idx[name]].score = int(0.4*v[which_idx[name]].mid_score + 0.6*score+0.5);
        else
            v[which_idx[name]].score = score;
            
    }
        sort(v.begin(), v.end(), cmp);
        for(auto &each:v){
            if(each.final_score < 60) break;
            cout << each.name << " " << each.online <<" " << each.mid_score << " " << each.final_score<<" " << each.score << "\n";
        }
            
}
