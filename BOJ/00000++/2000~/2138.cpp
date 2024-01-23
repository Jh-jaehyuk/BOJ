//
//  2138.cpp
//  BOJ
//
//  Created by J213h on 1/23/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
int before[100001];
int after[100001];
int result = 1e9;

void Change(int tmp[100001], int idx) {
    tmp[idx] = ~tmp[idx] & 1;
    
    if (idx > 0) {
        tmp[idx - 1] = ~tmp[idx - 1] & 1;
    }
    
    if (idx < N - 1) {
        tmp[idx + 1] = ~tmp[idx + 1] & 1;
    }
}

bool Check(int tmp[100001]) {
    for (int i = 0; i < N; i++) {
        if (tmp[i] != after[i]) {
            return false;
        }
    }
    return true;
}

void Solve(int flag) {
    int tmp[100001];
    int count = 0;
    for (int i = 0; i < N; i++) {
        tmp[i] = before[i];
    }
    
    if (!flag) {
        Change(tmp, 0);
        count++;
    }
    
    for (int i = 1; i < N; i++) {
        if (tmp[i - 1] != after[i - 1]) {
            Change(tmp, i);
            count++;
        }
    }
    
    if (Check(tmp)) {
        result = min(result, count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        char tmp;
        cin >> tmp;
        before[i] = tmp - '0';
    }
    
    for (int i = 0; i < N; i++) {
        char tmp;
        cin >> tmp;
        after[i] = tmp - '0';
    }
    
    Solve(0);
    Solve(1);
    
    cout << (result == 1e9 ? -1 : result) << "\n";
    
    return 0;
}

