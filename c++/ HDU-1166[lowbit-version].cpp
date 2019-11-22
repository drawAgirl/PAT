// C++ program to show segment tree operations like construction, query
// and update
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;

#define lowbit(x) (x&(-x))

const int maxn = 50010;

int arr[maxn];
int t,n;
string str;
int getsum(int x){
    int sum = 0;
    for(int i=x;i>0;i-=lowbit(i)) sum += arr[i];
    return sum;
}

void update(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        arr[i] +=v;
    }
}

int main(){
//    printf("123\n");
    
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        scanf("%d",&n);
        memset(arr, 0, sizeof(arr));
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            update(i,a);
        }
        printf("Case %d:\n",k);
        string str;
        while (cin >> str) {
            if(str=="Query"){
                int a,b;
                scanf("%d%d",&a,&b);
                printf("%d\n",getsum(b)-getsum(a-1));
            }else if(str == "Add"){
                int a,b;
                scanf("%d%d",&a,&b);
                update(a,b);
            }else if(str == "Sub"){
                int a,b;
                scanf("%d%d",&a,&b);
                update(a,-b);
            }else break;
        }
    }
    
}