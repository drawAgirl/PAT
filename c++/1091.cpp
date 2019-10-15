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
int m,n,l,t,a;
int cnt = 0;
int MAP[61][1290][129] = {0};
bool vis[61][1290][129] = {false};
int direction[6][3] = {{1,0,0},{-1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
int now = 0;
struct node{
    int i,j,k;
};

int main(){
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(int i=0;i<l;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<n;++k){
                scanf("%d",&MAP[i][j][k]);
            }
        }
    }
    for(int i=0;i<l;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<n;++k){
                if (MAP[i][j][k] == 1) {
                    vis[i][j][k] = true;
                    queue<node> q;
                    q.push({i,j,k});
                    now = 0;
                    while (q.size()) {
                        int size = (int)q.size();
                        while (size--) {
                            now++;
                            node cur = q.front();
                            q.pop();
                            for(int d=0;d<6;++d){
                                int x = cur.i + direction[d][0];
                                int y = cur.j + direction[d][1];
                                int z = cur.k + direction[d][2];
                                if(x<0 || y<0 || z<0 || x>=l || y>=m || z>=n ||MAP[x][y][z] == 0 || vis[x][y][z]==true) continue;

                                q.push({x,y,z});
                                MAP[x][y][z] = 0;
                            }
                        }
                    }
                    if(now < t) continue;
                    cnt += now;
                }
            }
        }
    }
    printf("%d",cnt);
}
