//
//  2002.cpp
//  BOJ
//
//  Created by J213h on 2023/09/16.
//

#include <bits/stdc++.h>

using namespace std;

static map<string, int> mymap;
static int check[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    fill(check, check + 1001, 0);
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        mymap.insert({ s, i });
    }
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        check[i] = mymap[s];
    }
    
    int result = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (check[i] > check[j]) {
                result++;
                break;
            }
        }
    }
    cout << result << "\n";
    
    return 0;
}
