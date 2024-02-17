//
//  1711.cpp
//  BOJ
//
//  Created by J213h on 2/17/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
pair<long long, long long> A[1501];
vector<pair<long long, long long>> V;
int result = 0;

long long get_dist(pair<long long, long long> i, pair<long long, long long> j) {
    long long x1 = i.first;
    long long y1 = i.second;
    long long x2 = j.first;
    long long y2 = j.second;
    
    return ((x2 - x1) * (x2 -  x1) + (y2 - y1) * (y2 - y1));
}

bool check(long long d1, long long d2, long long d3) {
    long long Max = max(d1, max(d2, d3));
    
    if (2 * Max == d1 + d2 + d3) {
        return true;
    }
    return false;
}

void DFS(int idx) {
    if (V.size() == 3) {
        long long d1 = get_dist(V[0], V[1]);
        long long d2 = get_dist(V[0], V[2]);
        long long d3 = get_dist(V[1], V[2]);
        
        if (check(d1, d2, d3)) {
            ++result;
        }
        return;
    }
    
    else if (idx == N) {
        return;
    }
    
    else {
        V.push_back(A[idx]);
        DFS(idx + 1);
        V.pop_back();
        DFS(idx + 1);
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    
    DFS(0);
    cout << result << "\n";

    return 0;
}

