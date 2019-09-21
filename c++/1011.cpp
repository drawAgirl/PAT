//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/21.
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
#include <string.h>
using namespace std;

double first[3];
double second[3];
double third[3];

int main(){
    for (int i=0; i<3; i++)
        scanf("%lf",&first[i]);
    for (int i=0; i<3; i++)
        scanf("%lf",&second[i]);
    for (int i=0; i<3; i++) 
        scanf("%lf",&third[i]);
    double *a = max_element(first, first+3);
    double *b = max_element(second, second+3);
    double *c = max_element(third, third+3);
    double profit = (*a**b**c*0.65-1)*2;
    char s[3] = {'W','T','L'};
    printf("%c %c %c ",s[a-first],s[b-second],s[c-third]);
    printf("%.2lf",profit);
}
