//
//  30090.cpp
//  BOJ
//
//  Created by J213h on 2023/09/22.
//

#include <bits/stdc++.h>

using namespace std;

static int N, result = (int)1e9;
static int length_sum = 0;
static string A[10];
static bool visited[10];

int check(string a, string b);
void DFS(int idx, int depth, int tmp);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        length_sum += (int)A[i].size();
    }
    
//    for (int i = 0; i < N; i++) {
//        fill(visited, visited + 10, false);
//        visited[i] = true;
//        DFS(i, 1, 0);
//    }
    fill(visited, visited + 10, false);
    DFS(0, 1, 0);
    
    cout << result << "\n";
    
    return 0;
}

int check(string a, string b) {
    int a_sz = (int)a.size();
    int b_sz = (int)b.size();
    
    for (int k = min(a_sz, b_sz); k >= 1; k--) {
        bool flag = false;
        for (int i = 0; i < k; i++) {
            if (a[a_sz - k + i] != b[i]) {
                flag = true;
                break;
            }
        }
        
        if (!flag) {
            return k;
        }
    }
    
    return 0;
}

void DFS(int idx, int depth, int tmp) {
    if (depth == N) {
        result = min(result, length_sum - tmp);
        return;
    }
    
    for (int i = idx + 1; i < N; i++) {
        if (!visited[i]) {
            int s = check(A[idx], A[i]);
            if (s != 0) {
                visited[i] = true;
                DFS(i, depth + 1, tmp + s);
                visited[i] = false;
            }
        }
    }
}
