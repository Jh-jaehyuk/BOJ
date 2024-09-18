//
//  32247.cpp
//  BOJ
//
//  Created by J213h on 9/18/24.
//

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int c, x, h;
    
    bool operator < (const Node &
                     temp) const {
        return x < temp.x;
    }
};

vector<Node> V;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        Node temp;
        cin >> temp.c >> temp.x >> temp.h;
        V.push_back(temp);
    }
    
    sort(V.begin(), V.end());
    
    int now_x = 0;
    int now_h = 0;
    
    int flag = 0;
    for (Node i: V) {
        int c, x, h;
        c = i.c;
        x = i.x;
        h = i.h;
        
        if (!c) {
            if (now_h > h) {
                now_h = max(h + 1, now_h - (x - now_x));
            }
            else {
                now_h = h + 1;
            }
        }
        else {
            if (now_h < h) {
                now_h -= (x - now_x);
            }
            else {
                if ((now_h - h) >= (x - now_x)) {
                    flag = 1;
                    break;
                }
                else {
                    now_h -= (x - now_x);
                }
            }
        }
        now_x = x;
    }
    
    if (now_h > 0) {
        if (N - now_x < now_h) {
            flag = 1;
        }
    }
    
    cout << (flag ? "adios" : "stay") << "\n";

    return 0;
}
