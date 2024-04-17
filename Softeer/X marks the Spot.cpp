#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string S, T;
        cin >> S >> T;
        
        int length = (int)S.size();
        for (int j = 0; j < length; j++) {
            if (S[j] == 'x' || S[j] == 'X') {
                if (T[j] >= '0' && T[j] <= '9') {
                    cout << (char)T[j];
                }

                else {
                    cout << (char)toupper(T[j]);
                }
                break;
            }
        }
    }

    return 0;
}
