#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> adj[1000005];
int isused[1000005];
int dp[2][1000005];

void solve(int st) {
	isused[st] = 1;
	dp[0][st] = 1; // 얼리어답터일 때
	for (int nxt : adj[st]) {
		if (isused[nxt]) continue;
		solve(nxt);
		dp[0][st] += min(dp[0][nxt], dp[1][nxt]); // 자식이 얼리어답터일 때와, 아닐 때를 모두 더해줌
		dp[1][st] += dp[0][nxt]; // 자식이 얼리어답터가 아닐 때를 모두 더해줌
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve(1);
	cout << min(dp[0][1], dp[1][1]);
}
