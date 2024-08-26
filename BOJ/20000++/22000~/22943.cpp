//
//  22943.cpp
//  BOJ
//
//  Created by J213h on 8/26/24.
//

#include <bits/stdc++.h>

using namespace std;

int K, M;
int cnt[10];
vector<int> prime;
int ans;
set<int> num;

void DFS(string now, int length) {
    if (length == K) {
        num.insert(stoi(now));
        return;
    }
    
    for (int i = 0; i < 10; i++){
        if (!length && !i) {
            continue;
        }
        if (cnt[i]) {
            continue;
        }
        cnt[i] = 1;
        DFS(now + to_string(i), length + 1);
        cnt[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> K >> M;
    
    for (int i = 2; i < 100001; i++) {
        int flag = 0;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (!flag) {
            prime.push_back(i);
        }
    }
    
    DFS("", 0);
    
    int ps = (int)prime.size();
    for (int i: num) {
        int s = 0;
        int e = ps - 1;
        
        int flag1 = 0;
        int flag2 = 0;
        
        while (s < e) {
            int x = prime[s] + prime[e];
            
            if (x == i) {
                flag1 = 1;
                break;
            }
            else if (x < i) {
                s++;
            }
            else {
                e--;
            }
        }
        
        int temp = i;
        while (temp % M == 0) {
            temp /= M;
        }
        
        s = 0;
        e = ps - 1;
        while (s <= e) {
            long long x = 1LL * prime[s] * prime[e];
            
            if (x == 1LL * temp) {
                flag2 = 1;
                break;
            }
            else if (x < 1LL * temp) {
                s++;
            }
            else {
                e--;
            }
        }
        
        if (flag1 && flag2) {
            ans++;
        }
    }
    cout << ans << "\n";
    
    return 0;
}
