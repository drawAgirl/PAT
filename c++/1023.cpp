//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/29.
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

int arr[30];
int cnt[10];
int double_num(string n){
    int len = (int)n.size();
    int temp=0;
    int index=0;
    for(int i=len-1;i>=0;--i){
        cnt[n[i]-'0']++;
        int add = 2*(n[i]-'0')+temp;
        temp = add / 10;
        arr[index++] = add%10;
        cnt[arr[index-1]]--;
    }
    if(temp != 0) arr[index++] = temp;
    return index;
}
int main(){
    string n;
    cin >> n;
    int len = (int)n.size();
    int index = double_num(n);
    if(index != len) printf("No\n");
    else{
        bool flag = true;
        for(int i=0;i<10;++i){
            if(cnt[i] != 0){
                flag = false;
                break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    for(int i=index-1;i>=0;--i) printf("%d",arr[i]);

}
