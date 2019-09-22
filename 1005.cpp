#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string print1[10] ={"zero","one","two","three","four","five","six","seven","eight","nine"}; 
int numPrint[101];
int main(){
	char num[101];
	scanf("%s",num);
	int len = strlen(num);
	int sum = 0;
	for(int i=0 ;i<len ;i++){
		sum += num[i]-'0';
	}
 
	if(sum==0){	//如果是0 直接输出zero 即可 
		printf("zero\n");
	}else{
		int n=0;
		while(sum>10){
			numPrint[n] = sum%10;
			sum /= 10;
			n++;
		}
		numPrint[n] = sum; //别忘了处理最后一位 
		
		for(int i=n ;i>=0 ;i--){
 
			if(i==n){
				cout<<print1[numPrint[i]];
			}else{
				cout<<" "<<print1[numPrint[i]];
			}
		}
		printf("\n");
	}
	
	
	
	return 0;
}
