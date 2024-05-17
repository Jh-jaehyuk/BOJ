//
//  1484.cpp
//  BOJ
//
//  Created by J213h on 5/14/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            int temp = j * (2 * i + j);
            if (temp == N) {
                ans.push_back(i + j);
            }
            else if (temp > N) {
                break;
            }
        }
    }
    if (ans.empty()) {
        cout << -1 << "\n";
    }
    else {
        sort(ans.begin(), ans.end());
        for (int i: ans) {
            cout << i << "\n";
        }
    }

    return 0;
}

// (a + b)^2 - a^2 = 2ab + b^2 = G
// b(2a + b) = G

