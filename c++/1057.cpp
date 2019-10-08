#include <cstdio>
#include <cstring>
#include <stack>
#include <string>
#include <algorithm>
#include <iostream>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int MAXN = 100010;
int c[MAXN];
stack<int> st;
void update(int x,int v){
    for(int i=x;i<MAXN;i+=lowbit(i))
        c[i] += v;
}
int getSum(int x){
    int sum = 0;
    for(int i=x;i>0;i-=lowbit(i))
        sum += c[i];
    return sum;
}
void Peek(){
    int l=  1,r = MAXN,mid,k = (st.size()+1)/2;
    while (l < r) {
        mid = (l+r) / 2;
        if(getSum(mid) >= k) r= mid;
        else l = mid+1;
    }
    printf("%d\n",l);
}

int main(){
    int n;
    scanf("%d%*c",&n);
    fill(c, c+MAXN, 0);
    for(int i=0;i<n;i++){
        string str;
        getline(cin,str);
        if(str[1] == 'o'){
            if(st.empty())
                printf("Invalid\n");
            else{
                int val = st.top(); st.pop();
                printf("%d\n",val);
                update(val, -1);
            }
        }else if( str[1] == 'u'){
            int val = 0;
            for(int i=5;i<str.size();i++){
                val = val*10+(str[i]-'0');
            }
            st.push(val);
            update(val,1);
        }else {
            if(st.empty())
                printf("Invalid\n");
            else{
                Peek();
            }
        }
    }
}

