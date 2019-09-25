//
//  main.cpp
//  test
//
//  Created by 李寻欢 on 2019/9/25.
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
using namespace std;
//这题抄的柳神,tql.
const int MAXN = 1e5+10;
int main() {
    int first, k, n, sum = 0;
    cin >> first >> n >> k;
    int temp, data[MAXN], next[MAXN], list[MAXN], result[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    for (int i = 0; i < sum; i++) result[i] = list[i];//复制一份，这样最后不翻转的可以直接输出
    for (int i = 0; i < (sum - sum % k); i++) //处理前面翻转部分
        result[i] = list[i / k * k + k - 1 - i % k]; // i/k*k=每份翻转片段起始位置
    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
    return 0;
}
