#include <iostream>
#include <set>

using namespace std;

static set<int> myset;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;

		if (x == 1) {
			myset.insert(i + 1);
		}
	}
	int now = 1;

	while (Q--) {
		int x;
		cin >> x;

		if (x == 1) {
			int tmp;
			cin >> tmp;

			if (myset.find(tmp) != myset.end()) {
				myset.erase(tmp);
			}

			else {
				myset.insert(tmp);
			}
		}

		else if (x == 2) {
			int tmp;
			cin >> tmp;

			now = (now + tmp - 1) % N + 1;
		}

		else {
			if (myset.empty()) {
				cout << -1 << "\n";
			}

			else {
				auto iter = myset.lower_bound(now);

				if (iter == myset.end()) {
					cout << N - now + * myset.begin() << "\n";
				}

				else {
					cout << *iter - now << "\n";
				}
			}
		}
	}


	return 0;
  	}