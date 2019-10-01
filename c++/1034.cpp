#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <queue>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cctype>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


const int MAXN = 2010;
const int INF = 0x7fffffff;

map<int,string> intostring;
map<string,int> stringtoint;
map<string,int> gang;
int G[MAXN][MAXN] = { 0};
int weight[MAXN] = { 0 };
int n,k,numperson = 0;
bool vis[MAXN] = { false };

void dfs(int nowVisit,int &head,int &nummember,int &total){
    nummember++;
    vis[nowVisit] = true;
    if (weight[nowVisit] > weight[head]) {
        head = nowVisit;
    }
    for (int i=0; i<numperson; i++) {
        if(G[nowVisit][i] > 0){
            total += G[nowVisit][i];
            G[nowVisit][i] = G[i][nowVisit] = 0;
            if(vis[i] == false) dfs(i, head, nummember, total);
        }
    }
}

void trave(){
    for (int i=0; i<numperson; i++) {
        if (vis[i] == false) {
            int head = i,member = 0,total = 0;
            dfs(i,head,member,total);
            if (member > 2 && total > k) {
                gang[intostring[head]] = member;
            }
        }
    }
}

int change(string str){
    if (stringtoint.find(str) != stringtoint.end()) {
        return stringtoint[str];
    }else{
        stringtoint[str] = numperson;
        intostring[numperson] = str;
        return numperson++;
    }
}

int main(){
    int w;
    string s1,s2;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> s1>>s2>>w;
        int id1 = change(s1);
        int id2 = change(s2);
        weight[id1] +=w;
        weight[id2] +=w;
        G[id1][id2] +=w;
        G[id2][id1] +=w;
    }
    trave();
    cout << gang.size() << endl;
    for (auto it=gang.begin(); it != gang.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
