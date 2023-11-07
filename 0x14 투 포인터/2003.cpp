#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> sum; // 누적합

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    sum.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    int st = 0, en = 0;
    int ans = 0;
    while (en <= n) {
        int tmp = sum[en] - sum[st];
        if (tmp <= m) {
            if (tmp == m) ans++;
            en++;
        }
        else st++;
    }

    cout << ans;
}
