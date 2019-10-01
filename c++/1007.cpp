#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
int n;
int arr[MAXN];
int dp[MAXN];
int s[MAXN];

// dp[i] = max{arr[i],dp[i-1]+arr[i]}
// s[i] = {s[i-1],i}
int main(){
	bool flag = false;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
		if(arr[i] >= 0) flag = true; 
	}
	if(flag == false){
		printf("0 %d %d\n",arr[0],arr[n-1]);
		return 0;
	}
	dp[0] = arr[0];
	for (int i = 1; i < n; ++i){
		int a = dp[i-1] + arr[i];
		if(a > arr[i]){
			dp[i] = a;
			s[i] = s[i-1];
		}else{
			dp[i] = arr[i];
			s[i] = i;
			}
	}

	int k = 0;
	for (int i = 1; i < n; ++i)
	{
		if(dp[i] > dp[k])
			k = i;
	}
	printf("%d %d %d\n",dp[k],arr[s[k]],arr[k]);
	return 0;
}