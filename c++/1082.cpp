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


string number[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
//string radix[] = {"Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi"};
string radix[] = {"Shi","Bai","Qian","Wan","Yi"};
int main(){
    string str;
    getline(cin,str);
    int len = (int)str.size();
    int left= 0,right= len-1;
    if(str[0] == '-'){
        printf("Fu");
        left++;
    }
    while(left+4 <= right){
        right -= 4;
    }
    while(left < len){
        bool flag = false;
        bool isprint = false;
        while(left <= right){
            if(left > 0 && str[left]=='0') flag = true;
            else{
                if(flag){
                    printf(" ling");
                    flag = false;
                }
                
                if(left > 0) printf(" ");
                cout << number[str[left]-'0'];
                isprint = true;
                if(left != right){
                    cout <<" " <<radix[right-left-1];
                }
            }
            left++;
        }
        if(isprint && right!=len-1){
            cout << " " <<radix[(len-1-right)/4+2];
        }
        right+=4;
    }
}
