//
//  24912.cpp
//  BOJ
//
//  Created by J213h on 1/27/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000001];
vector<int> result;

int get_val(int idx) {
    int tmp = 1;
    int check[4] = { 0, 0, 0, 0 };
    
    if (idx - 1 >= 0) {
        check[A[idx - 1]]++;
    }
    
    if (idx + 1 < N) {
        check[A[idx + 1]]++;
    }
    
    for (int i = 1; i <= 3; i++) {
        if (!check[i]) {
            tmp = i;
            break;
        }
    }

    A[idx] = tmp;
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; i++) {
        if (A[i]) {
            result.push_back(A[i]);
        }
        else {
            result.push_back(get_val(i));
        }
    }
    
    for (int i = 0; i < N - 1; i++) {
        if (result[i] == result[i + 1]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}

