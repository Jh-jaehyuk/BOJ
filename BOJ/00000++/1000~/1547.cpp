//
//  1547.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int M;
    cin >> M;
    
    int result = 1;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a == result) {
            result = b;
        }
        
        else if (b == result) {
            result = a;
        }
    }
    cout << result << "\n";
    
    return 0;
}
