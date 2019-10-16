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

const int MAXN = 1e5;
int n;
bool vis[MAXN] = {false};
vector<int> v;
struct node{
    int id;
    vector<int> children;
    set<int> parents;
    int number_of_estate=0;
    int total_area_estate=0;
}Node[MAXN];
struct family{
    int small_root;
    int members;
    double avg_number_estate;
    double avg_area_estate;
    family(){
        small_root = MAXN;
        members = 0;
        avg_area_estate = avg_number_estate = 0;
    }
};
vector<family> ans;

bool cmp(family &a,family &b){
    if(a.avg_area_estate != b.avg_area_estate) return a.avg_area_estate > b.avg_area_estate;
    return a.small_root < b.small_root;
}


void dfs(int root,int &small_root,double &cur_number_estate,double &cur_total_estate,int &members){
    if(root == -1 || vis[root]) return;
    vis[root] = true;
    members++;
    small_root = min(small_root,root);
    cur_number_estate += Node[root].number_of_estate;
    cur_total_estate += Node[root].total_area_estate;
    for(auto &child:Node[root].children)
        dfs(child, small_root, cur_number_estate, cur_total_estate,members);
    for(auto &parent:Node[root].parents)
        dfs(parent, small_root, cur_number_estate, cur_total_estate, members);
}

int main(){
    scanf("%d",&n);
    int id,father,monther,child,k;
    for(int i=0;i<n;++i){
        scanf("%d%d%d%d",&id,&father,&monther,&k);
        v.emplace_back(id);
        Node[id].id = id;
        Node[id].parents.insert(father);
        Node[id].parents.insert(monther);
        Node[father].children.emplace_back(id);
        Node[monther].children.emplace_back(id);
        while (k--) {
            scanf("%d",&child);
            Node[id].children.emplace_back(child);
            Node[child].parents.insert(id);
        }
        scanf("%d%d",&Node[id].number_of_estate,&Node[id].total_area_estate);
    }
    for(auto &root:v){
        family temp;
        dfs(root, temp.small_root, temp.avg_number_estate, temp.avg_area_estate,temp.members);
        if(temp.small_root == MAXN) continue;
        temp.avg_number_estate /= temp.members;
        temp.avg_area_estate /= temp.members;
        ans.emplace_back(temp);
    }
    sort(ans.begin(), ans.end(), cmp);
    printf("%d\n",(int)ans.size());
    for(auto &fa:ans){
        printf("%04d %d %.3f %.3f\n",fa.small_root,fa.members,fa.avg_number_estate,fa.avg_area_estate);
    }
    
}
