//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/10/4.
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


struct gas_station {
    double price;
    double distance;
}station[510];

bool cmp(gas_station a,gas_station b){
    if(a.distance != b.distance)
        return a.distance < b.distance;
    return a.price < b.price;
}

int main(){
    int tank,distance,unit,number;
    scanf("%d%d%d%d",&tank,&distance,&unit,&number);
    for (int i=0; i<number; i++) {
        scanf("%lf%lf",&station[i].price,&station[i].distance);
    }
    station[number].price = 0;
    station[number].distance = distance;
    sort(station, station+number, cmp);
    if(station[0].distance > 0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int now = 0;
    double ans = 0,nowtank=0,MAX = tank*unit;
    while (now < number) {
        int k = -1;
        double pricemin = 10000;
        for (int i=now+1; i<=number && station[i].distance - station[now].distance <= MAX; i++) {
            if (station[i].price < pricemin) {
                pricemin = station[i].price;
                k = i;
            }
            if (pricemin < station[now].price) {
                break;
            }
        }
        if (k == -1) {
            break;
        }
        double need = (station[k].distance - station[now].distance) / unit;
        if (pricemin < station[now].price) {
            if (nowtank < need) {
                ans += (need - nowtank)*station[now].price;
                nowtank = 0;
            }else{
                nowtank -= need;
            }
        }else{
            ans += (tank - nowtank)*station[now].price;
            nowtank = tank - need;
        }
        now = k;
    }
    if (now == number) {
        printf("%.2f\n",ans);
    }else
        printf("The maximum travel distance = %.2f\n",station[now].distance + MAX);
}


