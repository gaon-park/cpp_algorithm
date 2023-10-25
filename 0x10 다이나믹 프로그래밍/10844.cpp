#include <iostream>

using namespace std;

long long dp[105][10]; 
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i < 10; i++) dp[1][i] = 1; // 초기화
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				dp[i][j] += dp[i - 1][j - 1] % 1'000'000'000;
				dp[i][j] %= 1'000'000'000;
			}
			if (j + 1 < 10) {
				dp[i][j] += dp[i - 1][j + 1] % 1'000'000'000;
				dp[i][j] %= 1'000'000'000;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= 1'000'000'000;
	}
	cout << sum;
}
