//
//  30090.cpp
//  BOJ
//
//  Created by J213h on 2023/09/22.
//

#include <bits/stdc++.h>

using namespace std;

static int N;
static vector<string> A;

int Check(const string &a, const string &b);
int Solve(vector<string> &A, int count, string tmp);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string x;
        cin >> x;
        A.push_back(x);
    }
    
    cout << Solve(A, 0, "") << "\n";
    
    return 0;
}

int Check(const string &a, const string &b) {
    int a_sz = (int)a.size();
    int b_sz = (int)b.size();
    
    for (int k = min(a_sz, b_sz); k >= 1; k--) {
        if (equal(a.end() - k, a.end(), b.begin())) {
            return k;
        }
    }
    
    return 0;
}

int Solve(vector<string> &A, int count, string tmp) {
    if (count == N) {
        return (int)tmp.length();
    }
    
    int Min = (int)1e9;
    
    for (int i = count; i < N; i++) {
        int K = Check(tmp, A[i]);
        swap(A[count], A[i]);
        Min = min(Min, Solve(A, count + 1, tmp + A[count].substr(K)));
        swap(A[count], A[i]);
    }
    
    return Min;
}
