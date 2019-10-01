
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <cstring>
#include <map>
#include <stack>

using namespace std;



int change(int a,int b){
    int arr[1000];
    int index = 0;
    while (a) {
        int d = a % b;
        arr[index++] = d;
        a = a / b;
    }
    int base = 0;
    int sum = 0;
    for (int i=index-1; i>=0; i--) {
        sum = arr[i]*pow(b, base) + sum;
        base++;
    }
    return sum;
}



bool isPrimer(int x){
    if (x <= 1) {
        return false;
    }
    for (int i=2; i<=sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
    int n,radix;
    while (scanf("%d",&n)!=EOF) {
        
        if (n < 0) {
            break;
        }
        scanf("%d",&radix);
        if (isPrimer(n)) {
            int a = change(n, radix);
            if (isPrimer(a)) {
                printf("Yes\n");
            }else
                printf("No\n");
        }else
            printf("No\n");
        
    }
    return 0;
}
