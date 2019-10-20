//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/19.
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

int n,m,k,temp;
unordered_map<int, vector<int>> goods;

int main(){
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<n;++i){
        scanf("%d%d",&a,&b);
        goods[a].emplace_back(b);
        goods[b].emplace_back(a);
    }
    while (m--) {
        scanf("%d",&k);
        vector<int> v;
        bool exists[100000] = {false};
        for(int i=0;i<k;++i){
            scanf("%d",&temp);
            exists[temp] = true;
            v.emplace_back(temp);
        }
        bool flag = true;
        for(int i=0;i<k && flag;++i){
            for(auto &each:goods[v[i]]){
                if(exists[each]){
                    flag = false;
                    break;
                }
            }
        }
        printf("%s\n",flag==true?"Yes":"No");
    }
}

