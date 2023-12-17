#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;
vector<int> vec, brute;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> k;
		if (!k) break;
		
		vec.assign(k, 0);
		brute.assign(k, 1);

		for (int i = 0; i < k; i++) {
			cin >> vec[i];
			if (i < 6) brute[i] = 0;
		}
		sort(vec.begin(), vec.end());

		do {
			for (int i = 0; i < k; i++) {
				if (!brute[i]) cout << vec[i] << " ";
			}
			cout << "\n";
		} while (next_permutation(brute.begin(), brute.end()));
		cout << "\n";
	}
}
