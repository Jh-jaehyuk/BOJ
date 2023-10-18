//
//  6198.cpp
//  BOJ
//
//  Created by J213h on 10/18/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<int> V;
static stack<pair<int, int>> mystack;
static long long result = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        V.push_back(x);
    }
    
    for (int i = N - 1; i >= 0; i--) {
        int count = 0;
        
        if (mystack.empty()) {
            mystack.push(make_pair(V[i], count));
            continue;
        }
        
        while (!mystack.empty()) {
            if (mystack.top().first < V[i]) {
                count += mystack.top().second + 1;
                mystack.pop();
            }
            
            else {
                mystack.push(make_pair(V[i], count));
                break;
            }
        }
        
        if (mystack.empty()) {
            mystack.push(make_pair(V[i], count));
        }
        
        result += count;
    }
    
    cout << result << "\n";
    
    return 0;
}
