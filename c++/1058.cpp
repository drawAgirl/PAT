//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/22.
//  Copyright © 2019 李寻欢. All rights reserved.
//
#include <cstdio>
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




int main(){
    int a,b,c;
    int x,y,z;
    scanf("%d.%d.%d",&a,&b,&c);
    scanf("%d.%d.%d",&x,&y,&z);
    int r = (c+z)%29;
    int q = ((c+z)/29 + b+y)%17;
    int p = a+x+((c+z)/29+b+y)/17;
    printf("%d.%d.%d",p,q,r);
}
