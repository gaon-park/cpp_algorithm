#include <bits/stdc++.h>

using namespace std;

vector<int> D;

int main() {
	int x;
	cin >> x;
	D.assign(x + 1, 0);
	D[0] = 0, D[1] = 0;
	for (int i = 2; i <= x; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
		if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
	}
	cout << D[x];
}