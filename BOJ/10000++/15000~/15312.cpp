//
//  15312.cpp
//  BOJ
//
//  Created by J213h on 10/17/23.
//

#include <bits/stdc++.h>

using namespace std;

static int A[26] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 };
static vector<int> V;
static vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b;
    cin >> a >> b;
    
    int ss = (int)a.size();
    
    for (int i = 0; i < ss; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                V.push_back(A[a[i] - 'A']);
            }
            else {
                V.push_back(A[b[i] - 'A']);
            }
        }
    }
    
    while (result.size() != 2) {
        result.clear();
        int vs = (int)V.size();

        for (int i = 0; i < vs - 1; i++) {
            result.push_back((V[i] + V[i + 1]) % 10);
        }
        
        V.clear();
        V = result;
    }
    
    cout << result[0] << result[1] << "\n";
    
    return 0;
}
