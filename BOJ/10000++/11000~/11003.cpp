//
//  11003.cpp
//  BOJ
//
//  Created by J213h on 10/18/23.
//

#include <bits/stdc++.h>

using namespace std;

static deque<pair<int, int>> mydeque;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, L;
    cin >> N >> L;
    
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        
        while (!mydeque.empty() && mydeque.back().first > x) {
            mydeque.pop_back();
        }
        
        mydeque.push_back(make_pair(x, i));
        
        if (mydeque.front().second <= i - L) {
            mydeque.pop_front();
        }
        
        cout << mydeque.front().first << " ";
    }
    
    return 0;
}
