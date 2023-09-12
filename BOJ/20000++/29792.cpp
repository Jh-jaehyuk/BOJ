//
//  29792.cpp
//  BOJ
//
//  Created by J213h on 2023/09/11.
//

#include <bits/stdc++.h>

using namespace std;

static vector<long long> Character;
static vector<pair<long long, long long>> Boss;

bool cmp(long long i, long long j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        Character.push_back(x * 15 * 60);
    }
    
    sort(Character.begin(), Character.end(), cmp);
    
    for (int i = 0; i < K; i++) {
        long long P, Q;
        cin >> P >> Q;
        Boss.push_back(make_pair(P, Q));
    }
    
    
    
    
    return 0;
}

bool cmp(long long i, long long j) {
    return i > j;
}
