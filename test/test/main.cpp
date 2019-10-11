//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/11.
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
string earths[] = {"tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov","dec"};
string mars[] = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int to_int(string s){
    int ans =0;
    for(int i=0;i<(int)s.size();++i){
        ans = ans*10 + s[i]-'0';
    }
    return ans;
}
int main(){
    string s;
    scanf("%d%*c",&n);
    while (n--) {
        getline(cin,s);
        if(s[0]>='0' && s[0] <='9'){
            int cur = to_int(s);
            if(cur >= 13){
                int d = cur % 13;
                cur/= 13;
                cout << mars[cur];
                if(d!=0) cout << " " << earths[d]<<"\n";
                else cout <<"\n";
                
            }else{
                cout << earths[cur] <<"\n";
            }
        }else{
            if(s.size() <= 4){
                for(int i=0;i<13;++i){
                    if(earths[i] == s){
                        printf("%d\n",i);
                        break;
                    }
                }
                for(int i=1;i<13;++i){
                    if(mars[i] == s){
                        printf("%d\n",i*13);
                        break;
                    }
                }
            }else{
                string d = s.substr(0,3);
                string e = s.substr(4,4);
                int i,j;
                for(i=0;i<13;++i){
                    if(mars[i] == d) break;
                }
                for(j=0;j<13;++j){
                    if(earths[j] == e) break;
                }
                printf("%d\n",13*i+j);
            }
        }
    }
}
