#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];
        string x; cin >> x;

        // quick checks
        bool any1 = false;
        for (char c: x) if (c == '1') any1 = true;
        if (!any1) { cout << 0 << '\n'; continue; }

        if (x[0] == '1' || x[n-1] == '1') { // endpoints can never be set
            cout << -1 << '\n';
            continue;
        }

        bool impossible = false;
        for (int i = 0; i < n; ++i) {
            if (x[i] == '1' && (p[i] == 1 || p[i] == n)) {
                // global min/max value can never be strictly between two values
                impossible = true;
                break;
            }
        }
        if (impossible) { cout << -1 << '\n'; continue; }

        vector<char> covered(n, 0);
        vector<pair<int,int>> ops;

        auto all_covered = [&]() {
            for (int i = 0; i < n; ++i) if (x[i] == '1' && !covered[i]) return false;
            return true;
        };

        int attempts = 0;
        bool fail = false;
        while (!all_covered() && attempts < 5) {
            // find leftmost uncovered required index
            int i = -1;
            for (int j = 0; j < n; ++j) if (x[j] == '1' && !covered[j]) { i = j; break; }
            if (i == -1) break;

            // try to find l < i with p[l] < p[i] and r > i with p[r] > p[i]
            int l = -1, r = -1;
            for (int L = i-1; L >= 0; --L) {
                if (p[L] < p[i]) { l = L; break; }
            }
            for (int R = i+1; R < n; ++R) {
                if (p[R] > p[i]) { r = R; break; }
            }

            if (l == -1 || r == -1) {
                // try opposite orientation: left > p[i] and right < p[i]
                int l2 = -1, r2 = -1;
                for (int L = i-1; L >= 0; --L) {
                    if (p[L] > p[i]) { l2 = L; break; }
                }
                for (int R = i+1; R < n; ++R) {
                    if (p[R] < p[i]) { r2 = R; break; }
                }
                if (l2 == -1 || r2 == -1) {
                    fail = true;
                    break;
                } else {
                    l = l2; r = r2;
                }
            }

            // apply operation [l,r] (1-based in output)
            ops.emplace_back(l+1, r+1);

            int mn = min(p[l], p[r]);
            int mx = max(p[l], p[r]);
            for (int j = l+1; j <= r-1; ++j) {
                if (p[j] > mn && p[j] < mx) covered[j] = 1;
            }
            attempts++;
        }

        if (fail || !all_covered()) {
            cout << -1 << '\n';
        } else {
            cout << ops.size() << '\n';
            for (auto &pr : ops) cout << pr.first << ' ' << pr.second << '\n';
        }
    }
    return 0;
}
