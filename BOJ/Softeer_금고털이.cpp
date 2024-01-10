//
//  Softeer_금고털이.cpp
//  Softeer
//
//  Created by J213h on 12/30/23.
//


#include <bits/stdc++.h>

using namespace std;

static vector<pair<int, int>> V;

bool cmp(pair<int, int> i, pair<int, int> j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int W, N;
    cin >> W >> N;
    
    V.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }
    
    sort(V.begin(), V.end(), cmp);
    
    long long result = 0;
    
    for (int i = 0; i < N; i++) {
        if (W >= V[i].first) {
            result += V[i].first * V[i].second;
            W -= V[i].first;
        }
        
        else {
            result += W * V[i].second;
            break;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

bool cmp(pair<int, int> i, pair<int, int> j) {
    if (i.second != j.second) {
        return i.second > j.second;
    }
    
    return i.first > j.first;
}

