//
//  30013.cpp
//  BOJ
//
//  Created by J213h on 2023/09/24.
//

#include <bits/stdc++.h>

using namespace std;

int Check(string s, int freq);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    string s;
    cin >> s;
    
    int Min = 2001;
    
    for (int i = 1; i <= N; i++) {
        Min = min(Min, Check(s, i));
    }
    
    cout << Min << "\n";
    
    return 0;
}

int Check(string s, int freq) {
    int result = 0;
    
    int ss = (int)s.size();
    for (int i = 0; i < ss; i++) {
        if (s[i] == '#') {
            if (i < freq) {
                result++;
            }
            
            else {
                if (s[i - freq] == '.') {
                    result++;
                }
            }
        }
    }
    
    return result;
}
