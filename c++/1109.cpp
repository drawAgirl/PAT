//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/13.
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
#include <deque>
using namespace std;
const int MAXN = 1e4+10;
int n,k;

struct node{
    char name[9]; // 如果这里改成string 
    int height;
}men[MAXN];

bool cmp(node &a,node &b){
    if(a.height != b.height) return a.height > b.height;
    return strcmp(a.name, b.name) < 0; // 这里要改成 a.name < b.name
}

int main(){
    scanf("%d%d",&n,&k);
    int each_row_people = n/k;
    int last_row_people = n%k + each_row_people;
    for(int i=0;i<n;++i) scanf("%s%d",men[i].name,&men[i].height);
    sort(men, men+n, cmp);
    int base = 0;
    for(int i=0;i<k;++i){
        deque<int> q;
        int people = each_row_people;
        if(i == 0) people = last_row_people;
        for(int j=0;j<people;++j){
            if(j&1) q.push_front(j+base);
            else q.push_back(j+base);
        }
        base += people;
        int space = 0;
        for(auto &man:q){
            printf("%s",men[man].name);
            space++;
            if(space != people) printf(" ");
            else printf("\n");
        }
    }
}
