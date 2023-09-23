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

vector<vector<pair<int, char>>> rotate_90(vector<vector<pair<int, char>>> &V);

void RESET(vector<vector<pair<int, char>>> &_board) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            _board[i][j] = make_pair(0, 'W');
        }
    }
}

void Attach(vector<vector<pair<int, char>>> &_board, vector<vector<pair<int, char>>> g, int x, int y);

int calculate(vector<vector<pair<int, char>>> &_board);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    A.resize(n);
    for (int i = 0; i < n; i++) {
        vector<vector<pair<int, char>>> v(4, vector<pair<int, char>>(4, make_pair(0, 'W')));
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
    
    int Max = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                
                for (int a = 0; a < 4; a++) {
                    for (int b = 0; b < 4; b++) {
                        for (int c = 0; c < 4; c++) {
                            
                            for (int p = 0; p < 4; p++) {
                                for (int q = 0; q < 4; q++) {
                                    for (int r = 0; r < 4; r++) {
                                        RESET(_board);
                                        Attach(_board, A[i], a / 2, a % 2);
                                        Attach(_board, A[j], b / 2, b % 2);
                                        Attach(_board, A[k], c / 2, c % 2);
                                        
                                        int score = calculate(_board);
                                        if (Max < score) {
                                            Max = score;
                                        }
                                        A[k] = rotate_90(A[k]);
                                    }
                                    A[j] = rotate_90(A[j]);
                                }
                                A[i] = rotate_90(A[i]);
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << Max << "\n";
    
    return 0;
}

vector<vector<pair<int, char>>> rotate_90(vector<vector<pair<int, char>>> &V) {
    vector<vector<pair<int, char>>> tmp(4, vector<pair<int, char>>(4, make_pair(0, 'W')));
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            tmp[i][j].first = V[4 - j - 1][i].first;
            tmp[i][j].second = V[4 - j - 1][i].second;
        }
    }
    
    return tmp;
}

void Attach(vector<vector<pair<int, char>>> &_board, vector<vector<pair<int, char>>> g, int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num = g[i][j].first;
            int color = g[i][j].second;
            
            _board[x + i][y + j].first += num;
            
            if (_board[x + i][y + j].first > 9) {
                _board[x + i][y + j].first = 9;
            }
            
            if (_board[x + i][y + j].first < 0) {
                _board[x + i][y + j].first = 0;
            }
            
            if (color != 'W') {
                _board[x + i][y + j].second = color;
            }
        }
    }
}

int calculate(vector<vector<pair<int, char>>> &_board) {
    int R = 0;
    int B = 0;
    int G = 0;
    int Y = 0;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (_board[i][j].second == 'R') {
                R += _board[i][j].first;
            }
            
            if (_board[i][j].second == 'B') {
                B += _board[i][j].first;
            }
            
            if (_board[i][j].second == 'G') {
                G += _board[i][j].first;
            }
            
            if (_board[i][j].second == 'Y') {
                Y += _board[i][j].first;
            }
        }
    }
    
    int score = (7 * R) + (5 * B) + (3 * G) + (2 * Y);
    return score;
}
