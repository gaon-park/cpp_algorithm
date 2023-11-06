#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, n, m;
vector<int> a, b;
vector<int> asum, bsum; // 누적합
vector<int> aSorted, bSorted; // 부 배열의 합으로 나올 수 있는 값을 정렬하여 저장

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> n;
    a.assign(n, 0);
    asum.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        asum[i] = i == 0 ? a[i] : asum[i - 1] + a[i];
    }
    for (int i = 0; i < asum.size(); i++) {
        aSorted.push_back(asum[i]);
        for (int j = 0; j < i; j++) {
            aSorted.push_back(asum[i] - asum[j]);
        }
    }
    sort(aSorted.begin(), aSorted.end());
    cin >> m;
    b.assign(m, 0);
    bsum.assign(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        bsum[i] = i == 0 ? b[i] : bsum[i - 1] + b[i];
    }
    for (int i = 0; i < bsum.size(); i++) {
        bSorted.push_back(bsum[i]);
        for (int j = 0; j < i; j++) {
            bSorted.push_back(bsum[i] - bsum[j]);
        }
    }
    sort(bSorted.begin(), bSorted.end());

    // A의 정렬된 값들을 순차로 탐색하면서 T보다 작을 때까지만 반복
    long long ans = 0;
    for (int i = 0; i < aSorted.size(); i++) {
        long long lidx = lower_bound(bSorted.begin(), bSorted.end(), T - aSorted[i]) - bSorted.begin();
        long long uidx = upper_bound(bSorted.begin(), bSorted.end(), T - aSorted[i]) - bSorted.begin();
        if (uidx - lidx > 0) {
            ans += uidx - lidx;
        }
    }

    cout << ans;
}
