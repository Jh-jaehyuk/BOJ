//
//  16120.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

static stack<char> mystack;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int l = (int)s.size();
    
    for (int i = 0; i < l; i++) {
        if (mystack.empty()) {
            mystack.push(s[i]);
            continue;
        }
        
        if (mystack.size() >= 3) {
            string tmp = "";
            
            for (int j = 0; j < 3; j++) {
                tmp += mystack.top();
                mystack.pop();
            }
            
            if (tmp != "APP" || s[i] != 'P') {
                for (int k = 2; k >= 0; k--) {
                    mystack.push(tmp[k]);
                }
                mystack.push(s[i]);
            }
            
            else {
                mystack.push('P');
            }
        }
        
        else {
            mystack.push(s[i]);
        }
    }
    
    cout << (mystack.size() > 1 || mystack.top() == 'A' ? "NP" : "PPAP") << "\n";
    
    return 0;
}
