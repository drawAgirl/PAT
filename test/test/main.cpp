//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/1.
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



struct bign {
    int d[1000];
    int len;
    bign(){
        memset(d, 0, sizeof(d));
        len = 0;
    }
};

bign change(char c[]){
    int len = strlen(c);
    bign a;
    for (int i=0; i<len; i++) {
        a.d[i] = c[len-i-1] - '0' ;
        a.len++;
    }
    return a;
}

bign add(bign a,bign b){
    int carry = 0;
    int index = 0;
    bign c;
    for (int i=0; i<a.len; i++) {
        int temp = a.d[i] + b.d[i] + carry;
        c.d[index++] = temp % 10;
        carry = temp / 10;
        c.len++;
    }
    if (carry != 0) {
        c.d[index++] = carry;
        c.len++;
    }
    return c;
}

bign Reverse(bign a){
    bign b;
    b.len = a.len;
    for (int i=0; i<a.len; i++) {
        b.d[i] = a.d[a.len-1-i];
    }
    return b;
}

bool istrue(bign a){
    for (int i=0; i<a.len/2; i++) {
        if (a.d[i] != a.d[a.len-i-1]) {
            return false;
        }
    }
    return true;
}

void show(bign a){
    for (int i=a.len-1; i>=0; i--) {
        printf("%d",a.d[i]);
    }
    printf("\n");
}

int main(){
    int k;
    char n[1000];
    scanf("%s%d",n,&k);
    bign a = change(n);
    
    int count = 0;
    while (count < k) {
        if (istrue(a)) {
            show(a);
            printf("%d",count);
            return 0;
        }else{
            count++;
            bign b = Reverse(a);
            a = add(a, b);
        }
    }
    show(a);
    printf("%d",count);
}
