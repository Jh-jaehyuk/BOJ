//
//  3015.cpp
//  BOJ
//
//  Created by J213h on 10/19/23.
//

#include <bits/stdc++.h>

using namespace std;

static stack<pair<int, int>> mystack;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    long long result = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        while (!mystack.empty() && mystack.top().first < x) {
            result += mystack.top().second;
            mystack.pop();
        }
        
        if (mystack.empty()) {
            mystack.push(make_pair(x, 1));
            continue;
        }
        
        if (mystack.top().first == x) {
            int tmp = mystack.top().second;
            mystack.pop();
            result += tmp;
            
            if (!mystack.empty()) {
                result++;
            }
            
            mystack.push(make_pair(x, tmp + 1));
        }
        
        else {
            mystack.push(make_pair(x, 1));
            result++;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}
