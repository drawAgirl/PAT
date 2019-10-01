#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 100010;
int arr[MAXN];
int main() {
    int n,p;
    scanf("%d%d",&n,&p);
    for (int i=0; i<n; i++) {
        scanf("%d",&arr[i]);
    }
    sort(arr, arr+n);
    int max_len = 0;
    for (int i=0; i<n; i++) {
        int pos = upper_bound(arr+i, arr+n, (long long)arr[i]*p)-&arr[i];
        max_len = max(pos,max_len);
    }
    printf("%d\n",max_len);
}
