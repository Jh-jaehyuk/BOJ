//
//  2457.cpp
//  BOJ
//
//  Created by J213h on 2023/09/21.
//

#include <bits/stdc++.h>

using namespace std;

static int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static int prefix_month[13] = { 0 };
static vector<pair<int, int>> A;

pair<int, int> change(pair<int, int> s, pair<int, int> e);
bool cmp(pair<int, int> i, pair<int, int> j);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 1; i < 13; i++) {
        prefix_month[i] = prefix_month[i - 1] + month[i];
    }
    
    for (int i = 0; i < N; i++) {
        pair<int, int> s, e;
        cin >> s.first >> s.second >> e.first >> e.second;
        
        pair<int, int> tmp = change(s, e);
        A.push_back(tmp);
    }
    
    sort(A.begin(), A.end(), cmp);
    
    int result = 1;
    int Start = A[0].first;
    int End = A[0].second;
    int tmp = prefix_month[2] + 1;
    
    for (int i = 1; i < N; i++) {
        if (A[i].first <= tmp && A[i].second > tmp) {
            if (End < A[i].second) {
                End = A[i].second;
            }
        }
        
        else {
            if (A[i].first <= End && A[i].second > End) {
                result++;
                tmp = End;
                End = A[i].second;
            }
        }
        
        if (End > prefix_month[11]) {
            break;
        }
    }
    
    if (Start <= prefix_month[2] + 1 && End > prefix_month[11]) {
        cout << result << "\n";
    }
    
    else {
        cout << 0 << "\n";
    }
    
    return 0;
}

pair<int, int> change(pair<int, int> s, pair<int, int> e) {
    int Start = prefix_month[s.first - 1] + s.second;
    int End = prefix_month[e.first - 1] + e.second;
    
    return make_pair(Start, End);
}

bool cmp(pair<int, int> i, pair<int, int> j) {
    if (i.first == j.first) {
        return i.second > j.second;
    }
    
    else {
        return i.first < j.first;
    }
}
