//
//  9250.cpp
//  BOJ
//
//  Created by J213h on 10/23/23.
//

#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie *go[26];
    Trie *fail;
    bool output;
    
    Trie() {
        fill(go, go + 26, nullptr);
        output = false;
    }
    
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (go[i]) {
                delete go[i];
            }
        }
    }
    
    void insert(const char* key) {
        if (*key == '\0') {
            output = true;
            return;
        }
        
        int next = *key - 'a';
        if (!go[next]) {
            go[next] = new Trie;
        }
        
        go[next] -> insert(key + 1);
    }
};

static queue<Trie*> myqueue;
static char str[10001];

void Solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    
    Trie* root = new Trie;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> str;
        root -> insert(str);
    }
    
    root -> fail = root;
    myqueue.push(root);
    
    while (!myqueue.empty()) {
        Trie* now = myqueue.front();
        myqueue.pop();
        
        for (int i = 0; i < 26; i++) {
            Trie* next = now -> go[i];
            
            if (!next) {
                continue;
            }
            
            if (now == root) {
                next -> fail = root;
            }
            
            else {
                Trie* parent = now -> fail;
                
                while (parent != root && !parent -> go[i]) {
                    parent = parent -> fail;
                }
                
                if (parent -> go[i]) {
                    parent = parent -> go[i];
                }
                next -> fail = parent;
            }
            
            if (next -> fail -> output) {
                next -> output = true;
            }
            
            myqueue.push(next);
        }
    }
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> str;
        
        Trie* now = root;
        bool result = false;
        
        for (int j = 0; str[j]; j++) {
            int next = str[j] - 'a';
            
            while (now != root && !now -> go[next]) {
                now = now -> fail;
            }
            
            if (now -> go[next]) {
                now = now -> go[next];
            }
            
            if (now -> output) {
                result = true;
                break;
            }
        }
        cout << (result ? "YES" : "NO") << "\n";
    }
    delete root;
    
    return 0;
}
