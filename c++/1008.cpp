//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/29.
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
using namespace std;


int n,to;
// up = 6s down = 4s stay = 5s
int main(){
    scanf("%d",&n);
    int time = 5*n;
    int pre = 0;
    for(int i=0;i<n;++i){
        scanf("%d",&to);
        if(to>pre){
            time += (to-pre)*6;
            pre = to;
        }else{
            time += (pre-to)*4;
            pre = to;
        }
    }
    printf("%d\n",time);
}
