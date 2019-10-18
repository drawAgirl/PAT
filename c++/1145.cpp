//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/18.
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
const int MAXN = 1e4+10;
int Msize,n,m;
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);++i){
        if(n%i == 0) return false;
    }
    return true;
}
bool used[MAXN]={false};
int main(){
    scanf("%d%d%d",&Msize,&n,&m);
    while (isPrime(Msize) == false) Msize++;
    vector<int> v(Msize);
    
    int location,key;
    for(int i=0;i<n;++i){
        scanf("%d",&key);
        bool flag = false;
        for(int j=0;j<Msize;++j){
            location = (key+ j*j) %Msize;
            if(!used[location]){
                flag = true;
                used[location] = true;
                v[location] = key;
                break;
            }
        }
        if(!flag) printf("%d cannot be inserted.\n",key);
    }
    int cnt = 0;
    for(int i=0;i<m;++i){
        scanf("%d",&key);
        for(int step=0;step<=Msize;++step){
            cnt++;
            location = (key + step*step)%Msize;
            if(used[location] == false) break;
            if(v[location] == key) break;
        }
    }
    printf("%.1f",1.0*cnt/m);
    
}
