//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/15.
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
int n;
int id[MAXN];
bool prime[MAXN] ={false};
int reward[10010];

void init(){
    for(int i=2;i<MAXN;++i){
        if(prime[i] == false){
            for(int j=i+i;j<MAXN;j+=i) prime[j] = true;
        }
    }
}

int main(){
    fill(reward, reward+MAXN, -1);
    scanf("%d",&n);
    init();
    for(int i=1;i<=n;++i){
        scanf("%d",&id[i]);
        if(i == 1) reward[id[i]] = 0;
        else if (prime[i] == false) reward[id[i]] = 1;
        else reward[id[i]] = 2;
    }
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int cur;
        scanf("%d",&cur);
        printf("%04d: ",cur);
        if(reward[cur] == 0){
            printf("Mystery Award\n");
            reward[cur] = 3;
        }
        else if(reward[cur] == 1){
            printf("Minion\n");
            reward[cur] = 3;
        }
        else if(reward[cur] == 2){
            printf("Chocolate\n");
            reward[cur] = 3;
        }
        else if (reward[cur] == 3){
            printf("Checked\n");
        }else printf("Are you kidding?\n");
        
    }
    
}

