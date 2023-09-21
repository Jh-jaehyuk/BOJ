//
//  7453.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

static int A[4000];
static int B[4000];
static int C[4000];
static int D[4000];

static vector<int> AB, CD;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AB.push_back(A[i] + B[j]);
            CD.push_back(C[i] + D[j]);
        }
    }
    
    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());
    
    int l = (int)AB.size();
    long long result = 0;
    for (int i = 0; i < l; i++) {
        auto iter1 = equal_range(AB.begin(), AB.end(), AB[i]);
        auto iter2 = equal_range(CD.begin(), CD.end(), -AB[i]);
        auto d1 = distance(iter1.first, iter1.second);
        auto d2 = distance(iter2.first, iter2.second);
        
        result += 1LL * d1 * d2;
        i += (d1 - 1);
    }
    cout << result << "\n";
    
    return 0;
}
