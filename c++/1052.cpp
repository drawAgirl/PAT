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
    int data;
    bool flag = false;
}Node[MAXN];


bool cmp(node &a,node &b){
    if(a.flag != b.flag) return a.flag > b.flag;
    return a.data < b.data;
}



int main(){
    int n,head,cur,next,data;
    scanf("%d%d",&n,&head);
    for (int i=0; i<n; ++i) {
        scanf("%d%d%d",&cur,&data,&next);
        Node[cur].address = cur;
        Node[cur].data = data;
        Node[cur].next = next;
    }
    int cnt = 0;
    while (head != -1) {
        cnt++;
        Node[head].flag = true;
        head = Node[head].next;
    }
    if(cnt == 0){
        printf("0 -1\n");
        return 0;
    }
    sort(Node, Node+MAXN, cmp);
    head = Node[0].address;
    printf("%d %05d\n",cnt,head);
    for (int i=0; i<cnt; ++i) {
        printf("%05d %d ",Node[i].address,Node[i].data);
        if(i != cnt-1) printf("%05d\n",Node[i+1].address);
        else printf("-1\n");
    }
    
}

