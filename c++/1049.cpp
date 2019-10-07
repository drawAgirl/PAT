//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/4.
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

int n;
int a=1;
int ans = 0;

int main(){
    scanf("%d",&n);
    int left,now,right;
    while (n / a != 0) {
        left = n /(10*a);
        now = n/a % 10;
        right = n % a;
        if(now == 0) ans += left*a;
        else if (now==1) ans+= left*a + right+1;
        else ans += (left+1)*a;
        a *= 10;
    }
    printf("%d\n",ans);
}
