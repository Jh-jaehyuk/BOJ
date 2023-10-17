//
//  1969.cpp
//  BOJ
//
//  Created by J213h on 10/17/23.
//

#include <bits/stdc++.h>

using namespace std;

static int A[1001][51];
static int check[51][4];
static map<int, char> icmap = { { 0, 'A' }, { 1, 'C' }, { 2, 'G' }, { 3, 'T' } };
static map<char, int> cimap = { { 'A', 0 }, { 'C', 1 }, { 'G', 2 }, { 'T', 3 } };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        
        for (int j = 0; j < M; j++) {
            A[i][j] = cimap[tmp[j]];
        }
    }
    
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            check[j][A[i][j]]++;
        }
    }
    
    string result = "";
    int dist = 0;
    for (int i = 0; i < M; i++) {
        int Max = *max_element(check[i], check[i] + 4);
        dist += (N - Max);
        
        for (int j = 0; j < 4; j++) {
            if (check[i][j] == Max) {
                result += icmap[j];
                break;
            }
        }
    }
    
    cout << result << "\n" << dist << "\n";
    
    return 0;
}
