//
//  4994.cpp
//  BOJ
//
//  Created by J213h on 1/23/24.
//

#include <bits/stdc++.h>

using namespace std;

set<long long> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    queue<string> myqueue;
    myqueue.push("1");
    S.insert(1);
    
    while (!myqueue.empty()) {
        string now = myqueue.front();
        myqueue.pop();
        
        for (char i: { '0', '1' }) {
            string next = now + i;
            
            if (next.size() > 19) {
                continue;
            }
            
            long long llnext = stoll(next);
            if (S.find(llnext) != S.end()) {
                continue;
            }
            
            S.insert(llnext);
            myqueue.push(next);
        }
    }
    
    while (true) {
        int N;
        cin >> N;
        
        if (N == 0) {
            break;
        }
        
        for (auto iter = S.begin(); iter != S.end(); iter++) {
            if (*iter % N == 0) {
                cout << *iter << "\n";
                break;
            }
        }
    }
    
    return 0;
}

