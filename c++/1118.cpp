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
int n,k;
int father[MAXN];
bool isTree[MAXN] ={false};
set<int> forest;
int findfather(int x){
    int a = x;
    while (a != father[a]) {
        a = father[a];
    }
    while (x != father[x]) {
        int z = x;
        x = father[x];
        father[z] = a;
    }
    return x;
}

void Union(int a,int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa != fb) father[fa] = fb;
}



int main(){
    scanf("%d",&n);
    int birds,cur;
    for(int i=0;i<MAXN;++i) father[i] = i;
    for(int i=0;i<n;++i){
        scanf("%d%d",&k,&cur);
        forest.insert(cur);
        for(int j=1;j<k;++j){
            scanf("%d",&birds);
            forest.insert(birds);
            Union(cur, birds);
        }
    }
    int cnt = 0;
    for(auto &bird:forest){
        int fa = findfather(bird);
        if(isTree[fa] == false){
            isTree[fa] = true;
            cnt++;
        }
    }
    printf("%d %d\n",cnt,(int)forest.size());
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        int fa = findfather(a);
        int fb = findfather(b);
        if(fa == fb) printf("Yes\n");
        else printf("No\n");
    }
}
