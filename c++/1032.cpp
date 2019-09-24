//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/24.
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


const int MAXN = 1e6;
struct node {
    int address;
    int next;
    bool flag;
}Node[MAXN];
//bool vis[MAXN] = { false };

int main(){
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    int cur,next;
    char data;
    for (int i=0; i<n; ++i) {
        scanf("%d %c %d",&cur,&data,&next);
        Node[cur].address = cur;
        Node[cur].next = next;
        Node[cur].flag = false;
    }
    while (a != -1) {
        Node[a].flag = true;
        a = Node[a].next;
    }
    while (b != -1) {
        if(Node[b].flag){
            printf("%05d",b);
            return 0;
        }
        b = Node[b].next;
    }
    printf("-1");
    
    
}

