//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/19.
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

int L,K;

bool isPrime(int x){
    int limit = sqrt(x);
    if( x ==2 ) return true;
    for (int i = 2; i < limit; ++i)
    {
        if(x % i == 0) return false;
    }
    return true;
}


int main(){
    scanf("%d%d%*c",&L,&K);
    string s;
    getline(cin,s);
    for(int i=0;i<=L-K;i++){
        int sum = 0;
        string ss = s.substr(i,K);
        for(int i=0;i<ss.size();i++){
          sum = sum*10 + (ss[i]-'0');
        }
        if(isPrime(sum)){
        cout << ss << endl;
            return 0;
        }
    }
    printf("404\n");
}
