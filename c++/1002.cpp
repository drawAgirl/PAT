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
#include <string.h>
using namespace std;


struct point {
    int zhishu = 0;
    double xishu = 0;
    bool flag = false;
}node[2010];

// a是指数 b是系数
// a:int b:double

bool cmp(point &a,point &b){
    if(a.flag != b.flag) return a.flag > b.flag;
    return a.zhishu > b.zhishu;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int cnt = 0;
    for (int i=0; i<2; ++i) {
        int k;
        cin >> k;
        for (int j=0; j<k; ++j) {
            int a;
            double b;
            cin >> a >> b;
            node[a].xishu += b;
            node[a].zhishu = a;
            if(node[a].xishu != 0)
                node[a].flag = true;
            else
                node[a].flag = false;
        }
    }
    sort(node, node+2010, cmp);
    for(int i=0;i<2010;++i){
        if(node[i].flag == false) break;
        cnt++;
    }
    cout << cnt;
    for (int i=0; i<cnt; ++i) {
        printf(" %d %.1f",node[i].zhishu,node[i].xishu);
    }
    
}



