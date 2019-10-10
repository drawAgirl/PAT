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
const int MAXN = 1e5+10;
int n,m,k,c1,c2;
struct person {
    string name;
    int age;
    int worth;
};
unordered_map<int,  vector<person>> data;
int age[MAXN] = {0};
vector<person> v;
vector<person> ans;
bool cmp(person &a,person &b){
    if(a.worth != b.worth) return a.worth >b.worth;
    else if (a.age != b.age) return a.age < b.age;
    return a.name < b.name;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;++i){
        person cur;
        cin>> cur.name >> cur.age >> cur.worth;
        v.push_back(cur);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto &each:v){
        if(age[each.age] < 100){
            age[each.age]++;
            ans.push_back(each);
        }
    }
    for(int i=1;i<=m;++i){
        int k,c1,c2;
        cin >> k >> c1 >> c2;
        cout << "Case #"<<i<<":\n";
        int num = 0;
        for(int j=0;j<(int)ans.size() && num < k;j++){
            if(ans[j].age >=c1 && ans[j].age <= c2){
                cout << ans[j].name << " " << ans[j].age << " " << ans[j].worth << "\n";
                num++;
            }
                
        }
        if(num == 0) printf("None\n");   
    }
}
