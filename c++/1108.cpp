//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/13.
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

int n;


int main(){
    scanf("%d",&n);
    double ans = 0,temp =0;
    int cnt = 0;
    char a[50],b[50];
    for(int i=0;i<n;++i){
        scanf("%s",a);
        sscanf(a,"%lf", &temp);
        sprintf(b, "%.2f",temp);
        bool flag = false;
        int len = (int)strlen(a);
        for(int j=0;j<len;++j){
            if(a[j] != b[j]){
                flag = true;
                break;
            }
        }
        if (flag || temp>1000 || temp < -1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }else{
            ans += temp;
            cnt++;
        }
    }
    if(cnt == 1)
        printf("The average of 1 number is %.2f", ans);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, ans / cnt);
    else
        printf("The average of 0 numbers is Undefined");

}
  