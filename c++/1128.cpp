//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/16.
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

int N;
int main(){
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        bool flag = false;
        int n;
        scanf("%d",&n);
        int number[1010];
        for(int j=0;j<n;j++){
            scanf("%d",&number[j]);
        }
        for(int j=0;j<n;j++){
            for(int step=1;j+step<n;step++){
                if(number[j]+step == number[j+step] || number[j]-step == number[j+step] || number[j] == number[j+step]){
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag)
            printf("NO\n");
        else
            printf("YES\n");

    }
}
