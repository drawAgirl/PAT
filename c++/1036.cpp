//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/21.
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


struct node {
    string name;
    string id;
    int score;
};
vector<node> v1,v2; // v1->male v2->female

bool cmp(node &a,node &b){
    return a.score > b.score;
}
bool cmp1(node &a,node &b){
    return a.score < b.score;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        node temp;
        string sex;
        cin >> temp.name >> sex >> temp.id >> temp.score;
        if (sex == "M") v1.push_back(temp);
        else v2.push_back(temp);
    }
    if(v1.size() == 0){
        sort(v2.begin(), v2.end(), cmp);
        cout << v2[0].name << " " << v2[0].id << "\nAbsent\n" << "NA";
    }else if(v2.size() == 0){
        sort(v1.begin(), v1.end(), cmp1);
        cout << "Absent\n" << v1[0].name <<" "<<v1[0].id << "\nNA";
    }else{
        sort(v1.begin(), v1.end(), cmp1);
        sort(v2.begin(), v2.end(), cmp);
        cout << v2[0].name << " " << v2[0].id << "\n";
        cout << v1[0].name << " " << v1[0].id << "\n";
        cout << v2[0].score - v1[0].score;
    }
    
}
