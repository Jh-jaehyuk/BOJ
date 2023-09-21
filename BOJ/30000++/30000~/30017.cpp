//
//  30017.cpp
//  BOJ
//
//  Created by J213h on 2023/09/19.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    
    if (a > b) {
        cout << b + 1 + b << "\n";
    }
    
    else {
        cout << a + a - 1 << "\n";
    }
    
    return 0;
}
