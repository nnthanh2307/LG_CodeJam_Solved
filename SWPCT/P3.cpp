#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

static int a = []() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

int N;
vector<int> W;

void InputData(void) {
	cin >> N;
	W.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
}

int solve() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (j == i + 1) {
				ret++;
			} else {
				int temp = min(W[i], W[j]);
				bool flag = true;
				for (int k = i + 1; k < j; k++) {
					if (W[k] >= temp) {
						flag = false; break;
					}
				}
				if (flag) ret++;
			}
		}
	}
	
	return ret;
}

int main(void) {
	int ans = -1;
	InputData();
	ans = solve();
	cout << ans << endl;

	return 0;
}
