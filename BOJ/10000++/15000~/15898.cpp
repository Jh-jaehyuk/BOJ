//
//  15898.cpp
//  BOJ
//
//  Created by J213h on 2023/09/23.
//

#include <bits/stdc++.h>

using namespace std;

static int n;
static vector<vector<pair<int, char>>> board(5, vector<pair<int, char>>(5, make_pair(0, 'W')));
static vector<vector<pair<int, char>>> _board(5, vector<pair<int, char>>(5, make_pair(0, 'W')));
static vector<vector<vector<pair<int, char>>>> A;

vector<vector<pair<int, char>>> rotate_90(vector<vector<pair<int, char>>> V);

void RESET(vector<vector<pair<int, char>>>) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            _board[i][j] = board[i][j];
        }
    }
}

void Attach(vector<vector<pair<int, char>>> &_board, vector<vector<pair<int, char>>> g);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    A.resize(n);
    for (int i = 0; i < n; i++) {
        vector<vector<pair<int, char>>> v;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> v[j][k].first;
            }
        }
        
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> v[j][k].second;
            }
        }
        
        A[i] = v;
    }
    
    return 0;
}

vector<vector<pair<int, char>>> rotate_90(vector<vector<pair<int, char>>> V) {
    vector<vector<pair<int, char>>> tmp(5, vector<pair<int, char>>(5, make_pair(0, 0)));
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i][j].first = V[4 - j - 1][i].first;
            tmp[i][j].second = V[4 - j - 1][i].second;
        }
    }
    
    return tmp;
}
