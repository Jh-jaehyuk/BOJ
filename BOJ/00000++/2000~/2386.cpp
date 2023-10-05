//
//  2386.cpp
//  BOJ
//
//  Created by J213h on 2023/10/02.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while (true) {
        char x;
        cin >> x;
        
        if (x == '#') {
            break;
        }
        
        cin.ignore();
        string s;
        getline(cin, s);
        
        int count = 0;
        for (char i : s) {
            if (x == i || x == i + 32) {
                count++;
            }
        }
        
        cout << x << " " << count << "\n";
    }
    
    return 0;
}
