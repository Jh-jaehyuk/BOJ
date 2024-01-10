//
//  31001.cpp
//  BOJ
//
//  Created by J213h on 1/10/24.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> group;
set<string> stock;
map<string, long long> companies;
map<string, int> mymap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    long long M;
    cin >> N >> M >> Q;
    
    group.resize(101);
    
    for (int i = 0; i < N; i++) {
        int G, P;
        string H;
        cin >> G >> H >> P;
        group[G].push_back(H);
        companies[H] = P;
    }
    
    for (int q = 0; q < Q; q++) {
        int command;
        cin >> command;
        
        if (command == 1) {
            string A;
            int B;
            cin >> A >> B;
            
            if (M < companies[A] * B) {
                continue;
            }
            
            M -= companies[A] * B;
            mymap[A] += B;
            stock.insert(A);
        }
        
        else if (command == 2) {
            string A;
            int B;
            cin >> A >> B;
            
            if (!mymap[A]) {
                continue;
            }
            
            int val = min(mymap[A], B);
            mymap[A] -= val;
            if (!mymap[A]) {
                stock.erase(A);
            }
            M += val * companies[A];
        }
        
        else if (command == 3) {
            string A;
            int C;
            cin >> A >> C;
            
            companies[A] += C;
        }
        
        else if (command == 4) {
            int D, C;
            cin >> D >> C;
            
            for (string A: group[D]) {
                companies[A] += C;
            }
        }
        
        else if (command == 5) {
            int D, E;
            cin >> D >> E;
            
            for (string A: group[D]) {
                companies[A] = companies[A] * (100 + E) / 100;
                companies[A] -= companies[A] % 10;
            }
        }
        
        else if (command == 6) {
            cout << M << "\n";
        }
        
        else {
            long long result = M;
            for (set<string>::iterator iter = stock.begin(); iter != stock.end(); iter++) {
                string A = *iter;
                result += companies[A] * mymap[A];
            }
            cout << result << "\n";
        }
    }

    return 0;
}
