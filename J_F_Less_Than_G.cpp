#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl '\n'
#define v vector

#ifdef WASSIM
#include "debug.h"
#else
#define dbg(...)
#endif

int op(int a, int b) {
    return a | b;
}

int e() {
    return 0;
}

// O(nlog(n)), O(1)
template <class S, S (*op)(S, S), S (*e)()>
struct sparse_table {
    vector<vector<S>> d;

    sparse_table(vector<S>& a) {
        int n = a.size(), k = 1 + __lg(n);
        d.resize(k, vector<S>(n));
        copy(a.begin(), a.end(), d[0].begin());

        for (int i = 1; i <= k; i++)
            for (int j = 0; j + (1 << i) <= n; j++)
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
    }

    S prod(int l, int r) {
        if (l == r) return e();
        int i = __lg(r - l);
        return op(d[i][l], d[i][r - (1 << i)]);
    }
};

void solve() {
    int n; cin >> n;

    v<int> a(n), b(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    v<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i] * a[i];
    sparse_table<int, op, e> st(b);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r = i;
        while (r < n) {
            //for which rb is g(i, rb) == g(i, r)
            int lo = i, hi = n - 1, rb = n - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;

                if (st.prod(i, mid + 1) <= st.prod(i, r + 1))
                    lo = mid + 1, rb = mid;
                else
                    hi = mid - 1;
            }
            int x = st.prod(i, r + 1);
            x = x * x;

            //for rb
            //now find in this range [r; rb]
            //the number of elements such that my square
            //is greater than them
            auto it = lower_bound(
                pref.begin() + r + 1,
                pref.begin() + rb + 2,
                pref[i] + x
            );
            ans += it - (pref.begin() + r) - 1;
            r = rb + 1;
        }
    }
    cout << ans << nl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--) solve();
}