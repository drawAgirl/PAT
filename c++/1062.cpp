//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/23.
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

const int MAXN = 1e5+10;

struct person {
    string id;
    int virtue;
    int talent;
    int rank=MAXN;
}people[MAXN];

// virtue and talent both get L will be ranked
// both get H will be sages
// virtue get H but talent not are noblemen
// both below H but virtue > talent are fool men
// rest people


bool cmp(person &a,person &b){
    if( a.rank != b.rank) return a.rank < b.rank;
    else if(a.virtue+a.talent != b.virtue + b.talent) return a.virtue+a.talent > b.virtue+b.talent;
    else if(a.virtue != b.virtue) return a.virtue > b.virtue;
    return a.id < b.id;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,L,H;
    cin >> n >> L >> H;
    int cnt = 0;
    for (int i=0; i<n; ++i) {
        string id;
        int virtue,talent;
        cin >> id >> virtue >> talent;
        if(virtue < L || talent < L) continue;
        if(virtue >=H && talent >= H) people[cnt].rank = 1;
        else if(virtue >= H && talent < H) people[cnt].rank = 2;
        else if(virtue >= talent) people[cnt].rank = 3;
        else people[cnt].rank = 4;
        people[cnt].id = id;
        people[cnt].virtue = virtue;
        people[cnt++].talent = talent;
    }
    sort(people, people+cnt, cmp);
    cout << cnt << "\n";
    for (int i=0; i<cnt; ++i) {
        cout << people[i].id << " " << people[i].virtue << " " << people[i].talent << "\n";
    }
}
