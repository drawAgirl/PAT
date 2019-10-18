//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/17.
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
const int MAXN = 1010;

struct bign{
    int len;
    int d[MAXN];
    bign(){
        len = 0;
        fill(d, d+MAXN, 0);
    }
};

bign add(bign &a,bign &b){
    bign c;
    int carry = 0;
    int t;
    for(int i=0;i<a.len || i<b.len;++i){
        t = a.d[i]+b.d[i] + carry;
        c.d[c.len++] = t % 10;
        carry = t/10;
    }
    if(carry != 0) c.d[c.len++] = carry;
    return c;
}

bool isPali(bign &a){
    for(int i=0;i<a.len/2;++i){
        if(a.d[i] != a.d[a.len-i-1]) return false;
    }
    return true;
}

bign reverse_bign(bign &a){
    bign b;
    b.len = a.len;
    for(int i=0;i<a.len;++i) b.d[i] = a.d[a.len-i-1];
    return b;
}

void show_bign(bign &a){
    for(int i=a.len-1;i>=0;--i) printf("%d",a.d[i]);
}


int main(){
    string n;
    cin >> n;
    bign a;
    a.len = (int)n.size();
    for(int i=0;i<a.len;++i) a.d[i] = n[a.len-i-1]-'0';
    
    for(int i=0;i<10;++i){
        if(isPali(a)){
            show_bign(a);
            printf(" is a palindromic number.\n");
            return 0;
        }
        bign b = reverse_bign(a);
        show_bign(a);
        printf(" + ");
        show_bign(b);
        printf(" = ");
        a = add(a, b);
        show_bign(a);
        printf("\n");
        
    }
    printf("Not found in 10 iterations.\n");
    
}
