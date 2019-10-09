//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/8.
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

const int MAXN = 1e5+10;
struct factor{
    int x,cnt;
}fac[10];
int prime[MAXN];
int pnum =0 ;
bool is[MAXN] = { false};
void find_prime(){
    for(int i=2;i<MAXN;++i){
        if (is[i] == false) {
            prime[pnum++] = i;
            for(int j=i+i;j<MAXN;j+=i) is[j] = true;
        }
    }
}

int main(){
    find_prime();
    int n,num = 0;
    scanf("%d",&n);
    if(n == 1) printf("1=1");
    else{
        printf("%d=",n);
        int sqr = (int)sqrt(1.0*n);
        for(int i=0;i<pnum && prime[i] <=sqr ;++i){
            if(n % prime[i] == 0){
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (n % prime[i] == 0) {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if(n==1)break;
        }
        if(n != 1 ){
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for(int i=0;i<num;++i){
            if(i>0) printf("*");
            printf("%d",fac[i].x);
            if(fac[i].cnt > 1)
                printf("^%d",fac[i].cnt);
        }
    }
}


