//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/16.
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

struct node{
    int num, cnt;
    node(int num, int cnt):num(num),cnt(cnt){}
    bool operator < (const node &a)const{ // 重载运算符
        return cnt != a.cnt ? cnt > a.cnt : num < a.num;
    }
};
set<node> s;
int times[50001]={0}, n, k;
int main(){
    scanf("%d%d",&n,&k);
    int num;
    for(int i = 0; i < n; i++){
        scanf("%d",&num);
        if(i){
            printf("%d:",num);
            int cnts = 0; // 记录输出的次数
            for(auto it = s.begin(); cnts < k && it != s.end(); it++){
                printf(" %d",it->num);
                cnts++;
            }
            printf("\n");
        }
        auto it = s.find(node(num,times[num])); // 判断set中是否存在
        if(it != s.end()) s.erase(it);
        times[num]++; // 更新浏览次数
        s.insert(node(num,times[num]));
    }
    return 0;
}
