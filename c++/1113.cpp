//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/15.
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
 
int n,t;
vector<int> v;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&t);
        v.emplace_back(t);
    }
    sort(v.begin(), v.end());
    int a=0,b=0;
    int mid =  n>>1;
    for(int i=0;i<mid;++i) a+=v[i];
    for(int i=mid;i<n;++i) b+=v[i];
    if(n&1) printf("1 %d\n",abs(a-b));
    else printf("0 %d\n",abs(a-b));
}
