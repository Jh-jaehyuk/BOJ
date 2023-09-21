//
//  15736.cpp
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
    
    int result = 0;
    
    for (int i = 1; i * i <= N; i++) {
        result++;
    }
    
    cout << result << "\n";
    
    return 0;
}
