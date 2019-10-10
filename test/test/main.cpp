//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/10.
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
const int MAXN = 4e4+10;
int n,m,k;
int school;
int quota[110];
struct node{
    int exam;
    int view;
    double total;
    int rank;
    int id;
    vector<int> school;
}Node[MAXN];


bool cmp(node &a,node &b){
    if(a.total != b.total) return a.total > b.total;
    return a.exam > b.exam;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;++i) scanf("%d",&quota[i]);
    for(int i=0;i<n;++i){
        scanf("%d%d",&Node[i].exam,&Node[i].view);
        Node[i].id = i;
        Node[i].total = (Node[i].exam + Node[i].view)/2;
        for(int j=0;j<k;++j){
            scanf("%d",&school);
            Node[i].school.push_back(school);
        }
    }
    sort(Node, Node+n, cmp);
    int rank = 1;
    Node[0].rank = rank++;
    map<int, vector<int>> dic;
    for(int i=1;i<n;++i){
        if(Node[i].total != Node[i-1].total) Node[i].rank = rank;
        else{
            if(Node[i].exam != Node[i-1].exam) Node[i].rank = rank;
            else Node[i].rank = Node[i-1].rank;
        }
        rank++;
    }
    rank = 1;
    int pre[110] = {0};//比较排名是否相同
    dic[Node[0].school[0]].push_back(Node[0].id);
    quota[Node[0].school[0]]--;
    pre[Node[0].school[0]] = Node[0].rank;
    for(int i=1;i<n;++i){
        for(auto &want:Node[i].school){
            if(quota[want] > 0){
                quota[want]--;
                dic[want].push_back(Node[i].id);
                pre[want] = max(pre[want],Node[i].rank);
                break;
            }else{
                if(pre[want] == Node[i].rank){
                    quota[want]--;
                    dic[want].push_back(Node[i].id);
                    break;
                }
            }
        }
        
    }
    for(int i=0;i<m;++i){
        if(dic[i].size() != 0){
            sort(dic[i].begin(), dic[i].end());
            for(int j=0;j<(int)dic[i].size();++j){
                printf("%d",dic[i][j]);
                if(j != (int)dic[i].size()-1) printf(" ");
                else printf("\n");
            }
        }else printf("\n");
    }
}
