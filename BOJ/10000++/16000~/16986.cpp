//
//  16986.cpp
//  BOJ
//
//  Created by J213h on 10/11/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N, K;
static int A[10][10];
static int L[3][20];
static int win[3];
static int turn[3];
static int result = 0;

bool Check(int idx);
int Find_next(int a, int b);
void DFS(int a, int b);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int i = 0; i < 20; i++) {
        cin >> L[1][i];
    }
    
    for (int i = 0; i < 20; i++) {
        cin >> L[2][i];
    }
    
    DFS(0, 1);
    cout << result << "\n";
    
    return 0;
}

bool Check(int idx) {
    for (int i = 0; i < turn[0]; i++) {
        if (L[0][i] == idx) {
            return true;
        }
    }
    
    return false;
}

int Find_next(int a, int b) {
    if ((a == 0 && b == 1) || (a == 1 && b == 0)) {
        return 2;
    }
    
    else if ((a == 1 && b == 2) || (a == 2 && b == 1)) {
        return 0;
    }
    
    else {
        return 1;
    }
}

void DFS(int a, int b) {
    if (result) {
        return;
    }
    
    if (win[1] == K || win[2] == K) {
        return;
    }
    
    if (win[0] == K) {
        result = 1;
        return;
    }
    
    for (int i = 1; i <= N; i++) {
        if (a != 0 && b != 0) {
            i = N;
        }
        
        else {
            if (Check(i)) {
                continue;
            }
            
            L[0][turn[0]] = i;
        }
        
        int tmp = A[L[a][turn[a]]][L[b][turn[b]]];
        int Next = Find_next(a, b);
        int Winner;
        
        if (tmp == 0) {
            Winner = b;
        }
        
        else if (tmp == 2) {
            Winner = a;
        }
        
        else {
            if (a > b) {
                Winner = a;
            }
            
            else {
                Winner = b;
            }
        }
        
        turn[a]++;
        turn[b]++;
        win[Winner]++;
        DFS(Winner, Next);
        turn[a]--;
        turn[b]--;
        win[Winner]--;
    }
}
