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

set<int> s;
int n;

int main(){
    scanf("%d",&n);
    char a[5];
    for(int i=0;i<n;++i){
        scanf("%s",a);
        int len = (int)strlen(a);
        int temp=0;
        for(int j=0;j<len;++j) temp += a[j]-'0';
        s.insert(temp);
    }
    printf("%d\n",(int)s.size());
    int space = 0;
    for(auto &each:s){
        space++;
        printf("%d",each);
        if(space != s.size()) printf(" ");
    }
}
