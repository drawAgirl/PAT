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
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
struct Fraction{
    ll up,down;
};

Fraction reduction(Fraction a){
    if(a.up == 0) a.down = 1;
    if(a.down < 0){
        a.down = -a.down;
        a.up = -a.up;
    }
    ll d = gcd(abs(a.up), abs(a.down));
    a.up /= d;
    a.down /= d;
    return a;
}

Fraction add(Fraction a,Fraction b){
    Fraction c;
    c.down = a.down*b.down;
    c.up = a.down*b.up + a.up*b.down;
    return reduction(c);
}

Fraction multi(Fraction a,Fraction b){
    Fraction c;
    c.up = a.up*b.up;
    c.down = a.down*b.down;
    return reduction(c);
}
Fraction div(Fraction a,Fraction b){
    Fraction c;
    c.up = a.up * b.down;
    c.down = a.down * b.up;
    return reduction(c);
}

void show(Fraction a){
    a = reduction(a);
    if(a.down == 0){
        printf("Inf");
        return;
    }
    if(a.down == 1){
        if(a.up < 0) printf("(%lld)",a.up);
        else printf("%lld",a.up);
    }else if (abs(a.up) > abs(a.down)){
        if(a.up < 0) printf("(%lld %lld/%lld)",a.up/a.down,abs(a.up)%a.down,a.down);
        else printf("%lld %lld/%lld",a.up/a.down,a.up%a.down,a.down);
    }else{
        if(a.up < 0) printf("(%lld/%lld)",a.up,a.down);
        else printf("%lld/%lld",a.up,a.down);
    }
}
Fraction a,b;
char c[] = {'+','-','*','/'};
int main(){
    scanf("%lld/%lld%lld/%lld",&a.up,&a.down,&b.up,&b.down);
    for(int i=0;i<4;++i){
        show(a);
        printf(" %c ",c[i]);
        show(b);
        printf(" = ");
        if(i==0) show(add(a, b));
        else if (i==1){
            b.up = -b.up;
            show(add(a, b));
            b.up = -b.up;
        }else if(i==2) show(multi(a, b));
        else show(div(a, b));
        printf("\n");
    }
    
}
