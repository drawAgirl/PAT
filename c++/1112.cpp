//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/14.
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
//抄的某大佬的 https://www.cnblogs.com/chenxiwenruo/p/6131165.html
const int MAXN = 1010;
int k;
char str[MAXN];
unordered_map<char,int> maps; //一开始都为0，表示为stucked keys
int main()
{
    scanf("%d%*c",&k);
    scanf("%s",str);
    int len=(int)strlen(str);
    char ch;
    int cnt;
    for(int i=0;i<len;i+=cnt){
        ch=str[i];
        int p=i;
        for(;ch==str[p+1];p++);
        cnt=p-i+1;
        if(cnt%k!=0){
            maps[ch]=1; //如果连续出现的次数不是k的倍数，显然不是stucked keys，标记为1
        }
    }
    char ans[MAXN];
    char stucked[MAXN];
    int idx=0,idx2=0;;
    cnt=0;
    for(int i=0;i<len;i+=cnt){
        if(maps[str[i]]==1){
            ans[idx++]=str[i];
            cnt=1;
        }
        else{
            int p=i;
            //若stucked keys第一次出现对应的map为0，之后标记为2
            if(maps[str[i]]!=2){
                stucked[idx2++]=str[i];
                maps[str[i]]=2;
            }
            for(;str[i]==str[p+1];p++);
            cnt=p-i+1;
            for(int j=0;j<cnt/k;j++){
                ans[idx++]=str[i];
            }
        }
    }
    ans[idx]='\0';
    stucked[idx2]='\0';
    printf("%s\n",stucked);
    printf("%s",ans);
    return 0;
}
