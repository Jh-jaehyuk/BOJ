//
//  29736.cpp
//  BOJ
//
//  Created by 한재혁 on 2023/09/11.
//


#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int A, B, K, X;
    cin >> A >> B >> K >> X;
    
    int result = 0;
    
    for (int i = A; i <= B; i++) {
        if (abs(K - i) <= X) {
            result++;
        }
    }
    
    if (result == 0) {
        cout << "Impossible" << "\n";
    }
    
    else {
        cout << result << "\n";
    }
    
    return 0;
}
