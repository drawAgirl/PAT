//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/17.
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

const int MAXN = 1e6+10;
int head,n,k;
struct node{
    int address;
    int val;
    int next;
    bool flag = false;
    int priority = MAXN;
    int order=MAXN;
}Node[MAXN];


bool cmp(const node &a,const node &b){
    if(a.flag != b.flag) return a.flag > b.flag;
    else if (a.priority!= b.priority) return a.priority < b.priority;
    return a.order < b.order;
}


int main(){
    scanf("%d%d%d",&head,&n,&k);
    int address;
    for(int i=0;i<n;++i){
        scanf("%d",&address);
        Node[address].address = address;
        scanf("%d%d",&Node[address].val,&Node[address].next);
    }
    int p = head;
    int cnt = 0;
    while (p != -1) {
        Node[p].flag = true;
        Node[p].order = ++cnt;
        if(Node[p].val < 0) Node[p].priority = 1;
        else if (Node[p].val <= k) Node[p].priority = 2;
        else Node[p].priority = 3;
        p = Node[p].next;
    }
    sort(Node, Node+MAXN, cmp);
    for(int i=0;i<cnt;++i){
        printf("%05d %d ",Node[i].address,Node[i].val);
        if(i!=cnt-1) printf("%05d\n",Node[i+1].address);
        else printf("-1\n");
    }
}
