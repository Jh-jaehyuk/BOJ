//
//  20207.cpp
//  BOJ
//
//  Created by J213h on 2/14/24.
//

#include <bits/stdc++.h>

using namespace std;

int N;
int day[366];
pair<int, int> A[1005];
int result = 0;

bool cmp(pair<int, int> &i, pair<int, int> &j) {
    if (i.first != j.first) {
        return i.first < j.first;
    }
    
    else {
        return i.second - i.first > j.second - j.first;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        for (int j = A[i].first; j <= A[i].second; j++) {
            ++day[j];
        }
    }
    
    sort(A, A + N, cmp);
    A[N] = { 370, 370 };
    
    pair<int, int> now = A[0];
    for (int i = 1; i <= N; i++) {
        pair<int, int> next = A[i];
        
        if (next.first <= now.second + 1) {
            now.second = max(now.second , next.second);
        }
        
        else {
            int length = now.second - now.first + 1;
            int height = *max_element(day + now.first, day + now.second + 1);

            result += length * height;
            now = next;
        }
    }
    
    cout << result << "\n";
    
    return 0;
}

