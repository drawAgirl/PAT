//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/23.
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
#include <unordered_map>
#include <string.h>
using namespace std;


#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct student {
    int id;
    int grade[4];
}stu[2010];
int now;
int Rank[10000000][4] = {0};

bool cmp(struct student a,struct student b){
    return a.grade[now] > b.grade[now];
}

char course[4] = {'A','C','M','E'};
int main(){
    // printf("hello\n");
    int N,M;
    scanf("%d%d",&N,&M);
    for (int i=0; i<N; i++){
        scanf("%d%d%d%d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
        stu[i].grade[0] =round(((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/3.0)+0.5);
    }
    for (now = 0; now <4; now++) {
        sort(stu, stu+N, cmp);
        Rank[stu[0].id][now] = 1;
        for (int i =1; i<N; i++) {
            if (stu[i].grade[now] == stu[i-1].grade[now]) {
                Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
            }else
                Rank[stu[i].id][now] = i+1;
        }
    }
    int query;
    for (int i =0; i<M; i++) {
        scanf("%d",&query);
        if(Rank[query][0] == 0)
            printf("N/A\n");
        else{
            int k = 0;
            for (int j = 0; j<4; j++) {
                if (Rank[query][j] < Rank[query][k]) {
                    k = j;
                }
            }
            printf("%d %c\n",Rank[query][k],course[k]);
        }
    }
    return 0;
}

