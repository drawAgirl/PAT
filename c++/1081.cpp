//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/9.
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

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b, a%b);
}
struct fraction{
    int up;
    int down;
};

fraction reduction(fraction a){
    if (a.down < 0) {
        a.up = -a.up;
        a.down = -a.down;
    }
    if (a.up == 0) {
        a.down = 1;
    }else{
        int d= gcd(abs(a.down), abs(a.up));
        a.up /= d;
        a.down /= d;
    }
    return a;
}
// 1/3 1/5

fraction add(fraction a,fraction b){
    fraction c;
    c.down = a.down * b.down;
    c.up = a.up*b.down + b.up*a.down;
    return reduction(c);
}

void show(fraction a){
    if(a.down == 1) printf("%d",a.up);
    else if (abs(a.up) > a.down){
        printf("%d %d/%d",a.up/a.down,abs(a.up)%a.down,a.down);
    }else
        printf("%d/%d",a.up,a.down);
}

int n;

int main(){
    scanf("%d",&n);
    fraction ans,cur;
    ans.up =0;
    ans.down = 1;
    while (scanf("%d/%d",&cur.up,&cur.down)!=EOF) {
        ans = add(ans, cur);
    }
    show(ans);
    
}
