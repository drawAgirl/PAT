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

int n,m,k,c1,c2;

struct person{
    string name;
    int age;
    int worth;
};
vector<person> v;
bool age(person &a,person &b){
    if(a.age != b.age) return a.age < b.age;
    else if (a.worth != b.worth) return a.worth < b.worth;
    return a.name < b.name;
}


vector<int> vv;
int find_big(int c){
    int left = 0;
    int right = (int)vv.size()-1;
    while (left < right) {
        int mid = (left+right) >> 1;
        if(vv[mid] > c) right = mid;
        else left = mid+1;
    }
    return left;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=10;++i) vv.push_back(i);
    int ind = find_big(5);
    cout << ind << " "<< vv[ind];
//    cin >> n >> m;
//    for(int i=0;i<n;++i){
//        person cur;
//        cin >> cur.name >> cur.age >> cur.worth;
//        v.push_back(cur);
//    }
//    sort(v.begin(), v.end(), age);
//    for(int i=1;i<=m;++i){
//        cin >> k >> c1 >> c2;
//        cout <<"Case #"<< i <<":\n";
//
//    }
}
