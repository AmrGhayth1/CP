#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<ll> ans(n+2, 0);               // input array
    for (int i = 1; i <= n; ++i) cin >> ans[i];

    vector<int> nxt(n+2, n+1);            // next smaller index
    {
        vector<int> st;
        for (int i = 1; i <= n; ++i) {
            while (!st.empty() && ans[i] < ans[st.back()]) {
                nxt[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
    }

    const int LOG = 20; // enough for n ≤ 1e5
    vector<vector<int>> up(LOG, vector<int>(n+2, n+1));
    vector<vector<ll>> sum(LOG, vector<ll>(n+2, 0));
    vector<vector<ll>> len(LOG, vector<ll>(n+2, 0));

    for (int i = 1; i <= n; ++i) {
        up[0][i] = nxt[i];
        len[0][i] = nxt[i] - i;
        sum[0][i] = ans[i] * 1LL * len[0][i];
    }
    up[0][n+1] = n+1; len[0][n+1] = 0; sum[0][n+1] = 0;

    for (int k = 1; k < LOG; ++k) {
        for (int i = 1; i <= n+1; ++i) {
            int mid = up[k-1][i];
            up[k][i] = up[k-1][mid];
            len[k][i] = len[k-1][i] + len[k-1][mid];
            sum[k][i] = sum[k-1][i] + sum[k-1][mid];
        }
    }

    while (q--) {
        int l, r; cin >> l >> r;
        r = r - k + 1 ; 
        ll remaining = r - l + 1;
        ll ans2 = 0;
        int node = l;

        for (int k = LOG-1; k >= 0; k--) {
            if (node > n) break;
            if (len[k][node] <= remaining) {
                ans2 += sum[k][node];
                remaining -= len[k][node];
                node = up[k][node];
            }
        }
        if (remaining > 0 && node <= n) {
            ans2 += ans[node] * 1LL * remaining;
            remaining = 0;
        }
        cout << ans2 << '\n';
    }

    return 0;
}
