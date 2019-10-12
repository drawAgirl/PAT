//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/12.
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


int main(){
    int n;
    scanf("%d",&n);
    double v,ans = 0;
    for(int i=1;i<=n;i++){
      scanf("%lf",&v);
      ans += v*i*(n+1-i);
    }
    printf("%.2f",ans);
    return 0;
}
