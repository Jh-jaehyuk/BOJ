//
//  2623.cpp
//  BOJ
//
//  Created by J213h on 10/12/23.
//

#include <bits/stdc++.h>

using namespace std;

static vector<vector<int>> A;
static vector<int> indegree;
static queue<int> myqueue;
static vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    A.resize(N + 1);
    indegree.resize(N + 1);
    
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        vector<int> tmp;
        
        for (int j = 0; j < num; j++) {
            int x;
            cin >> x;
            tmp.push_back(x);
        }
        
        for (int j = 0; j < num - 1; j++) {
            A[tmp[j]].push_back(tmp[j + 1]);
            indegree[tmp[j + 1]]++;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            myqueue.push(i);
        }
    }
    
    while (!myqueue.empty()) {
        int now = myqueue.front();
        myqueue.pop();
        result.push_back(now);
        
        for (int next : A[now]) {
            indegree[next]--;
            
            if (indegree[next] == 0) {
                myqueue.push(next);
            }
        }
    }
    
    if (result.size() != N) {
        cout << 0 << "\n";
    }
    
    else {
        for (int i : result) {
            cout << i << "\n";
        }
    }
    
    return 0;
}
