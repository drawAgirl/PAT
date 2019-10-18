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

typedef pair<double, int> pp;
struct node{
    int score;
    int people;
    string school;
};
vector<node> v;
bool cmp(const node&a,const node &b){
    if(a.score != b.score) return a.score > b.score;
    else if (a.people != b.people ) return a.people < b.people;
    return a.school < b.school;
}
unordered_map<string, pp> total_school_score;

int n;

int main(){
    scanf("%d",&n);
    string id,school;
    int score;
    for(int i=0;i<n;++i){
        cin >> id >> score >> school;
        for(auto &each:school){
            if(each >='A' && each <='Z') each = 'a'+each-'A';
        }
        total_school_score[school].second++;
        if(id[0]=='A') total_school_score[school].first += score;
        else if (id[0]=='B') total_school_score[school].first += score/1.5;
        else total_school_score[school].first += score*1.5;
    }
    
    for(auto &each:total_school_score){
        node cur;
        cur.school = each.first;
        cur.score = (int)each.second.first;
        cur.people = each.second.second;
        v.emplace_back(cur);
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d\n",(int)v.size());
    int pre_rank = 1;
    int pre_score = -1;
    int rank = 1;
    for(int i=0;i<(int)v.size();++i){
        if(v[i].score == pre_score) printf("%d ",pre_rank);
        else{
            printf("%d ",rank);
            pre_rank = rank;
            pre_score = v[i].score;
        }
        cout << v[i].school << " " << v[i].score << " " << v[i].people <<"\n";
        rank++;
    }
    
    
    
}
