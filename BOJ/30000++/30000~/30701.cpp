//
//  30701.cpp
//  BOJ
//
//  Created by J213h on 1/19/24.
//

#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9 + 1;
int N;
long long D;
vector<int> M;
vector<int> E;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> D;
    
    for (int i = 0; i < N; i++) {
        int A, X;
        cin >> A >> X;
        
        if (A == 1) {
            M.push_back(X);
        }
        else {
            E.push_back(X);
        }
    }
    
    sort(M.begin(), M.end());
    sort(E.begin(), E.end());
    
    int midx = 0;
    int eidx = 0;
    int count = 0;
    
    while (midx < M.size()) {
        if (D > INF) {
            D = INF;
        }

        if (D > M[midx]) {
            D += M[midx];
            midx++;
            count++;
        }
        
        else {
            if (eidx == E.size()) {
                break;
            }
            
            else {
                D *= E[eidx];
                eidx++;
                count++;
            }
        }
    }
    
    cout << count + (E.size() - eidx) << "\n";
    
    return 0;
}
