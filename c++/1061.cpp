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

string DAY[] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int hour[30];
int day[30];
string a,b,c,d;
vector<char> v1,v2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(hour, 0, sizeof(hour));
    memset(day,0,sizeof(day));
    cin >> a >> b>> c>> d;
    int len = (int)min(a.size(), b.size());
    string dd;
    int h;
    int m;
    int i;
    for (i=0; i<len; ++i) {
        if(a[i] == b[i]){
            if(a[i] >='A' && a[i]<='G'){
                dd = DAY[a[i]-'A'];
                break;
            }
        }
    }
    for (i=i+1; i<len; ++i) {
        if(a[i] == b[i]){
            if(a[i]>='0' && a[i]<='9'){
                h = a[i]-'0';
                break;
            }
            else if (a[i]>='A' && a[i]<='N'){
                h = a[i]-'A'+10;
                break;
            }
        }
    }
    len = (int)min(c.size(),d.size());
    for (i=0; i<len; ++i) {
        if(c[i] == d[i]){
            if(c[i]>='a' && c[i]<='z'){
                m = i;
                break;
            }else if(c[i]>='A' && c
                     [i]<='Z'){
                m = i;
                break;
            }
        }
    }
    cout << dd <<" ";
    printf("%02d:%02d",h,m);
}
