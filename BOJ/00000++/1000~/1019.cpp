// 참고 : https://restudycafe.tistory.com/489
//  1019.cpp
//  BOJ
//
//  Created by J213h on 2023/09/23.
//

#include <bits/stdc++.h>

using namespace std;

static int N;
static int Check[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    fill(Check, Check + 10, 0);
    
    int tmp = 0;
    
    for (int i = 1; N != 0; i *= 10) {
        int _N = N % 10; // 현재 수의 일의 자리
        N /= 10; // 일의 자리를 제외한 나머지
        
        // 계산의 편의를 위해 계산 전, 맨 앞에 '0'이 오는 경우를 미리 빼줌.
        Check[0] -= i;
        
        // 일의 자리 숫자 전까지는 (N + 1) * i
        for (int j = 0; j < _N; j++) {
            Check[j] += (N + 1) * i;
        }
        
        // 일의 자리 숫자는 별도의 계산이 필요
        Check[_N] += N * i + 1 + tmp;
        
        // 일의 자리 이후는 N * i
        for (int j = _N + 1; j <= 9; j++) {
            Check[j] += N * i;
        }
        
        // 별도의 계산이 필요한 부분을 연산
        tmp += _N * i;
    }
    
    for (int i = 0; i <= 9; i++) {
        cout << Check[i] << " ";
    }
    
    return 0;
}

