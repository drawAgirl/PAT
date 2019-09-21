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


void to_array(int n,int arr[]){
    for (int i=0; i<4; ++i) {
        arr[i] = n % 10;
        n /= 10;
    }
}

int to_num(int num[]){
    int ans = 0;
    for (int i=0; i<4; ++i) {
        ans = ans*10 + num[i];
    }
    return ans;
}

bool cmp(int a,int b){
    return a > b;
}

int main(){
    int n;
    int a,b;
    scanf("%d",&n);
    int arr[5];
    while (1) {
        to_array(n, arr);
        sort(arr, arr+4);
        a = to_num(arr);
        sort(arr, arr+4, cmp);
        b = to_num(arr);
        n = b-a;
        printf("%04d - %04d = %04d\n",b,a,n);
        if( n == 6174 || n == 0) break;
    }
    return 0;
}
