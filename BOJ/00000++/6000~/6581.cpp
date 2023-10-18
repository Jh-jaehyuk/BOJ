//
//  6581.cpp
//  BOJ
//
//  Created by J213h on 10/18/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    int count = 0;
    
    while (cin >> s) {
        if (s == "<br>") {
            cout << "\n";
            count = 0;
        }
        
        else if (s == "<hr>") {
            if (count != 0) {
                cout << "\n";
            }
            for (int i = 0; i < 80; i++) {
                cout << '-';
            }
            cout << "\n";
            count = 0;
        }
        
        else {
            if (count + (int)s.size() + 1 > 80) {
                cout << "\n";
                count = 0;
            }
            
            if (count != 0) {
                cout << ' ';
                count++;
            }
            
            cout << s;
            count += (int)s.size();
        }
    }
    
    return 0;
}
