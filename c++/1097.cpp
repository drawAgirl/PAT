//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/25.
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

const int MAXN = 1e5+10;
int head,n;
unordered_map<int, bool> dic;

struct node{
    int address;
    int data;
    int next;
    int order = MAXN;
    int category = MAXN; // 1=原始数据 2=需要删除数据
}Node[MAXN];

bool cmp(node &a,node &b){
    if (a.category != b.category) return a.category < b.category;
    return a.order < b.order;
}


int main(){
    scanf("%d%d",&head,&n);
    for(int i=0;i<n;++i){
        int cur,data,next;
        scanf("%d%d%d",&cur,&data,&next);
        Node[cur].address = cur;
        Node[cur].data = data;
        Node[cur].next = next;
    }
    int cnt = 0;
    int first = 0;
    while (head != -1) {
        Node[head].order = cnt++;
        if(dic.find(abs(Node[head].data)) == dic.end()){
            first++; // 不删除的结点 数量
            Node[head].category = 1;
            dic[abs(Node[head].data)] = true;
        }else Node[head].category = 2;
        head = Node[head].next;
    }
    sort(Node, Node+MAXN, cmp);
    if (first != cnt) {
        for (int i=0; i<first; ++i) {
            if ( i != first - 1)
                printf("%05d %d %05d\n",Node[i].address,Node[i].data,Node[i+1].address);
            else
                printf("%05d %d -1\n",Node[i].address,Node[i].data);
        }
        for (int i=first;i<cnt;++i){
            if( i != cnt-1)
                printf("%05d %d %05d\n",Node[i].address,Node[i].data,Node[i+1].address);
            else
                printf("%05d %d -1\n",Node[i].address,Node[i].data);
        }
    }else{
        for(int i=0;i<cnt;++i){
            if( i != cnt-1)
                printf("%05d %d %05d\n",Node[i].address,Node[i].data,Node[i+1].address);
            else
                printf("%05d %d -1\n",Node[i].address,Node[i].data);
        }
    }
    
}
