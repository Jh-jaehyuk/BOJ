//
//  30973.cpp
//  BOJ
//
//  Created by J213h on 1/12/24.
//

#include <bits/stdc++.h>

using namespace std;

struct Tree {
    long long x, y, l;
};

int N;
Tree tree[50001];

long long get_val(long long x, long long y, Tree now);
long long get_distance(long long x, long long y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    long long xmin, ymin, xmax, ymax;
    cin >> N >> xmin >> ymin >> xmax >> ymax;
    
    long long xsum = 0, ysum = 0, lsum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> tree[i].x >> tree[i].y >> tree[i].l;
        
        xsum += tree[i].x * tree[i].l;
        ysum += tree[i].y * tree[i].l;
        lsum += tree[i].l;
    }
    
    if (lsum == 0) {
        cout << 0 << "\n";
        return 0;
    }
    long long xavg = xsum / lsum;
    long long yavg = ysum / lsum;
    long long result = 9e18;
    
    result = min(result, get_distance(xavg - 1, ymax + 1));
    result = min(result, get_distance(xavg, ymax + 1));
    result = min(result, get_distance(xavg + 1, ymax + 1));
    result = min(result, get_distance(xavg - 1, ymin - 1));
    result = min(result, get_distance(xavg, ymin - 1));
    result = min(result, get_distance(xavg + 1, ymin - 1));
    result = min(result, get_distance(xmax + 1, yavg - 1));
    result = min(result, get_distance(xmax + 1, yavg));
    result = min(result, get_distance(xmax + 1, yavg + 1));
    result = min(result, get_distance(xmin - 1, yavg - 1));
    result = min(result, get_distance(xmin - 1, yavg));
    result = min(result, get_distance(xmin - 1, yavg + 1));

    cout << result << "\n";
    
    return 0;
}

long long get_val(long long x, long long y, Tree now) {
    return now.l * ((x - now.x) * (x - now.x) + (y - now.y) * (y - now.y));
}

long long get_distance(long long x, long long y) {
    long long tmp = 0;
    for (int i = 0; i < N; i++)  {
        tmp += get_val(x, y, tree[i]);
    }
    return tmp;
}
