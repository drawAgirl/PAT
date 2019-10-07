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
const int MAXN = 1010;
int m,n,k,t;

int main(){
    scanf("%d%d%d",&m,&n,&k);
    while (k--) {
        stack<int> s;
        int arr[MAXN];
        for(int i=1;i<=n;++i){
            scanf("%d",&arr[i]);
        }
        bool flag = true;
        int cur = 1;
        for(int i=1;i<=n;++i){
            s.push(i);
            if(s.size() > m){
                flag = false;
                break;
            }
            while (!s.empty() &&s.top() == arr[cur]) {
                s.pop();
                cur++;
            }
        }
        if(s.empty() && flag) printf("YES\n");
        else printf("NO\n");
    }
}
