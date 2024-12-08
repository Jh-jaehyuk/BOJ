#include <bits/stdc++.h>

using namespace std;

string S, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        S += c;
    }
    
    int s = 0;
    int e = N - 1;
    
    while (s <= e) {
        if (S[s] < S[e]) {
            T += S[s];
            s++;
        }
        else if (S[s] > S[e]) {
            T += S[e];
            e--;
        }
        else {
            int ns = s + 1;
            int ne = e - 1;
            int flag = 0;
            while (ns <= ne) {
                if (S[ns] < S[ne]) {
                    break;
                }
                else if (S[ns] > S[ne]) {
                    flag = 1;
                    break;
                }
                else {
                    ns++;
                    ne--;
                }
            }
            
            if (!flag) {
                T += S[s];
                s++;
            }
            else {
                T += S[e];
                e--;
            }
        }
    }
    
    int cnt = 0;
    for (auto i: T) {
        cout << i;
        if (++cnt % 80 == 0) {
            cout << "\n";
        }
    }
}
