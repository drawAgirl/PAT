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
const int MAXN =1e4+10;
int n,k,m,id,problem,grades;
int score[6];

struct node{
    int id;
    int score[6];
    int total = 0;
    int perfect = 0;
    int rank;
    bool flag = false;
    node(){
        fill(score, score+6, -2);
    }
}people[MAXN];

bool cmp(node &a,node &b){
    if(a.flag != b.flag) return a.flag > b.flag;
    else if (a.total != b.total) return a.total > b.total;
    else if (a.perfect != b.perfect) return a.perfect > b.perfect;
    return a.id < b.id;
}


int main(){
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=k;++i) scanf("%d",&score[i]);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&id,&problem,&grades);
        people[id].id = id;
        if(grades > -1) people[id].flag = true;
        people[id].score[problem] = max(people[id].score[problem],grades);
    }
    int cnt = 0;
    for(int i=1;i<=n;++i){
        if(people[i].flag){
            cnt++;
            for(int j=1;j<=k;++j){
                if(people[i].score[j]>0){
                    people[i].total += people[i].score[j];
                    if(people[i].score[j] == score[j]) people[i].perfect++;
                }
            }
        }
    }
    sort(people, people+MAXN, cmp);
    int rank = 1;
    people[0].rank = rank++;
    for(int i=1;i<n;++i){
        if(people[i].flag == false) continue;
        if(people[i].total == people[i-1].total) people[i].rank = people[i-1].rank;
        else people[i].rank = rank;
        rank++;
    }
    for(int i=0;i<cnt;++i){
        printf("%d %05d %d",people[i].rank,people[i].id,people[i].total);
        for(int j=1;j<=k;++j){
            if(people[i].score[j] >=0) printf(" %d",people[i].score[j]);
            else if (people[i].score[j] == -1) printf(" 0");
            else printf(" -");
        }
        printf("\n");
    }
    
    
}
