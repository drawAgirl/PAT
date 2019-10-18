//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/18.
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

int hashtable[100010];
int main(){
    int n;
    scanf("%d",&n);
    fill(hashtable, hashtable+100010, 1);
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if (a > 0 && a<100010) {
            hashtable[a] = 0;
        }
    }
    for (int i=1; i<100010; i++) {
        if (hashtable[i] == 1) {
            printf("%d",i);
            break;
        }
    }
    
}

