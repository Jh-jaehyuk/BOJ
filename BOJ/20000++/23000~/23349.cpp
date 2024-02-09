//
//  23349.cpp
//  BOJ
//
//  Created by J213h on 2/2/24.
//

#include <bits/stdc++.h>

using namespace std;

int N, a, b;
string name, place;
map<string, int[50001]> M;
set<string> Name, Place;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> name >> place >> a >> b;
        
        if (Name.find(name) != Name.end()) {
            continue;
        }
        
        Name.insert(name);
        Place.insert(place);
        
        for (int j = a; j < b; j++) {
            M[place][j]++;
        }
    }
    
    int Max = -1;
    string Mplace = "";
    for (auto iter = Place.begin(); iter != Place.end(); iter++) {
        string now = *iter;
        int tmp = *max_element(M[now], M[now] + 50000);
        
        if (Max >= tmp) {
            continue;
        }
        
        Max = tmp;
        Mplace = now;
    }
    
    int start = -1;
    int end = -1;
    for (int i = 0; i < 50001; i++) {
        if (M[Mplace][i] == Max) {
            if (start == -1) {
                start = i;
            }
        }
        
        if (start != -1 && M[Mplace][i] != Max) {
            end = i;
            break;
        }
    }
    
    cout << Mplace << " " << start << " " << end << "\n";
    
    return 0;
}
