//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/20.
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
using namespace std;

struct student {
    char id[15];
    int score;
    int location;
    int location_rank;
}stu[30010];

bool cmp(student a,student b){
    if (a.score != b.score)
        return a.score > b.score;
    else
        return strcmp(a.id, b.id) < 0;
}

int main(){
    //    printf("hello\n");
    int n;
    scanf("%d",&n);
    int index = 0;
    for (int i=0; i<n; i++) {
        int k;
        scanf("%d",&k);
        for (int j=0; j<k; j++) {
            scanf("%s %d",stu[index].id,&stu[index].score);
            stu[index].location = i+1;
            index++;
        }
        sort(stu+index-k, stu+index, cmp);
        stu[index-k].location_rank = 1;
        for (int j=index-k+1; j<index; j++) {
            if (stu[j].score == stu[j-1].score) {
                stu[j].location_rank = stu[j-1].location_rank;
            }else
                stu[j].location_rank = j+1-(index-k);
        }
    }
    printf("%d\n",index);
    sort(stu, stu+index, cmp);
    int r = 1;
    for (int i=0; i<index; i++) {
        if(i >0 && stu[i].score != stu[i-1].score){
            r = i+1;
        }
        printf("%s ",stu[i].id);
        printf("%d %d %d\n",r,stu[i].location,stu[i].location_rank);
    }
    return 0;
}
