//
//  29813.cpp
//  BOJ
//
//  Created by J213h on 2023/09/16.
//

#include <bits/stdc++.h>

using namespace std;

static deque<string> mydeque;
static map<string, int> mymap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string name;
        int num;
        cin >> name >> num;
        mymap.insert({ name, num - 1 });
        mydeque.push_back(name);
    }
    
    while (mydeque.size() > 1) {
        string name = mydeque.front();
        mydeque.pop_front();
        
        int l = (int)mydeque.size();
        for (int i = 0; i < mymap[name] % l; i++) {
            string temp = mydeque.front();
            mydeque.pop_front();
            mydeque.push_back(temp);
        }
        
        mydeque.pop_front();
    }
    
    cout << mydeque.front() << "\n";
    
    return 0;
}

