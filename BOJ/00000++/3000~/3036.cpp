//
//  3036.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    int First;
    cin >> First;
    
    for (int i = 0; i < N - 1; i++) {
        int x;
        cin >> x;
        
        int g = gcd(x, First);
        cout << First / g << '/' << x / g << "\n";
    }
    
    return 0;
}
