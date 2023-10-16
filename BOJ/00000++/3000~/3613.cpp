//
//  3613.cpp
//  BOJ
//
//  Created by J213h on 10/16/23.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    getline(cin, s);
    
    int ss = (int)s.size();
    if (isupper(s[0]) || s[0] == '_' || s[ss - 1] == '_') {
        cout << "Error!" << "\n";
        return 0;
    }

    bool underbar = false;
    bool upper = false;
    
    for (int i = 0; i < ss; i++) {
        if (isupper(s[i])) {
            upper = true;
        }
        
        if (s[i] == '_') {
            underbar = true;
            
            if (i > 0 && s[i - 1] == '_') {
                cout << "Error!" << "\n";
                return 0;
            }
        }
    }
    
    if (underbar && upper) {
        cout << "Error!" << "\n";
    }
    
    else if (underbar && !upper) {
        for (int i = 0; i < ss; i++) {
            if (s[i] == '_') {
                continue;
            }
            
            if (i > 0 && s[i - 1] == '_') {
                cout << (char)(s[i] - 32);
                continue;
            }
            cout << s[i];
        }
    }
    
    else if (!underbar && upper) {
        for (int i = 0; i < ss; i++) {
            if (isupper(s[i])) {
                cout << '_' << (char)(s[i] + 32);
                continue;
            }
            cout << s[i];
        }
    }
    
    else {
        cout << s << "\n";
    }
    
    return 0;
}
