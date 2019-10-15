
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


map<string,set<int>> title,author,key_word,publisher,year;


int n,m,id;

void query(map<string,set<int>>& data,string &str){
    if(data.find(str) != data.end()){
        for(auto each:data[str]) printf("%07d\n",each);
    }else
        printf("Not Found\n");
}

int main(){
    cin >> n;
    string a,b,c,d,e;
    for(int i=0;i<n;++i){
        scanf("%d\n",&id);
        getline(cin,a);
        title[a].insert(id);
        getline(cin,b);
        author[b].insert(id);
        while (cin >> c) {
            key_word[c].insert(id);
            char ch = getchar();
            if(ch=='\n') break;
        }
        getline(cin,d);
        publisher[d].insert(id);
        getline(cin,e);
        year[e].insert(id);
    }
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        int category;
        scanf("%d: ",&category);
        getline(cin,a);
        cout << category << ": "<<a <<"\n";
        if(category == 1) query(title, a);
        else if (category == 2)query(author, a);
        else if(category == 3) query(key_word, a);
        else if(category==4)query(publisher, a);
        else query(year, a);
    }
}
